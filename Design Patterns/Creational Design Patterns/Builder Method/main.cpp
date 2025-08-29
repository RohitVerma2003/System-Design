#include <iostream>
#include "Builder.h"
using namespace std;

int main()
{
    HTTPRequest req1 = HTTPRequest::Builder("https://google.com/").build();
    req1.print();
    cout << endl;

    HTTPRequest req2 = HTTPRequest::Builder("https://linkedin.com").set_body("/feed").set_header("X-API-Key", "secret").set_method("POST").set_query_params("env", "prod").set_timeout(1000).build();
    req2.print();

    return -1;
}