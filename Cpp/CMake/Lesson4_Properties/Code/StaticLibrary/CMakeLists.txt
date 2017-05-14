project(StaticLibrary)

add_library(${PROJECT_NAME} STATIC "Source/StaticLibraryFactory.cpp" "Source/StaticLibraryHeader.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC "Interface")
target_include_directories(${PROJECT_NAME} PRIVATE "Headers")

# Each target, source file, directory, etc. can have properties. 
# The list of properties: https://CMake.org/CMake/help/v3.0/manual/CMake-properties.7.html
# You can manipulate properties via set_property method.
# Here it is set C++11 standard for StaticLibrary project. 
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# You can also specify more than one property for target.
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)

# You can also get property's value. The first argument is output variable name.
# Below a C++ standard of StaticLibrary is retrieved
get_property(WHAT_IS_CPP_STANDARD TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD)

# Displays a result.
message(STATUS "Target: ${PROJECT_NAME} C++ standards: ${WHAT_IS_CPP_STANDARD}")

# Changes a compiler warning to treat warnings as errors.
# There is an unused variable to StaticLibraryFactory.cpp:8: abc, so program WON'T compile.
set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_FLAGS "-Wall -Werror")

# You can also provide compilation flags by following method. Note that each flags must be set separately.
target_compile_options(${PROJECT_NAME} PUBLIC "-Wall" "-Werror")

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
