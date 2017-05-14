project(Executable)

add_executable(${PROJECT_NAME} "Source/ExecutableHeader.cpp" "Source/main.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE "Headers")
target_link_libraries(${PROJECT_NAME} HeaderOnlyLibrary SharedLibrary StaticLibrary)

# Let's copy all our artifacts to the folder named Artifacts.
# Artifacts
#     |- Executable (folder with this executable file)

# CMAKE_BINARY_DIR - variable contains path to the output location
set(EXPORT_DIR "${CMAKE_BINARY_DIR}/Artifacts/${PROJECT_NAME}") # create variable

# install command:
# TARGETS target1, target2, .. targetN - install target related artifacts
# LIBRARY DESTINATION directory - shared library destination path
# RUNTIME DESTINATION directory - executable file destination path
# ARCHIVE DESTINATION directory - static libary destination path
install(TARGETS ${PROJECT_NAME} 
  RUNTIME DESTINATION "${EXPORT_DIR}" # copy executable file
)


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
