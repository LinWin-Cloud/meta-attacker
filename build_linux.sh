find ./src/ | grep .cpp > buildcode_list.txt
cd src/
g++ -std=c++17 main_application.cpp -o ../output/meta_attacker -lpthread

