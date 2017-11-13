project(SharedLibrary)

add_library(${PROJECT_NAME} SHARED "Source/SharedLibraryFactory.cpp" "Source/SharedLibraryHeader.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC "Interface")
target_include_directories(${PROJECT_NAME} PRIVATE "Headers")

# Let's copy all our artifacts to the folder named Artifacts.
# Artifacts
#     |- SharedLibrary
#            |- include (folder with API - Interface folder)
#            |- lib (folder with shared library)

# CMAKE_BINARY_DIR - variable contains a path to the output location
set(EXPORT_DIR "${CMAKE_BINARY_DIR}/Artifacts/${PROJECT_NAME}") # create variable
message(STATUS "EXPORT_DIR=${EXPORT_DIR}")
# install command:
# TARGETS target1, target2, .. targetN - install target related artifacts
# LIBRARY DESTINATION directory - shared library destination path
# RUNTIME DESTINATION directory - executable file destination path or DLLs on Windows
# ARCHIVE DESTINATION directory - static library destination path
install(TARGETS ${PROJECT_NAME} 
  RUNTIME DESTINATION  "${EXPORT_DIR}/lib"
  LIBRARY DESTINATION  "${EXPORT_DIR}/lib" # copy shared library path
)

install(DIRECTORY Interface/ DESTINATION "${EXPORT_DIR}/include") # copy header files to the include directory

# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
