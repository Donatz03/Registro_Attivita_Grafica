# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Registro_Attivita_Grafica_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Registro_Attivita_Grafica_autogen.dir/ParseCache.txt"
  "CMakeFiles/core_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/core_autogen.dir/ParseCache.txt"
  "Registro_Attivita_Grafica_autogen"
  "core_autogen"
  "test/CMakeFiles/runAllTests_autogen.dir/AutogenUsed.txt"
  "test/CMakeFiles/runAllTests_autogen.dir/ParseCache.txt"
  "test/lib/googletest/CMakeFiles/gtest_autogen.dir/AutogenUsed.txt"
  "test/lib/googletest/CMakeFiles/gtest_autogen.dir/ParseCache.txt"
  "test/lib/googletest/CMakeFiles/gtest_main_autogen.dir/AutogenUsed.txt"
  "test/lib/googletest/CMakeFiles/gtest_main_autogen.dir/ParseCache.txt"
  "test/lib/googletest/gtest_autogen"
  "test/lib/googletest/gtest_main_autogen"
  "test/runAllTests_autogen"
  )
endif()
