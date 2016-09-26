project(SharedLibrary)

# add_library creates a library target with a name given in the 1st argument.
# There are few types of target. Here is SHARED. It would be *.so file on Linux,
# *.dll on Windows, etc. 
# After a type of library source files should be placed. 
add_library(${PROJECT_NAME} SHARED "Source/SharedLibraryFactory.cpp" "Source/SharedLibraryHeader.cpp")

# Here we include header folders. The first one is PUBLIC, which means
# that content of header files from it can be used to link with other targets.
# PRIVATE headers can be ONLY used by library's header and source files.
# It is not possible to link against symbols from PRIVATE headers.
target_include_directories(${PROJECT_NAME} PUBLIC "Interface")
target_include_directories(${PROJECT_NAME} PRIVATE "Headers")


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
