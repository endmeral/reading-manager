# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ovidiupopa/CLionProjects/reading-manager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/reading_manager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reading_manager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reading_manager.dir/flags.make

CMakeFiles/reading_manager.dir/main.cpp.o: CMakeFiles/reading_manager.dir/flags.make
CMakeFiles/reading_manager.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reading_manager.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reading_manager.dir/main.cpp.o -c /Users/ovidiupopa/CLionProjects/reading-manager/main.cpp

CMakeFiles/reading_manager.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reading_manager.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ovidiupopa/CLionProjects/reading-manager/main.cpp > CMakeFiles/reading_manager.dir/main.cpp.i

CMakeFiles/reading_manager.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reading_manager.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ovidiupopa/CLionProjects/reading-manager/main.cpp -o CMakeFiles/reading_manager.dir/main.cpp.s

CMakeFiles/reading_manager.dir/Book.cpp.o: CMakeFiles/reading_manager.dir/flags.make
CMakeFiles/reading_manager.dir/Book.cpp.o: ../Book.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/reading_manager.dir/Book.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reading_manager.dir/Book.cpp.o -c /Users/ovidiupopa/CLionProjects/reading-manager/Book.cpp

CMakeFiles/reading_manager.dir/Book.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reading_manager.dir/Book.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ovidiupopa/CLionProjects/reading-manager/Book.cpp > CMakeFiles/reading_manager.dir/Book.cpp.i

CMakeFiles/reading_manager.dir/Book.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reading_manager.dir/Book.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ovidiupopa/CLionProjects/reading-manager/Book.cpp -o CMakeFiles/reading_manager.dir/Book.cpp.s

CMakeFiles/reading_manager.dir/BookRepo.cpp.o: CMakeFiles/reading_manager.dir/flags.make
CMakeFiles/reading_manager.dir/BookRepo.cpp.o: ../BookRepo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/reading_manager.dir/BookRepo.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reading_manager.dir/BookRepo.cpp.o -c /Users/ovidiupopa/CLionProjects/reading-manager/BookRepo.cpp

CMakeFiles/reading_manager.dir/BookRepo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reading_manager.dir/BookRepo.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ovidiupopa/CLionProjects/reading-manager/BookRepo.cpp > CMakeFiles/reading_manager.dir/BookRepo.cpp.i

CMakeFiles/reading_manager.dir/BookRepo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reading_manager.dir/BookRepo.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ovidiupopa/CLionProjects/reading-manager/BookRepo.cpp -o CMakeFiles/reading_manager.dir/BookRepo.cpp.s

CMakeFiles/reading_manager.dir/Controller.cpp.o: CMakeFiles/reading_manager.dir/flags.make
CMakeFiles/reading_manager.dir/Controller.cpp.o: ../Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/reading_manager.dir/Controller.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reading_manager.dir/Controller.cpp.o -c /Users/ovidiupopa/CLionProjects/reading-manager/Controller.cpp

CMakeFiles/reading_manager.dir/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reading_manager.dir/Controller.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ovidiupopa/CLionProjects/reading-manager/Controller.cpp > CMakeFiles/reading_manager.dir/Controller.cpp.i

CMakeFiles/reading_manager.dir/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reading_manager.dir/Controller.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ovidiupopa/CLionProjects/reading-manager/Controller.cpp -o CMakeFiles/reading_manager.dir/Controller.cpp.s

CMakeFiles/reading_manager.dir/UserInterface.cpp.o: CMakeFiles/reading_manager.dir/flags.make
CMakeFiles/reading_manager.dir/UserInterface.cpp.o: ../UserInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/reading_manager.dir/UserInterface.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reading_manager.dir/UserInterface.cpp.o -c /Users/ovidiupopa/CLionProjects/reading-manager/UserInterface.cpp

CMakeFiles/reading_manager.dir/UserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reading_manager.dir/UserInterface.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ovidiupopa/CLionProjects/reading-manager/UserInterface.cpp > CMakeFiles/reading_manager.dir/UserInterface.cpp.i

CMakeFiles/reading_manager.dir/UserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reading_manager.dir/UserInterface.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ovidiupopa/CLionProjects/reading-manager/UserInterface.cpp -o CMakeFiles/reading_manager.dir/UserInterface.cpp.s

CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.o: CMakeFiles/reading_manager.dir/flags.make
CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.o: ../PersistenceEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.o -c /Users/ovidiupopa/CLionProjects/reading-manager/PersistenceEngine.cpp

CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ovidiupopa/CLionProjects/reading-manager/PersistenceEngine.cpp > CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.i

CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ovidiupopa/CLionProjects/reading-manager/PersistenceEngine.cpp -o CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.s

# Object files for target reading_manager
reading_manager_OBJECTS = \
"CMakeFiles/reading_manager.dir/main.cpp.o" \
"CMakeFiles/reading_manager.dir/Book.cpp.o" \
"CMakeFiles/reading_manager.dir/BookRepo.cpp.o" \
"CMakeFiles/reading_manager.dir/Controller.cpp.o" \
"CMakeFiles/reading_manager.dir/UserInterface.cpp.o" \
"CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.o"

# External object files for target reading_manager
reading_manager_EXTERNAL_OBJECTS =

reading_manager: CMakeFiles/reading_manager.dir/main.cpp.o
reading_manager: CMakeFiles/reading_manager.dir/Book.cpp.o
reading_manager: CMakeFiles/reading_manager.dir/BookRepo.cpp.o
reading_manager: CMakeFiles/reading_manager.dir/Controller.cpp.o
reading_manager: CMakeFiles/reading_manager.dir/UserInterface.cpp.o
reading_manager: CMakeFiles/reading_manager.dir/PersistenceEngine.cpp.o
reading_manager: CMakeFiles/reading_manager.dir/build.make
reading_manager: /Users/ovidiupopa/Qt5.14.2/5.14.2/clang_64/lib/QtWidgets.framework/QtWidgets
reading_manager: /Users/ovidiupopa/Qt5.14.2/5.14.2/clang_64/lib/QtGui.framework/QtGui
reading_manager: /Users/ovidiupopa/Qt5.14.2/5.14.2/clang_64/lib/QtCore.framework/QtCore
reading_manager: CMakeFiles/reading_manager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable reading_manager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reading_manager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reading_manager.dir/build: reading_manager

.PHONY : CMakeFiles/reading_manager.dir/build

CMakeFiles/reading_manager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reading_manager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reading_manager.dir/clean

CMakeFiles/reading_manager.dir/depend:
	cd /Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ovidiupopa/CLionProjects/reading-manager /Users/ovidiupopa/CLionProjects/reading-manager /Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug /Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug /Users/ovidiupopa/CLionProjects/reading-manager/cmake-build-debug/CMakeFiles/reading_manager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reading_manager.dir/depend

