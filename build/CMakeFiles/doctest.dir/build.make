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
CMAKE_COMMAND = C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Asus\OneDrive\Desktop\AIP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Asus\OneDrive\Desktop\AIP\build

# Include any dependencies generated for this target.
include CMakeFiles/doctest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/doctest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/doctest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/doctest.dir/flags.make

CMakeFiles/doctest.dir/src/doctest.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/doctest.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/doctest.cpp
CMakeFiles/doctest.dir/src/doctest.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/doctest.dir/src/doctest.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/doctest.cpp.obj -MF CMakeFiles\doctest.dir\src\doctest.cpp.obj.d -o CMakeFiles\doctest.dir\src\doctest.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\doctest.cpp

CMakeFiles/doctest.dir/src/doctest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/doctest.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\doctest.cpp > CMakeFiles\doctest.dir\src\doctest.cpp.i

CMakeFiles/doctest.dir/src/doctest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/doctest.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\doctest.cpp -o CMakeFiles\doctest.dir\src\doctest.cpp.s

CMakeFiles/doctest.dir/src/xor_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/xor_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/xor_cipher.cpp
CMakeFiles/doctest.dir/src/xor_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/doctest.dir/src/xor_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/xor_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\xor_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\xor_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\xor_cipher.cpp

CMakeFiles/doctest.dir/src/xor_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/xor_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\xor_cipher.cpp > CMakeFiles\doctest.dir\src\xor_cipher.cpp.i

CMakeFiles/doctest.dir/src/xor_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/xor_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\xor_cipher.cpp -o CMakeFiles\doctest.dir\src\xor_cipher.cpp.s

CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/gronsfeld_cipher.cpp
CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\gronsfeld_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\gronsfeld_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\gronsfeld_cipher.cpp

CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\gronsfeld_cipher.cpp > CMakeFiles\doctest.dir\src\gronsfeld_cipher.cpp.i

CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\gronsfeld_cipher.cpp -o CMakeFiles\doctest.dir\src\gronsfeld_cipher.cpp.s

CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/vigenere_cipher.cpp
CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\vigenere_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\vigenere_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\vigenere_cipher.cpp

CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\vigenere_cipher.cpp > CMakeFiles\doctest.dir\src\vigenere_cipher.cpp.i

CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\vigenere_cipher.cpp -o CMakeFiles\doctest.dir\src\vigenere_cipher.cpp.s

CMakeFiles/doctest.dir/src/affine_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/affine_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/affine_cipher.cpp
CMakeFiles/doctest.dir/src/affine_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/doctest.dir/src/affine_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/affine_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\affine_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\affine_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\affine_cipher.cpp

CMakeFiles/doctest.dir/src/affine_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/affine_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\affine_cipher.cpp > CMakeFiles\doctest.dir\src\affine_cipher.cpp.i

CMakeFiles/doctest.dir/src/affine_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/affine_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\affine_cipher.cpp -o CMakeFiles\doctest.dir\src\affine_cipher.cpp.s

CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/rail_fence_cipher.cpp
CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\rail_fence_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\rail_fence_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\rail_fence_cipher.cpp

CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\rail_fence_cipher.cpp > CMakeFiles\doctest.dir\src\rail_fence_cipher.cpp.i

CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\rail_fence_cipher.cpp -o CMakeFiles\doctest.dir\src\rail_fence_cipher.cpp.s

CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/turn_grid_cipher.cpp
CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\turn_grid_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\turn_grid_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\turn_grid_cipher.cpp

CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\turn_grid_cipher.cpp > CMakeFiles\doctest.dir\src\turn_grid_cipher.cpp.i

CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\turn_grid_cipher.cpp -o CMakeFiles\doctest.dir\src\turn_grid_cipher.cpp.s

CMakeFiles/doctest.dir/src/reverser_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/reverser_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/reverser_cipher.cpp
CMakeFiles/doctest.dir/src/reverser_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/doctest.dir/src/reverser_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/reverser_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\reverser_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\reverser_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\reverser_cipher.cpp

CMakeFiles/doctest.dir/src/reverser_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/reverser_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\reverser_cipher.cpp > CMakeFiles\doctest.dir\src\reverser_cipher.cpp.i

CMakeFiles/doctest.dir/src/reverser_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/reverser_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\reverser_cipher.cpp -o CMakeFiles\doctest.dir\src\reverser_cipher.cpp.s

CMakeFiles/doctest.dir/src/polybius_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/polybius_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/polybius_cipher.cpp
CMakeFiles/doctest.dir/src/polybius_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/doctest.dir/src/polybius_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/polybius_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\polybius_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\polybius_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\polybius_cipher.cpp

CMakeFiles/doctest.dir/src/polybius_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/polybius_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\polybius_cipher.cpp > CMakeFiles\doctest.dir\src\polybius_cipher.cpp.i

CMakeFiles/doctest.dir/src/polybius_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/polybius_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\polybius_cipher.cpp -o CMakeFiles\doctest.dir\src\polybius_cipher.cpp.s

CMakeFiles/doctest.dir/src/pi_cipher.cpp.obj: CMakeFiles/doctest.dir/flags.make
CMakeFiles/doctest.dir/src/pi_cipher.cpp.obj: C:/Users/Asus/OneDrive/Desktop/AIP/src/pi_cipher.cpp
CMakeFiles/doctest.dir/src/pi_cipher.cpp.obj: CMakeFiles/doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/doctest.dir/src/pi_cipher.cpp.obj"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doctest.dir/src/pi_cipher.cpp.obj -MF CMakeFiles\doctest.dir\src\pi_cipher.cpp.obj.d -o CMakeFiles\doctest.dir\src\pi_cipher.cpp.obj -c C:\Users\Asus\OneDrive\Desktop\AIP\src\pi_cipher.cpp

CMakeFiles/doctest.dir/src/pi_cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/doctest.dir/src/pi_cipher.cpp.i"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\OneDrive\Desktop\AIP\src\pi_cipher.cpp > CMakeFiles\doctest.dir\src\pi_cipher.cpp.i

CMakeFiles/doctest.dir/src/pi_cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/src/pi_cipher.cpp.s"
	C:\Users\Asus\Downloads\winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r3\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\OneDrive\Desktop\AIP\src\pi_cipher.cpp -o CMakeFiles\doctest.dir\src\pi_cipher.cpp.s

# Object files for target doctest
doctest_OBJECTS = \
"CMakeFiles/doctest.dir/src/doctest.cpp.obj" \
"CMakeFiles/doctest.dir/src/xor_cipher.cpp.obj" \
"CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.obj" \
"CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.obj" \
"CMakeFiles/doctest.dir/src/affine_cipher.cpp.obj" \
"CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.obj" \
"CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.obj" \
"CMakeFiles/doctest.dir/src/reverser_cipher.cpp.obj" \
"CMakeFiles/doctest.dir/src/polybius_cipher.cpp.obj" \
"CMakeFiles/doctest.dir/src/pi_cipher.cpp.obj"

# External object files for target doctest
doctest_EXTERNAL_OBJECTS =

doctest.exe: CMakeFiles/doctest.dir/src/doctest.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/xor_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/gronsfeld_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/vigenere_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/affine_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/rail_fence_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/turn_grid_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/reverser_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/polybius_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/src/pi_cipher.cpp.obj
doctest.exe: CMakeFiles/doctest.dir/build.make
doctest.exe: CMakeFiles/doctest.dir/linkLibs.rsp
doctest.exe: CMakeFiles/doctest.dir/objects1.rsp
doctest.exe: CMakeFiles/doctest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable doctest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\doctest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/doctest.dir/build: doctest.exe
.PHONY : CMakeFiles/doctest.dir/build

CMakeFiles/doctest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\doctest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/doctest.dir/clean

CMakeFiles/doctest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Asus\OneDrive\Desktop\AIP C:\Users\Asus\OneDrive\Desktop\AIP C:\Users\Asus\OneDrive\Desktop\AIP\build C:\Users\Asus\OneDrive\Desktop\AIP\build C:\Users\Asus\OneDrive\Desktop\AIP\build\CMakeFiles\doctest.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/doctest.dir/depend

