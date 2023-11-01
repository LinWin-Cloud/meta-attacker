#include <iostream>  
#include <experimental/filesystem>    
#include "meta_attacker.hpp"  
#include <fstream>  
#include <string>  
#include <filesystem>
#include <cstdlib>

using namespace std;  

std::string logo = "";  
  
void PrintLogo(std::string logo_path) {
	std::cout << GetFileContent(logo_path) << std::endl;
	std::cout << " [version: 1.0]" << std::endl;
	std::cout << " Author: Linwin-Cloud: https://github.com/LinWin-Cloud/" << std::endl;
	std::cout << " [注意] 输入 help 查看命令行帮助; 输入 exit 退出" << std::endl;
	std::cout << " [Notice] Enter 'help' to show the command line help; Enter the command 'exit' to quit.\n" << endl;
}

void run_command(std::string command) {
	if (command.compare("exit") == 0) {
		exit(EXIT_SUCCESS);
	}else {
		system(command.c_str());
	}
}

int main() {  
	std::filesystem::path abs_path = std::filesystem::canonical(".");
	// Print the logo in the console.
	PrintLogo(abs_path.string() + "/../config/logo.txt");
 	while (true)  
 	{  
 		/* code */  
 		std::string command = "";  
 		printf("Meta_Attacker$ ");
 		getline(std::cin , command);  
   		run_command(command);
	}  
   
 	return 0;  
}
