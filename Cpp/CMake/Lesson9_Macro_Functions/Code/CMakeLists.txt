CMake_minimum_required(VERSION 3.5.2 FATAL_ERROR)

#################### FUNCTION - simple
message(STATUS "---------------------------------------------------------")

function (function_name ARGUMENT_1ST ARGUMENT_2ND) # in bracket: the name of function and arguments' names
  message(STATUS "ARGUMENT_1ST=${ARGUMENT_1ST} ARGUMENT_2ND=${ARGUMENT_2ND}") 
  set(LOCAL_VARIABLE "abc") # This is a local variable, which isn't visible outside the function.
  set(ARGUMENT_1ST "changed") # This changes the value only locally.

  # returning value
  set(VARIABLE_VISIBLE_OUTSIDE "outside" PARENT_SCOPE) # Variable definition in parent scope
endfunction ()

set(FUNCTION_ARGUMENT1 "a")
set(FUNCTION_ARGUMENT2 "b")
function_name(${FUNCTION_ARGUMENT1} ${FUNCTION_ARGUMENT2}) # calling function
message(STATUS "FUNCTION_ARGUMENT1 after calling function: ${FUNCTION_ARGUMENT1}") # variable was changed inside function, but change was visible locally
message(STATUS "VARIABLE_VISIBLE_OUTSIDE after calling function: ${VARIABLE_VISIBLE_OUTSIDE}") # variable defined in function

################## FUNCTION - variadic number of arguments
message(STATUS "---------------------------------------------------------")

function (function_variadic_arguments)
  # ARGV is a list of all arguments
  #
  # ARGC is number of arguments
  #
  # ARGV0 is the first argument
  # ARGV1 is the second argument
  # ARGVn is the n-th argument
  set(ARGUMENT_LIST "${ARGN}")
  foreach(ITEM IN LISTS ARGUMENT_LIST)
    message(STATUS "ARGUMENT=${ITEM}")
  endforeach ()

  message(STATUS "Odd arguments")
  set(STEP 2)

  math(EXPR STOP_NUMBER "${ARGC}-1") # sets the last index
  foreach (COUNTER RANGE 0 ${STOP_NUMBER} ${STEP}) # iterates through arguments
    set(ARGUMENT_VALUE "ARGV${COUNTER}")   # sets variable name: ARGVi ; i - index
    message(STATUS "ARGUMENT_VALUE=${${ARGUMENT_VALUE}}") # value of variable whose name is in the ${ARGUMENT_VALUE} variable
  endforeach ()

endfunction ()

function_variadic_arguments(a b c d e f)

################## FUNCTION - variadic number of argument - simplest solution
message(STATUS "---------------------------------------------------------")

function (function_parsing_arguments)
  message(STATUS "${ARGV}")
  set(OPTIONAL_ARGUMENTS_PATTERN OPTIONAL_VAR1_NAME OPTIONAL_VAR2_NAME) # 2 optional arguments:
  set(ONE_ARGUMENT_PATTERN ONE_ARGUMENT_VAR1_NAME ONE_ARGUMENT_VAR2_NAME) # 2 one argument 
  set(MULTI_ARGUMENT_PATTERN MULTI_ARGUMENT_VAR1_NAME MULTI_ARGUMENT_VAR2_NAME) # 2 multi argument

  # CMAKE_PARSE_ARGUMENTS(<prefix> <options> <one_value_keywords> <multi_value_keywords> args...)
  # arguments: 
  # <prefix> - prefix of variables that will be created.
  # <options> - pattern of optional arguments
  # <one_value_keywords> - pattern of arguments with one value
  # <multi_value_keywords> - pattern of arguments with variadic values
  # args.. - function arguments
  CMake_parse_arguments(VARIABLE_PREFIX "${OPTIONAL_ARGUMENTS_PATTERN}" "${ONE_ARGUMENT_PATTERN}" "${MULTI_ARGUMENT_PATTERN}" ${ARGN} )

  if (${VARIABLE_PREFIX_OPTIONAL_VAR1_NAME}) # True if the argument present
    message(STATUS "VARIABLE_PREFIX_OPTIONAL_VAR1_NAME=${VARIABLE_PREFIX_OPTIONAL_VAR1_NAME}") # True if the argument present
  endif ()

  if (${VARIABLE_PREFIX_OPTIONAL_VAR2_NAME}) # True if the argument present
    message(STATUS "VARIABLE_PREFIX_OPTIONAL_VAR2_NAME=${VARIABLE_PREFIX_OPTIONAL_VAR2_NAME}") # True if the argument present
  endif ()

  message(STATUS "VARIABLE_PREFIX_ONE_ARGUMENT_VAR1_NAME=${VARIABLE_PREFIX_ONE_ARGUMENT_VAR1_NAME}")
  message(STATUS "VARIABLE_PREFIX_ONE_ARGUMENT_VAR2_NAME=${VARIABLE_PREFIX_ONE_ARGUMENT_VAR2_NAME}")

  foreach (ITEM IN ITEMS ${VARIABLE_PREFIX_MULTI_ARGUMENT_VAR1_NAME})
    message(STATUS "VARIABLE_PREFIX_MULTI_ARGUMENT_VAR1_NAME=${ITEM}")
  endforeach ()

  foreach (ITEM IN ITEMS ${VARIABLE_PREFIX_MULTI_ARGUMENT_VAR2_NAME})
    message(STATUS "VARIABLE_PREFIX_MULTI_ARGUMENT_VAR2_NAME=${ITEM}")
  endforeach ()
endfunction ()

function_parsing_arguments(
  OPTIONAL_VAR1_NAME "optional1" 
  ONE_ARGUMENT_VAR1_NAME "oneArg1"
  MULTI_ARGUMENT_VAR1_NAME "multiArg1_a" "multiArg1_b"
  ONE_ARGUMENT_VAR2_NAME "oneArg2")


############################################### MACRO
message(STATUS "---------------------------------------------------------")

macro (macro_name ARGUMENT_1ST ARGUMENT_2ND) # in bracket: the name of macro and arguments' names
  message(STATUS "ARGUMENT_1ST=${ARGUMENT_1ST} ARGUMENT_2ND=${ARGUMENT_2ND}") 
  set(MACRO_VARIABLE "abc") # For a function it would be a local variable, but for a macro it is a normal variable in macro caller scope.
  set(ARGUMENT_1ST "changed") # This changes the value only locally.

  # set(VARIABLE_VISIBLE_OUTSIDE "outside" PARENT_SCOPE) # macro doesn't have a parent
endmacro ()

set(MACRO_ARGUMENT1 "a")
set(MACRO_ARGUMENT2 "b")
macro_name(${MACRO_ARGUMENT1} ${MACRO_ARGUMENT2}) # macro
message(STATUS "MACRO_ARGUMENT1 after macro: ${MACRO_ARGUMENT1}") # variable was changed inside function, but the change was visible locally
message(STATUS "MACRO_VARIABLE=${MACRO_VARIABLE}")

###################################################
###################################################
###### DIFFERENCE BETWEEN FUNCTION AND MACRO ######
###################################################
# Function has:
# - local variable
# - parent 
# It is similar to C-like functions.

# Macro is something like C macro preprocessor. 


# Author: Marcin Serwach
# Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/CMake
