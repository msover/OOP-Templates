cmake_minimum_required(VERSION 3.16)
project(Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Test
    main.cpp
    Domain/Item.h
    Domain/Item.cpp
        Repo/Repo.h
        Repo/Repo.cpp
        Service/Service.h
        Service/Service.cpp
    GUI/MainWindow.h
    GUI/MainWindow.cpp
    GUI/MainWindow.ui
    GUI/TableModel.h
    GUI/TableModel.cpp
)

target_link_libraries(Test PRIVATE Qt6::Widgets)
