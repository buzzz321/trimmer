project(trimmer)

cmake_minimum_required(VERSION 2.6.2)

################################
# Compiler thingies
################################

SET (CMAKE_C_COMPILER   "clang-9")
SET (CMAKE_CXX_COMPILER "clang++-9")
ADD_DEFINITIONS("-std=c++11 -Wall --pedantic -g") 

################################
# Unit Tests
################################
# Add test cpp file
set (trimmer_SRC trimmer.cc 
  )
add_executable( trimmer ${trimmer_SRC})
