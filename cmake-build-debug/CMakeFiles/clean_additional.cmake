# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Registro_Attivita_Grafica_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Registro_Attivita_Grafica_autogen.dir/ParseCache.txt"
  "Registro_Attivita_Grafica_autogen"
  )
endif()
