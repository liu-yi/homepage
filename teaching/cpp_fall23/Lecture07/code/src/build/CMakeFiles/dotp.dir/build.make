# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\build

# Include any dependencies generated for this target.
include CMakeFiles/dotp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dotp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dotp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dotp.dir/flags.make

CMakeFiles/dotp.dir/main.cpp.obj: CMakeFiles/dotp.dir/flags.make
CMakeFiles/dotp.dir/main.cpp.obj: C:/Users/45288/OneDrive/Courses/CPP/Lecture07/code/src/main.cpp
CMakeFiles/dotp.dir/main.cpp.obj: CMakeFiles/dotp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dotp.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dotp.dir/main.cpp.obj -MF CMakeFiles\dotp.dir\main.cpp.obj.d -o CMakeFiles\dotp.dir\main.cpp.obj -c C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\main.cpp

CMakeFiles/dotp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dotp.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\main.cpp > CMakeFiles\dotp.dir\main.cpp.i

CMakeFiles/dotp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dotp.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\main.cpp -o CMakeFiles\dotp.dir\main.cpp.s

CMakeFiles/dotp.dir/matoperation.cpp.obj: CMakeFiles/dotp.dir/flags.make
CMakeFiles/dotp.dir/matoperation.cpp.obj: C:/Users/45288/OneDrive/Courses/CPP/Lecture07/code/src/matoperation.cpp
CMakeFiles/dotp.dir/matoperation.cpp.obj: CMakeFiles/dotp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dotp.dir/matoperation.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dotp.dir/matoperation.cpp.obj -MF CMakeFiles\dotp.dir\matoperation.cpp.obj.d -o CMakeFiles\dotp.dir\matoperation.cpp.obj -c C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\matoperation.cpp

CMakeFiles/dotp.dir/matoperation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dotp.dir/matoperation.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\matoperation.cpp > CMakeFiles\dotp.dir\matoperation.cpp.i

CMakeFiles/dotp.dir/matoperation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dotp.dir/matoperation.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\matoperation.cpp -o CMakeFiles\dotp.dir\matoperation.cpp.s

# Object files for target dotp
dotp_OBJECTS = \
"CMakeFiles/dotp.dir/main.cpp.obj" \
"CMakeFiles/dotp.dir/matoperation.cpp.obj"

# External object files for target dotp
dotp_EXTERNAL_OBJECTS =

dotp.exe: CMakeFiles/dotp.dir/main.cpp.obj
dotp.exe: CMakeFiles/dotp.dir/matoperation.cpp.obj
dotp.exe: CMakeFiles/dotp.dir/build.make
dotp.exe: C:/msys64/mingw64/lib/libgomp.dll.a
dotp.exe: C:/msys64/mingw64/lib/libmingwthrd.a
dotp.exe: CMakeFiles/dotp.dir/linkLibs.rsp
dotp.exe: CMakeFiles/dotp.dir/objects1.rsp
dotp.exe: CMakeFiles/dotp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable dotp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dotp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dotp.dir/build: dotp.exe
.PHONY : CMakeFiles/dotp.dir/build

CMakeFiles/dotp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dotp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dotp.dir/clean

CMakeFiles/dotp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\build C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\build C:\Users\45288\OneDrive\Courses\CPP\Lecture07\code\src\build\CMakeFiles\dotp.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/dotp.dir/depend

