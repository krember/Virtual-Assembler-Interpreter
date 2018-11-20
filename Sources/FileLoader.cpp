//
// Created by Narek Hovhannisyan and/or Milena Mamyan on 10/14/18.
//

#include "../Headers/FileLoader.h"

const std::string FileLoader::CODE = ".code";

FileLoader::FileLoader() {}

StructuredFile FileLoader::load(std::string fileName) {
	std::ifstream codeFile(fileName);
	if (!codeFile.is_open()) {
		throw IOException("Could not open file with name : " + fileName);
	}
	std::string line;
	while (getline(codeFile, line)) {
		if (line[0] == '\n' || line[0] == '\0' || line[0] == '\n\r') {
			continue;
		}
		else if (line[0] == ' ' || line[0] == '\t') {
			line.erase(0, line.find_first_not_of(' \t\n\r') - 1);
		}
		line.erase(line.find_last_not_of(' \t\n\r') + 1);
		if (line.compare(CODE) != 0){
			throw IOException("Not an executable file");
		}
		else {
			break;
		}
	}

	StructuredFile structedFile;
	while (getline(codeFile, line)) {
		if (line[0] == '\n' || line[0] == '\0' || line[0] == '\n\r') {
			continue;
		}
		if (line[0] == ' ' || line[0] == '\t') {
			line.erase(0, line.find_first_not_of(' \t\n\r') - 1);
		}
		line.erase(line.find_last_not_of(' \t\n\r') + 1);

		if (!line.empty()) {
			structedFile.addOperation(line);
		}
	}

	return structedFile;
}
