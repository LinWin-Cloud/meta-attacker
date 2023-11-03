#include <string>
#include <iostream>
using namespace std;

void PrintList() {
    printf("hello world");
}

std::string* get_module_list() {
    static std::string array[4];
    array[0] = "death_ping";
    array[1] = "http_attack";
    array[2] = "tcp_flood";
    array[3] = "network_resource_attack";

    return array;
}