#include "map.h"

using json = nlohmann::json;

hexagonmap::hexagonmap()
{
    std::ifstream file("data/map.json");
    if (!file.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
    }

    // Parse the JSON file
    json jsonData;
    file >> jsonData;

    radius = int(jsonData["map_radius"]);
    cells.resize(radius * 2 + 1);
    for (int i = 0; i < cells.size(); i++)
    {
        if (i < radius + 1) cells[i].resize(radius + 1 + i, nullptr);
        else cells[i].resize(cells[i - 1].size() - 1, nullptr);
    }
    for (auto i: jsonData["cells"].items())
    {
        int q = i.value()["q"];
        int r = i.value()["r"];
        int s = i.value()["s"];
        auto valueField = i.value()["value"];
        valueField = to_string(valueField);
        char value;
        if (std::string(valueField).length() == 3) value = std::string(valueField)[1];
        else value = std::string(valueField)[0];
        cells[r + radius][q - std::max(-radius, -(r + radius))] = cellFactory::createCell(q, r, s, value);
    }
    for (int i = 0; i < cells.size(); i++)
    {
        for (int j = 0; j < cells[i].size(); j++)
        {
            if (!cells[i][j])
            {
                int r = i + radius, q = j + std::max(-radius, -(r + radius)), s = -q - r;
                cells[i][j] = cellFactory::createCell(q, r, s, 'x');
            }
        }
    }
    std::cout << "Map loaded successfully." << std::endl;
}

void hexagonmap::printMap()
{
    for (int i = 0; i < cells.size(); i++)
    {
        std::cout << std::string(2 * radius + 1 - cells[i].size(), ' ');
        for (int j = 0; j < cells[i].size(); j++)
        {
            if (cells[i][j] != nullptr)
            {
                std::cout << cells[i][j]->getType() << " ";
            }
            else
            {
                std::cout << "x ";
            }
        }
        std::cout << std::endl;
    }
}
