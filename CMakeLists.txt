cmake_minimum_required(VERSION 3.16)
project(reading_manager)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)

add_executable(reading_manager main.cpp Book.cpp Book.h BookRepo.cpp BookRepo.h Controller.cpp Controller.h UserInterface.cpp UserInterface.h PersistenceEngine.cpp PersistenceEngine.h "Qt UI/MainWindow.cpp" "Qt UI/MainWindow.h" "Qt UI/AdminWindow.cpp" "Qt UI/AdminWindow.h" "Qt UI/UserWindow.cpp" "Qt UI/UserWindow.h")

target_link_libraries(reading_manager Qt5::Widgets)