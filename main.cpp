#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main(){
    
    std::string parentDir;
    std::string folderName;

    std::cout<<"Enter the parent directory path: ";
    std::getline(std::cin, parentDir);

    std::cout<<"Enter the name of the folder to create: ";
    std::getline(std::cin, folderName);

    try{

        fs::path fullPath=fs::path(parentDir)/folderName;
        // create a directory
        if (fs::create_directory(fullPath)){
            std::cout<<"Folder '" << folderName << "' created successfully!" << std::endl;
        }else{
            std::cout<<"Folder '" << folderName << "' already exists." << std::endl;
        }
    }catch(const fs::filesystem_error& e){
        std::cerr<<"Error: " << e.what()<< std::endl;
    }

    return 0;
}