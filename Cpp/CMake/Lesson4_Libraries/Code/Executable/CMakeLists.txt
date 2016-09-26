project(Executable)

# Adds a executable target with a given name.
add_executable(${PROJECT_NAME} "Source/ExecutableHeader.cpp" "Source/main.cpp")

# Adds a header folder to the target given in the 1st argument. 
# PRIVATE means that these header files shouldn't be exposed.
target_include_directories(${PROJECT_NAME} PRIVATE "Headers")

# target_link_libraries links the target given in the 1st argument
# with libraries given in following arguments. There are targets' names.
#
# Note: There are 3 types of linking:
# PRIVATE - linked target will NOT be a interface - The interface of the library will not be a interface of the target.
# PUBLIC - linked target will be interface - The interface of the library will a part of a interface of the target.
# INTERFACE - linked interface will extends the target's interface.
target_link_libraries(${PROJECT_NAME} HeaderOnlyLibrary SharedLibrary StaticLibrary)

# DON'T use link_libraries, because it links all targets in this CMakeLists.txt with provided targets in link_libraries.
# You can define more than one target in one CMakeLists.txt and some of them may not required the same libraries.


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/cmake
