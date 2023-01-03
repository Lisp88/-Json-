#include "json.h"
#include "fstream"
using namespace shotacon::json;

int main() {
    std::ifstream fin("../test.json");
    std::stringstream ss;
    ss << fin.rdbuf();
    std::string s = ss.str();
    Json j;
    j.parser(s);
    std::cout << j.get();
    return 0;
}
