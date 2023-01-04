#include "json.h"
#include "fstream"
using namespace shotacon::json;

int main() {
    std::ifstream fin("../test.json");
    std::stringstream ss;
    ss << fin.rdbuf();
    Json j;
    j.parser(ss.str());
    std::cout<<j.get();
    return 0;
}
