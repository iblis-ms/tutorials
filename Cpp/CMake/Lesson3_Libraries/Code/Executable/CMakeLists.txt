project(Executable)

# Adds a executable target with a given name.
add_executable(${PROJECT_NAME} "Source/ExecutableHeader.cpp" "Source/main.cpp")

# Adds a header folder to the target given in the 1st argument. 
# PRIVATE means that these header files shouldn't be exposed,  which means that header files from "Headers" directory can't
# be used outside of this target.
# PUBLIC include type makes directory automatically visible for targets that includes this target. It makes only sense for 
# a library target.
# INTERFACE can be used only with interface targets. The Interface target is a target that contains only header files. It also 
# automatically available for for targets that include this interface.
#
# NOTE: The first argument must be target, so you have to provide a target name the same as you used in add_executable or 
#       add_library methods, therefore the order is important. You have to create target, than you can link include directories
target_include_directories(${PROJECT_NAME} PRIVATE "Headers")

# target_link_libraries links the target given in the 1st argument with libraries given in following arguments. There are targets' names.
#
# Note: There are 3 types of linking:
# PRIVATE - linked target will NOT be a interface - The interface of the library will not be a interface of the target.
# PUBLIC - linked target will be interface - The interface of the library will a part of a interface of the target.
# INTERFACE - linked interface will extends the target's interface.
target_link_libraries(${PROJECT_NAME} HeaderOnlyLibrary SharedLibrary StaticLibrary)

# DON'T use link_libraries and include_directories, because it links all targets in this CMakeLists.txt with provided targets in link_libraries.
# You can define more than one target in one CMakeLists.txt and some of them may not required the same libraries.
# Moreover PUBLIC and INTERFACE types allow linking 


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
