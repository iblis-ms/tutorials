cmake_minimum_required(VERSION 3.5)

project(Library)

set(SRC 
  Implementation/HeaderLibrary.cpp
  Implementation/InterfaceLibrary.cpp
  )

add_library(${PROJECT_NAME} STATIC ${SRC})
target_include_directories(${PROJECT_NAME} 
  PUBLIC Interface
  PRIVATE Headers)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

install(TARGETS ${PROJECT_NAME} 
        RUNTIME DESTINATION ${DEPLOY_DIRECTORY}/${PROJECT_NAME}/bin
        LIBRARY DESTINATION ${DEPLOY_DIRECTORY}/${PROJECT_NAME}/lib
        ARCHIVE DESTINATION ${DEPLOY_DIRECTORY}/${PROJECT_NAME}/lib/static
        INCLUDES DESTINATION ${DEPLOY_DIRECTORY}/${PROJECT_NAME}/include)

install(DIRECTORY Interface/ DESTINATION ${DEPLOY_DIRECTORY}/${PROJECT_NAME}/include) # Interface/ - slash to copy content
