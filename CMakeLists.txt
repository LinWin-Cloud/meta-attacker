cmake_minimum_required(VERSION 3.26)
project(meta_attacker)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(meta_attacker
        src/base_function.cpp
        src/main_application.cpp
        src/meta_attacker.hpp
        src/module_list.cpp
        src/death_ping.cpp
        src/HttpAttack.cpp
        src/TcpFlood.cpp)
