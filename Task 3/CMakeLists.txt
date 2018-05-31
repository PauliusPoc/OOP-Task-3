cmake_minimum_required(VERSION 3.9)
project(Task_3)

set(CMAKE_CXX_STANDARD 17)


option(Test "Do tests" OFF)
if (Test)
add_subdirectory(tests/googletest-master)
include_directories(tests/googletest-master/googletest/include)
include_directories(tests/googletest-master/googlemock/include)
add_executable(Task_3 "source files/mainTest.cpp" "headers/SkaiciavimoBudai.h" "source files/SkaiciavimoBudai.cpp" "source files/IvestiesMetodai.cpp" "headers/IvestiesMetodai.h" "source files/DarbasFailais.cpp" "headers/DarbasFailais.h" "source files/Profiling.cpp" "headers/Profiling.h" "source files/Studentas.cpp" "headers/Studentas.h")
target_link_libraries(Task_3 gtest gtest_main)
else()
add_executable(Task_3 "source files/main.cpp" "headers/SkaiciavimoBudai.h" "source files/SkaiciavimoBudai.cpp" "source files/IvestiesMetodai.cpp" "headers/IvestiesMetodai.h" "source files/DarbasFailais.cpp" "headers/DarbasFailais.h" "source files/Profiling.cpp" "headers/Profiling.h" "source files/Studentas.cpp" "headers/Studentas.h")
endif(Test)
unset(Test CACHE)