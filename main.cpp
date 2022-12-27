#include <iostream>
#include "json.h"

using namespace shotacon::json;

int main() {
    Json j = false;
    Json j1 = 1;
    Json j2 = true;
    Json j3 = 0.8;
    Json j4 = "123";
    Json arr;
    arr[0] = false;
    arr[1] = 2.0;
    arr[2] = 3.3;
    //arr[3] = "不是我";
    //arr.append("谁知道");
    bool a = arr[0];
    double b = arr[1];
    std::string s = arr[2];
    std::string c = arr[3];
    //std::cout<<(a == false)<<b<<s<<c;
    return 0;
}
