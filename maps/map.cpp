#include "map.h"

using json = nlohmann::json;

void foo()
{
    // Open the JSON file
    std::ifstream file("data/map.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
    }

    // Parse the JSON file
    json jsonData;
    file >> jsonData;

    // Access JSON data
    std::cout << "Parsed JSON: " << jsonData.dump(4) << std::endl;
}