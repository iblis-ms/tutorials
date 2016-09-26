project(HeaderOnlyLibrary)

# add_library creates library target with a name given in the 1st argument.
# There are few types of target. Here is INTERFACE.
# It should be used for HEADER ONLY library. It doesn't produce any binary file.
add_library(${PROJECT_NAME} INTERFACE)

# INTERFACE library can only include INTERFACE include directories.
# Remember, the first argument is already created target.
target_include_directories(${PROJECT_NAME} INTERFACE "Interface")


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake
