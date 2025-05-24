#include "download.h"


namespace download {



   

    //get path
    std::string GetCurrentDirectoryPath() {
        char buffer[MAX_PATH] = { 0 };
        GetCurrentDirectoryA(MAX_PATH, buffer);
        return std::string(buffer);
    }

    //download file into dir.
    // BOOL so ez error handling
    bool DownloadFileToCurrentDir() {
        //get current dir
        std::string currentDir = GetCurrentDirectoryPath();

        //put ur url in the "" and it will auto download into the same dir.
        const std::string url = "";

        //choose the name of ur file here
        std::string fileName = "v.sys";

        //add the filename to the current path \\ to match windows dir syntax.
        std::string fullPath = currentDir + "\\" + fileName;

        //download
        HRESULT hr = URLDownloadToFileA(
            NULL,
            url.c_str(),
            fullPath.c_str(),
            0,
            NULL
        );

        if (hr != S_OK) { 
            return false;
        }

        return true;
    }

}