// author: connor kasarda
// date added: 12/19/2023
// description: handles access to openai api

#include "prompter.h"
#include <iostream>
#include <curl/curl.h>

namespace dragonbreath
{
    Prompter::Prompter
    (
        const char* openaiAPIKey,
        const char* openaiAPIURL
    )
        : openaiAPIKey(openaiAPIKey)
        , openaiAPIURL(openaiAPIURL)
        , curl(curl_easy_init())
    {
        if (!this->curl)
        {
            std::cerr << "CURL initialization failed!" << std::endl;
        }
    }
    Prompter::~Prompter()
    {
        if (this->curl)
        {
            curl_easy_cleanup(this->curl);
        }
    }
    size_t Prompter::WriteCallback
    (
        void* contents,
        size_t size,
        size_t nmemb,
        std::string* output
    )
    {
        size_t totalSize = size * nmemb;
        output->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }
    void Prompter::SetPrompt(const std::string& prompt)
    {
        this->prompt = prompt;
    }
    void Prompter::Prompt()
    {
        if (this->curl)
        {
            struct curl_slist* headers = nullptr;
            headers = curl_slist_append(headers, ("Authorization: Bearer " + std::string(openaiAPIKey)).c_str());
            headers = curl_slist_append(headers, "Content-Type: application/json");
            std::string requestData = R"({"prompt": ")" + prompt + R"("})";
            curl_easy_setopt(curl, CURLOPT_URL, this->openaiAPIURL);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestData);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->response);
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            } else {
                std::cout << "Response from OpenAI API:\n" << this->response << std::endl;
            }
        }
    }
    std::string Prompter::GetResponse() const
    {
        return this->response;
    }
}
