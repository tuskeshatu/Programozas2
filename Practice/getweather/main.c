#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char const *argv[])
{
    printf("fasz");

    CURL *curl;
    CURLcode result;

    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.openweathermap.org/data/2.5/weather?lat=47.4729606&lon=19.0521963&appid={API_key}");

    curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    return 0;
}