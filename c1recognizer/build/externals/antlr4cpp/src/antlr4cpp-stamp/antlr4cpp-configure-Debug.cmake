

set(command "/usr/bin/cmake;-DCMAKE_BUILD_TYPE=Release;-DANTLR4CPP_JAR_LOCATION=/home/cyh/antlr/antlr-4.7-complete.jar;-DBUILD_SHARED_LIBS=ON;-BUILD_TESTS=OFF;-DCMAKE_INSTALL_PREFIX:PATH=/home/cyh/Desktop/c1recognizer/build/externals/antlr4cpp;-DCMAKE_SOURCE_DIR:PATH=/home/cyh/Desktop/c1recognizer/build/externals/antlr4cpp/src/antlr4cpp/runtime/Cpp;/home/cyh/Desktop/c1recognizer/build/externals/antlr4cpp/src/antlr4cpp/runtime/Cpp")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/cyh/Desktop/c1recognizer/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-out.log"
  ERROR_FILE "/home/cyh/Desktop/c1recognizer/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/cyh/Desktop/c1recognizer/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "antlr4cpp configure command succeeded.  See also /home/cyh/Desktop/c1recognizer/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-*.log")
  message(STATUS "${msg}")
endif()
