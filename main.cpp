#include "maps/map.h"

using namespace std;
using json = nlohmann::json;

int main()
{
    hexagonmap map{};
    map.printMap();
    return 0;
}