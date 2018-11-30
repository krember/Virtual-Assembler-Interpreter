//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include "../Headers/FileLoader.h"

FileLoader::FileLoader(Memory *_memory) : vMemory(_memory) {

}

void FileLoader::load(std::string fileName) {
    std::ifstream exe(fileName, std::ios::binary);
    if (!exe.is_open()) {
        throw IOException("Could not open file with name : " + fileName);
    }

    uint32_t address = 0;

    uint32_t symbolTableOffset;
    uint32_t dataSectionOffset;
    uint32_t codeSectionOffset;
    exe.read(reinterpret_cast<char *>(&symbolTableOffset), sizeof(symbolTableOffset));
    exe.read(reinterpret_cast<char *>(&dataSectionOffset), sizeof(dataSectionOffset));
    exe.read(reinterpret_cast<char *>(&codeSectionOffset), sizeof(codeSectionOffset));

    // TODO Chage exe file structure
    uint64_t command;
    while(exe >> command) {
        if(command == 0)
            break;
        vMemory->write<uint64_t>(address, command);
        address += 8;
    }
}





//const ObjectFile & FileLoader::readFile(std::string fileName) {
//	std::ifstream codeFile(fileName);
//	if (!codeFile.is_open()) {
//		throw IOException("Could not open file with name : " + fileName);
//	}
//	std::string line;
//	while (getline(codeFile, line)) {
//		if (line[0] == '\n' || line[0] == '\0' || line[0] == '\n\r') {
//			continue;
//		}
//		else if (line[0] == ' ' || line[0] == '\t') {
//			line.erase(0, line.find_first_not_of(' \t\n\r') - 1);
//		}
//		line.erase(line.find_last_not_of(' \t\n\r') + 1);
//		if (line.compare(CODE) != 0){
//			throw IOException("Not an executable file");
//		}
//		else {
//			break;
//		}
//	}
//
//	ObjectFile structedFile;
//	while (getline(codeFile, line)) {
//		if (line[0] == '\n' || line[0] == '\0' || line[0] == '\n\r') {
//			continue;
//		}
//		if (line[0] == ' ' || line[0] == '\t') {
//			line.erase(0, line.find_first_not_of(' \t\n\r') - 1);
//		}
//		line.erase(line.find_last_not_of(' \t\n\r') + 1);
//
//		if (!line.empty()) {
//			structedFile.addOperation(line);
//		}
//	}
//
//	return structedFile;
//}

