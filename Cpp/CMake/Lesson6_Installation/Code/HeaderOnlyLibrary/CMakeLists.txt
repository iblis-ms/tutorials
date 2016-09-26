project(HeaderOnlyLibrary)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE "Interface")

# Let's copy all our artifacts to folder named Artifacts.
# For this project, which has only interface header files, copy content of Interface directory to
# Artifacts/HeaderOnlyLibrary/include folder.
# CMAKE_BINARY_DIR - variable contains a path to the output location
set(EXPORT_DIR "${CMAKE_BINARY_DIR}/Artifacts/${PROJECT_NAME}")
install(DIRECTORY Interface/ DESTINATION "${EXPORT_DIR}/include") # Interface/ - slash to copy content


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
