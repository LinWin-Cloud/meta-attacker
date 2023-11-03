#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

std::string GetFileContent(const std::string& path) {
	std::ifstream file(path);
	if (file.is_open()) {
		std::string line;
		std::stringstream ss;
		while (std::getline(file , line)) {
			ss << line;
			ss << "\n";
		}
		file.close();
		return ss.str();
	}else {
		std::cerr << "Can not open this file: " << path << std::endl;
		return nullptr;
	}
}

std::string input(const char *text) {
    std::string get_input;
    printf("%s", text);
    getline(std::cin , get_input);
    return get_input;
}