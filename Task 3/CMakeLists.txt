cmake_minimum_required(VERSION 3.9)
project(juxrvhtg)

set(CMAKE_CXX_STANDARD 17)

add_executable(juxrvhtg "source files/main.cpp" "headers/SkaiciavimoBudai.h" "source files/SkaiciavimoBudai.cpp" "source files/IvestiesMetodai.cpp" "headers/IvestiesMetodai.h" "source files/DarbasFailais.cpp" "headers/DarbasFailais.h" "source files/Profiling.cpp" "headers/Profiling.h")