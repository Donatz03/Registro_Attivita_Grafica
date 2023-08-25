cmake_minimum_required(VERSION 3.26)
project(Registro_Attivita_Grafica)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Registro_Attivita_Grafica main.cpp
        Attivita.cpp
        Attivita.h
        Registro.cpp
        Registro.h
        InterfacciaQt.cpp
        InterfacciaQt.h)
target_link_libraries(Registro_Attivita_Grafica
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

