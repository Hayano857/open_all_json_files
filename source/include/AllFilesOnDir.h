#pragma once

#include <filesystem>
#include <vector>
#include <string>


class AllFilesOnDir
{
public:
	AllFilesOnDir(std::string addrA);
	std::vector<std::filesystem::path> GetAllAddrs();
private:
	std::string addrA;
	int countA;

};
