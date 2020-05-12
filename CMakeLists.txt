cmake_minimum_required(VERSION 3.16)
project(reading_manager)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Widgets REQUIRED)

add_executable(reading_manager main.cpp Book.cpp Book.h BookRepo.cpp BookRepo.h Controller.cpp Controller.h UserInterface.cpp UserInterface.h PersistenceEngine.cpp PersistenceEngine.h)

target_link_libraries(reading_manager Qt5::Widgets)