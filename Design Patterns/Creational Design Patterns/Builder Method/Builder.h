#include <iostream>
#include <map>
#include <string>
using namespace std;

class HTTPRequest
{
private:
    string url;

    string method;
    map<string, string> headers;
    map<string, string> query_params;
    string body;
    int timeout;

    HTTPRequest(string &url, string &method, map<string, string> &headers, map<string, string> &query_params, string &body, int &timeout) : url(url), method(method), headers(headers), query_params(query_params), body(body), timeout(timeout) {}

public:
    void print(){
        cout<<"URL "<<this->url<<endl;
        cout<<"Method "<<this->method<<endl;
        cout<<"Headers size "<<this->headers.size()<<endl;
        cout<<"Query size "<<this->query_params.size()<<endl;
        cout<<"Body "<<this->body<<endl;
        cout<<"Timeout "<<this->timeout<<endl;
    }

    class Builder{
    private:
        string url;

        string method = "GET";
        map<string, string> headers;
        map<string, string> query_params;
        string body;
        int timeout = 30000;
    
    public:
        explicit Builder(const string& url) : url(url){}

        Builder& set_method(const string& method){
            this->method = method;
            return *this;
        }

        Builder& set_header(const string& key , const string& value){
            this->headers[key] = value;
            return *this;
        }

        Builder& set_query_params(const string& key , const string& value){
            this->query_params[key] = value;
            return *this;
        }

        Builder& set_body(const string& body){
            this->body = body;
            return *this;
        }

        Builder& set_timeout(int timeout){
            this->timeout = timeout;
            return *this;
        }

        HTTPRequest build(){
            return HTTPRequest(url , method , headers , query_params , body , timeout);
        }
    };
};