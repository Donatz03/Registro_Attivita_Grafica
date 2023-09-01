cmake_minimum_required(VERSION 3.26)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(TEST_SOURCE_FILES runAllTests.cpp registro_test.cpp)

add_executable(runAllTests ../Attivita.cpp ../Registro.cpp ${TEST_SOURCE_FILES})

target_link_libraries(runAllTests gtest gtest_main core Qt6::Core Qt6::Gui Qt6::Widgets)