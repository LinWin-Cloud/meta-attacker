#include <iostream>  
#include <experimental/filesystem>    
#include "meta_attacker.hpp"  
#include <fstream>  
#include <string>
#include <cstdlib>
#include <utility>
#include <unistd.h>
#include "filesystem"

using namespace std;
  
void PrintLogo(std::string logo_path) {
	std::cout << GetFileContent(logo_path) << std::endl;
	std::cout << " [version: 1.0]" << std::endl;
	std::cout << " Author: Linwin-Cloud: https://github.com/LinWin-Cloud/" << std::endl;
	std::cout << " [注意] 输入 help 查看命令行帮助; 输入 exit 退出" << std::endl;
	std::cout << " [Notice] Enter 'help' to show the command line help; Enter the command 'exit' to quit.\n" << endl;
}
void enter_attack_console(std::basic_string<char> payload) {
    if (payload == "death_ping") {
        auto* deathOfPing = new DeathOfPing();
        deathOfPing->Console();
        delete deathOfPing;
    }
    if (payload == "http_attack") {
        auto* httpAttack = new HttpAttack();
        httpAttack->Console();
        delete httpAttack;
    }
    if (payload == "tcp_flood") {
        auto* tcpFlood = new TcpFlood();
        tcpFlood->Console();
        delete tcpFlood;
    }
    else {
        return;
    }
}


void run_command(const std::string& command) {
	if (command == "exit") {
		exit(EXIT_SUCCESS);
	}
    if (command.rfind("cd ",0) == 0) {
        try {
            char* cd_path = const_cast<char *>(command.substr(3).c_str());
            //cout << cd_path << endl;
            if (chdir(cd_path) != 0) {
                std::cerr << "Failed to change working directory\n";
            }
        }catch (const std::runtime_error& e) {
            std::cerr << "[ERR] Your command error.\n";
        }
        return;
    }
    if (command.rfind("use ",0) == 0) {
        try {
            string use_payload = command.substr(4);
            string payload_array = get_module_list();
            bool find_payload = false;
            for (int i = 0; i < payload_array.length() ;i++) {
                //cout << payload_array[i] << " " << use_payload << "\n";
                if (payload_array[i]) {
                    find_payload = true;
                    break;
                }
            }
            //cout << find_payload << "\n" << endl;
            if (find_payload) {
                enter_attack_console(use_payload);
                return;
            }else {
                cerr << "[NOT FOUND ERROR] Can not find the Module: " << use_payload << "\n";
                return;
            }
        }catch (const std::runtime_error& e) {
            cerr << "[ERR] Your command error: use [payload name]\n";
            return;
        }
    }
    if (command == "help") {
        std::filesystem::path abs_path = std::filesystem::canonical(".");
        cout << GetFileContent(abs_path.string()+"/../config/help.md") << endl;
        return;
    }
    else {
		system(command.c_str());
        return;
	}
}

int main() {
    std::filesystem::path abs_path = std::filesystem::canonical(".");
	// Print the logo in the console.
	PrintLogo(abs_path.string() + "/../config/logo.txt");
 	while (true)  
 	{  
 		/* code */  
 		std::string command;
 		printf("Meta_Attacker$ ");
 		getline(std::cin , command);  
   		run_command(command);
	}  
   
 	return 0;  
}
