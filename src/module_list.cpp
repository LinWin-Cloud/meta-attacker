#include <string>
#include <iostream>
using namespace std;

void PrintList() {
    printf("hello world");
}

basic_string<char> get_module_list() {
    static std::string array[4];
    array[0] = "death_ping";
    array[1] = "http_attack";
    array[2] = "tcp_flood";
    array[3] = "resource_attack";

    return reinterpret_cast<basic_string<char> &&>(array);
}