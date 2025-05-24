#pragma once
#pragma once

#include <windows.h>
#include <urlmon.h>
#include <string>
#include <iostream>
#include <shlwapi.h> 

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "shlwapi.lib")


namespace download
{
	std::string GetCurrentDirectoryPath();
	bool DownloadFileToCurrentDir();
}

