#include"../http.h"
int main(int argc, char const *argv[])
{
    http a="GET /index.html HTTP/1.1\nHost: www.example.com\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:91.0) Gecko/20100101 Firefox/91.0\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\nAccept-Encoding: gzip, deflate\nConnection: keep-alive\n\nhello";
    auto Req = Http::decodeReq(a);
    http b="HTTP/1.1 200 OK\n Date: Wed, 18 Apr 2024 12:00:00 GMT\nServer: Apache/2.4.1 (Unix)\nLast-Modified: Wed, 18 Apr 2024 11:00:00 GMT\nContent-Length: 12345\nContent-Type: text/html; charset=UTF-8\n\n<!DOCTYPE html><html><head><title>Example Page</title></head><body<h1>Hello, World!</h1><!-- The rest of the HTML content --></body></html>";
    auto Res =  Http::decodeRes(b);
    Http::encode(Req);
    Http::encode(Res);
    return 0;
}
