CMake_minimum_required(VERSION 3.5.2 FATAL_ERROR)
project(CMakeLesson8) 

##### IF
# See https://CMake.org/CMake/help/v3.5/command/if.html
######## Numeric
set(varNumeric 15)

if (${varNumeric} LESS 20) # There are also: GREATER, EQUAL, 
  message(STATUS "varNumeric is less than 20")
elseif (${varNumeric} LESS 30) # elseif 
  message(STATUS "varNumeric is less than 30")
else ()                                           # () are required
  message(STATUS "varNumeric is not less than 20")
endif ()                                          # () are required

if ((${varNumeric} LESS 20) AND (${varNumeric} GREATER 10)) # AND, OR can merge conditions
  message(STATUS "varNumeric is between 10 and 20")
endif ()

########## String 
set(varString "123")
if (${varString} STRLESS "abc") # STRGREATER, STREQUAL
  message(STATUS "varString is less than 'abc' alphabetically")
else ()
  message(STATUS "varString is not less than 'abc' alphabetically")
endif ()


##### WHILE
# See https://CMake.org/CMake/help/v3.0/command/while.html
set(whileCounter 1)

while (${whileCounter} LESS 5) # the same format of the condition as for the IF statement
  math(EXPR whileCounter "${whileCounter}+1") # MATH - mathematical expression
  message(STATUS "While counter ${whileCounter}")
endwhile ()

##### FOReach
# See https://CMake.org/CMake/help/v3.0/command/foreach.html
foreach (foreachItem RANGE 0 10 2) # RANGE start stop step
  message(STATUS "foreachItem=${foreachItem}") 
endforeach ()

list(APPEND myList a b c) 
foreach (foreachItem IN LISTS myList) # iteration through list
  message(STATUS "foreachItem=${foreachItem}") 
endforeach ()



# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
