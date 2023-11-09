
#ifndef META_ATTACKER_HPP
#define META_ATTACKER_HPP
#include <string>
#include "iostream"

void PrintList(); 			        // Print all the information in the console.
std::string GetFileContent();		// Get the file's text content.
std::basic_string<char> get_module_list();     // Get all the payload in this software.
std::string input();                // Get the user's key input

#include "module_list.cpp"
#include "base_function.cpp"
#include "death_ping.cpp"
#include "HttpAttack.cpp"
#include "TcpFlood.cpp"
#include "NetworkResourceAttack.cpp"
#include "show_information.cpp"


#endif
