#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include "AllFilesOnDir.h"
#include <nlohmann/json.hpp>

int main()
{
    std::string addr = "C:\\Users\\taka_\\Test";
    AllFilesOnDir allFiles(addr);
    std::vector<std::filesystem::path> filePaths = allFiles.GetAllAddrs();
    for (size_t i = 0; i < filePaths.size(); i++)
    {
        std::ifstream jsonFileStream(filePaths[i].string());
        if (!jsonFileStream.is_open())
        {
            std::cerr << "Failed to open file: " << filePaths[i].string() << std::endl;
            continue;
        }
        nlohmann::json jsonData = nlohmann::json::parse(jsonFileStream);
        for (size_t j = 0; j < jsonData.size(); j++)
        {
            std::cout << "Word: " << jsonData[j]["word"] << std::endl;
            std::cout << "Definition: " << jsonData[j]["definitionA"] << std::endl;
            std::cout << std::endl;
        }
    }
    return 0;
}