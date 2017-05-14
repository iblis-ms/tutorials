CMake_minimum_required(VERSION 3.5.2 FATAL_ERROR)
project(CMakeLesson7) 

# List is a often used structure in CMake, so let's look it closer.
# Documentation: https://CMake.org/CMake/help/v3.0/command/list.html
# Moreover we can look at calling method and how them should be used.
# Each example starts with operation declaration. 
# Let's check a few examples.

# Declaration:
# list(APPEND <list> [<element> ...])
# Examples:
list(APPEND myList "abc" "234")
list(APPEND myList "123")
# APPEND adds element(s) to the list. 
# <list> this a list name. It defines a list.
# [<element> ...] Means that you can pass a variadic number of elements


# Declaration:
# list(LENGTH <list> <output variable>)
# Example:
list(LENGTH myList myListSize)
message(STATUS "${myListSize}") # displays list size
# LENGTH returns lenght of list.
# Let's check it with previous example. In both cases, the first argument is the list's name, which 
# is typical call structure for CMake.
# See that list(LENGTH myList myListSize) defines myListSize variable. You can display it by 
# a message method and passing to it: ${myListSize}. 


# Declaration:
# list(GET <list> <element index> [<element index> ...] <output variable>)
# Example:
list(GET myList 1 2 myListElements)
message(STATUS "myListElements=${myListElements}")
# GET method retrieves one or more elements from list.
# As always the first argument is the list's name.
# <element index> [<element index> ...] one index or more indices of elements.
# <output variable> Output variable.


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
