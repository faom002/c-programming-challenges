#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

// Callback function to handle response data
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    char *buffer = (char *)userp;
    
    // Copy the received data to the buffer
    strncat(buffer, (char *)contents, total_size);
    
    return total_size;
}

int main(void) {
    // Initialize libcurl
    CURL *hnd = curl_easy_init();

    // Set the custom request method to "GET"
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");

    // Set the URL you want to request
    curl_easy_setopt(hnd, CURLOPT_URL, "https://catfact.ninja/fact");

    // Create a buffer to store the response data
    char buffer[1024];
    buffer[0] = '\0'; // Initialize buffer with an empty string
    char egyptCat[] = "Cats with long, lean bodies are more likely to be outgoing, and more protective and vocal than those with a stocky build.";
    // Set the write callback function to handle response data
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &buffer);

    // Perform the request
    CURLcode ret = curl_easy_perform(hnd);

    // Check if the request was successful
    if (ret != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(ret));
    } else {
        // Extract a portion of the response
        char* start = strstr(buffer, "fact\":\"") + 7; // Find the start of the fact
        char* end = strchr(start, '"'); // Find the end of the fact
        if (start != NULL && end != NULL) {

            if (strcmp(start, egyptCat) == 0)
            {
                // Extract and print the fact
            *end = '\0'; // Null-terminate the fact
            printf("Cat Fact: %s\n", start);
            }

            
        } else {
            printf("Fact not found\n");
        }
    }

    // Clean up libcurl resources
    curl_easy_cleanup(hnd);

    return 0;
}
