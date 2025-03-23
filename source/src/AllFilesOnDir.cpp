#pragma once

#include "AllFilesOnDir.h"

AllFilesOnDir::AllFilesOnDir(std::string addr)
{
	countA = 0;
	addrA = addr;
}


std::vector<std::filesystem::path> AllFilesOnDir::GetAllAddrs()
{
	std::vector<std::filesystem::path> filePaths;
	for (const auto& entry : std::filesystem::directory_iterator(addrA))
	{
		filePaths.push_back(entry.path());
		countA++;
	}

	return filePaths;
}
