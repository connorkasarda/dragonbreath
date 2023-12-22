#ifndef PROMPTER_H
#define PROMPTER_H

#include <string>
#include <curl/curl.h>

namespace dragonbreath
{
    class Prompter
    {
    public:
        Prompter
        (
            const char* openaiAPIKey,
            const char* openaiAPIURL
        );
        ~Prompter();
        void SetPrompt(const std::string& prompt);
        void Prompt();
        std::string GetResponse() const;
    private:
        static size_t WriteCallback
        (
            void* contents,
            size_t size,
            size_t nmemb,
            std::string* output
        );
        const char* openaiAPIKey;
        const char* openaiAPIURL;
        std::string prompt;
        std::string response;
        CURL* curl;
    };
}

#endif
