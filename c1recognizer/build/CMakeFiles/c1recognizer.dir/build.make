# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cyh/Desktop/c1recognizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cyh/Desktop/c1recognizer/build

# Include any dependencies generated for this target.
include CMakeFiles/c1recognizer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c1recognizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c1recognizer.dir/flags.make

CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o: ../src/error_listener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o -c /home/cyh/Desktop/c1recognizer/src/error_listener.cpp

CMakeFiles/c1recognizer.dir/src/error_listener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/src/error_listener.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyh/Desktop/c1recognizer/src/error_listener.cpp > CMakeFiles/c1recognizer.dir/src/error_listener.cpp.i

CMakeFiles/c1recognizer.dir/src/error_listener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/src/error_listener.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyh/Desktop/c1recognizer/src/error_listener.cpp -o CMakeFiles/c1recognizer.dir/src/error_listener.cpp.s

CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o.requires

CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o.provides: CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o.provides

CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o


CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o: ../src/error_reporter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o -c /home/cyh/Desktop/c1recognizer/src/error_reporter.cpp

CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyh/Desktop/c1recognizer/src/error_reporter.cpp > CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.i

CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyh/Desktop/c1recognizer/src/error_reporter.cpp -o CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.s

CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o.requires

CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o.provides: CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o.provides

CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o


CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o: ../src/syntax_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o -c /home/cyh/Desktop/c1recognizer/src/syntax_tree.cpp

CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyh/Desktop/c1recognizer/src/syntax_tree.cpp > CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.i

CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyh/Desktop/c1recognizer/src/syntax_tree.cpp -o CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.s

CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o.requires

CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o.provides: CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o.provides

CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o


CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o: ../src/syntax_tree_builder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o -c /home/cyh/Desktop/c1recognizer/src/syntax_tree_builder.cpp

CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyh/Desktop/c1recognizer/src/syntax_tree_builder.cpp > CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.i

CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyh/Desktop/c1recognizer/src/syntax_tree_builder.cpp -o CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.s

CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o.requires

CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o.provides: CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o.provides

CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o


CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o: ../src/recognizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o -c /home/cyh/Desktop/c1recognizer/src/recognizer.cpp

CMakeFiles/c1recognizer.dir/src/recognizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/src/recognizer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyh/Desktop/c1recognizer/src/recognizer.cpp > CMakeFiles/c1recognizer.dir/src/recognizer.cpp.i

CMakeFiles/c1recognizer.dir/src/recognizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/src/recognizer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyh/Desktop/c1recognizer/src/recognizer.cpp -o CMakeFiles/c1recognizer.dir/src/recognizer.cpp.s

CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o.requires

CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o.provides: CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o.provides

CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o


CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o: antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o -c /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp > CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.i

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.s

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o.requires

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o.provides: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o.provides

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o


CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o: antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o -c /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp > CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.i

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.s

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o.requires

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o.provides: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o.provides

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o


CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o: antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o -c /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp > CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.i

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.s

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o.requires

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o.provides: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o.provides

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o


CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o: antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o -c /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp > CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.i

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.s

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o.requires

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o.provides: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o.provides

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o


CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o: antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o -c /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp > CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.i

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.s

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o.requires

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o.provides: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o.provides

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o


CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o: CMakeFiles/c1recognizer.dir/flags.make
CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o: antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o -c /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp > CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.i

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /home/cyh/Desktop/c1recognizer/build/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp -o CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.s

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o.requires:

.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o.requires

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o.provides: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o.requires
	$(MAKE) -f CMakeFiles/c1recognizer.dir/build.make CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o.provides.build
.PHONY : CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o.provides

CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o.provides.build: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o


# Object files for target c1recognizer
c1recognizer_OBJECTS = \
"CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o" \
"CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o" \
"CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o" \
"CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o" \
"CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o" \
"CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o" \
"CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o" \
"CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o" \
"CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o" \
"CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o" \
"CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o"

# External object files for target c1recognizer
c1recognizer_EXTERNAL_OBJECTS =

libc1recognizer.a: CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o
libc1recognizer.a: CMakeFiles/c1recognizer.dir/build.make
libc1recognizer.a: CMakeFiles/c1recognizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cyh/Desktop/c1recognizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX static library libc1recognizer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/c1recognizer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c1recognizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c1recognizer.dir/build: libc1recognizer.a

.PHONY : CMakeFiles/c1recognizer.dir/build

CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/src/error_listener.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/src/error_reporter.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/src/syntax_tree.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/src/syntax_tree_builder.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/src/recognizer.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Lexer.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1Parser.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseListener.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserBaseVisitor.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserListener.cpp.o.requires
CMakeFiles/c1recognizer.dir/requires: CMakeFiles/c1recognizer.dir/antlr4cpp_generated_src/c1_recognizer/C1ParserVisitor.cpp.o.requires

.PHONY : CMakeFiles/c1recognizer.dir/requires

CMakeFiles/c1recognizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c1recognizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c1recognizer.dir/clean

CMakeFiles/c1recognizer.dir/depend:
	cd /home/cyh/Desktop/c1recognizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cyh/Desktop/c1recognizer /home/cyh/Desktop/c1recognizer /home/cyh/Desktop/c1recognizer/build /home/cyh/Desktop/c1recognizer/build /home/cyh/Desktop/c1recognizer/build/CMakeFiles/c1recognizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c1recognizer.dir/depend

