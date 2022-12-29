#include <iostream>
#include "json.h"

using namespace shotacon::json;

int main() {
    Json j;
    j[0] = "123";
    j[1] = 89.9;
    j[3] = false;
    j[4].deep_copy(j);
    std::cout<<j.get();

    return 0;
}
