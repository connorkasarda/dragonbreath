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
    void Prompter::SetPrompt(const std::string& prompt)
    {
        this->prompt = prompt;
    }
    void Prompter::Prompt()
    {
        if (this->curl)
        {
            // if curl init success...
        }
    }
    std::string Prompter::GetResponse() const
    {
        return this->response;
    }
}
