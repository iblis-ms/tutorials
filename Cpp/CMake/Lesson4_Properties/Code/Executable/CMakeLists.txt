project(Executable)

add_executable(${PROJECT_NAME} "Source/ExecutableHeader.cpp" "Source/main.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE "Headers")

target_link_libraries(${PROJECT_NAME}  StaticLibrary)

# Each target, source file, directory, etc. can have properties.
# The list of properties: https://CMake.org/CMake/help/v3.0/manual/CMake-properties.7.html
# You can get a property's value. The first argument is an output variable name.
# Below a C++ standard of StaticLibrary is retrieved.
get_property(WHAT_IS_CPP_STANDARD TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD)

# Displays a result. The standard will be not displayed. CMake displayes standard if it was changed by CMake.
message(STATUS "Target: ${PROJECT_NAME} C++ standards: ${WHAT_IS_CPP_STANDARD}")


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
