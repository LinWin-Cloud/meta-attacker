#include <iostream>  
#include <experimental/filesystem>    
#include "meta_attacker.hpp"  
#include <fstream>  
#include <string>  
using namespace std;  
namespace fs = std::experimental::filesystem;  
  
std::string logo = "";  
std::string AbsPath;  
  
void PrintLogo() {  
 std::ifstream file;
	file.open(AbsPath+"/../config/logo.txt");  
 if (!file) {  
 std::cerr << "Can not open this file." << std::endl;  
 return;  
 }  
 std::string i;  
 while(std::getline(file, i )) {  
 std::cout << i << std::endl;  
 }  
 file.close();  
}  
  
int main() {  
 AbsPath = fs::current_path().string();   
 PrintLogo(); // Print the logo in the console.  
 while (true)  
 {  
 /* code */  
 std::string command = "";  
 std::cout << "Meta_Attacker$ " << std::endl;  
 getline(std::cin , command);  
   
 }  
   
 return 0;  
}
