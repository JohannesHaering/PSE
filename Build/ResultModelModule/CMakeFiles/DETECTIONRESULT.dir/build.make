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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dimitar/Desktop/CWD/PSE/PSE/ImplementationPhase/Model

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dimitar/Desktop/CWD/PSE/PSE/Build

# Include any dependencies generated for this target.
include ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/depend.make

# Include the progress variables for this target.
include ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/progress.make

# Include the compile flags for this target's objects.
include ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/flags.make

ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.o: ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/flags.make
ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.o: /home/dimitar/Desktop/CWD/PSE/PSE/ImplementationPhase/Model/ResultModelModule/src/DetectionResult.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dimitar/Desktop/CWD/PSE/PSE/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.o"
	cd /home/dimitar/Desktop/CWD/PSE/PSE/Build/ResultModelModule && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.o -c /home/dimitar/Desktop/CWD/PSE/PSE/ImplementationPhase/Model/ResultModelModule/src/DetectionResult.cpp

ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.i"
	cd /home/dimitar/Desktop/CWD/PSE/PSE/Build/ResultModelModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dimitar/Desktop/CWD/PSE/PSE/ImplementationPhase/Model/ResultModelModule/src/DetectionResult.cpp > CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.i

ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.s"
	cd /home/dimitar/Desktop/CWD/PSE/PSE/Build/ResultModelModule && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dimitar/Desktop/CWD/PSE/PSE/ImplementationPhase/Model/ResultModelModule/src/DetectionResult.cpp -o CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.s

# Object files for target DETECTIONRESULT
DETECTIONRESULT_OBJECTS = \
"CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.o"

# External object files for target DETECTIONRESULT
DETECTIONRESULT_EXTERNAL_OBJECTS =

ResultModelModule/libDETECTIONRESULT.a: ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/src/DetectionResult.cpp.o
ResultModelModule/libDETECTIONRESULT.a: ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/build.make
ResultModelModule/libDETECTIONRESULT.a: ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dimitar/Desktop/CWD/PSE/PSE/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDETECTIONRESULT.a"
	cd /home/dimitar/Desktop/CWD/PSE/PSE/Build/ResultModelModule && $(CMAKE_COMMAND) -P CMakeFiles/DETECTIONRESULT.dir/cmake_clean_target.cmake
	cd /home/dimitar/Desktop/CWD/PSE/PSE/Build/ResultModelModule && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DETECTIONRESULT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/build: ResultModelModule/libDETECTIONRESULT.a

.PHONY : ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/build

ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/clean:
	cd /home/dimitar/Desktop/CWD/PSE/PSE/Build/ResultModelModule && $(CMAKE_COMMAND) -P CMakeFiles/DETECTIONRESULT.dir/cmake_clean.cmake
.PHONY : ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/clean

ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/depend:
	cd /home/dimitar/Desktop/CWD/PSE/PSE/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dimitar/Desktop/CWD/PSE/PSE/ImplementationPhase/Model /home/dimitar/Desktop/CWD/PSE/PSE/ImplementationPhase/Model/ResultModelModule /home/dimitar/Desktop/CWD/PSE/PSE/Build /home/dimitar/Desktop/CWD/PSE/PSE/Build/ResultModelModule /home/dimitar/Desktop/CWD/PSE/PSE/Build/ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ResultModelModule/CMakeFiles/DETECTIONRESULT.dir/depend

