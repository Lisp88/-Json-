#include <iostream>
#include "json.h"

using namespace shotacon::json;

int main() {
    Json j1 = 2;
    Json j2 = 8.9;
    Json j3 = false;
    Json j4 = "不到";

    Json arr;
    arr[1] = 7.9;
    arr[2] = true;
    arr[3] = "ada";
    arr.append(5);


    std::cout<<arr.get();
    return 0;
}
