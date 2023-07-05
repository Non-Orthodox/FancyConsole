cmake_minimum_required(VERSION 3.5)

project(Fancy_Console VERSION 0.01)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
#set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

include_directories(FancyConsole)
add_subdirectory(tests)
