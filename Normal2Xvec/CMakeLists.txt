# CMakeList.txt : CMake project for Normal2Xvec, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.5)

SET( CMAKE_CXX_FLAGS  "-O1 -g -lrt -DNDEBUG -std=c++11 -DHAVE_CXX0X -march=native -fpic -w -fopenmp -ftree-vectorize -ftree-vectorizer-verbose=0" )
# Add source to this project's executable.
add_executable (Normal2Xvec_bin "Normal2Xvec.cpp" "Normal2Xvec.h")

# TODO: Add tests and install targets if needed.
