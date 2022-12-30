#include "json.h"

using namespace shotacon::json;

int main() {
    Json j;
    j[0] = "123";
    j[1] = 89.9;
    j[3] = true;
    Json j1;
    j1["sa"] = "sa";
    j[4].shallow_copy(j1);
    std::cout<<j.get()<<std::endl;
    j.remove(4);
    std::cout<<j.get()<<std::endl;
    std::cout<<j1.get()<<std::endl;
    return 0;
}
