find ./src/ | grep .cpp > buildcode_list.txt
cd src/
g++ main_application.cpp -o ../output/meta_attacker

