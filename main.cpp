#include <iostream>
#include "json.h"

using namespace shotacon::json;

int main() {
    Json j = false;
    Json j1 = 1;
    Json j2 = true;
    Json j3 = 0.8;
    Json j4 = "123";
    int a = j1;
    bool b = j2;
    double c = j3;
    const std::string & d = j4;
    const char* e = j4;
    std::cout<<e;
    return 0;
}
