cmake_minimum_required(VERSION 3.16)

# Project description
project( PrimordialParticleSystem
  VERSION 0.1
  DESCRIPTION "A C++ implementation of the Primordial Particle Systems"
  LANGUAGES CXX)

# We need openCV to display the image
find_package( OpenCV REQUIRED )

# We need this clang
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Adding the src/PPS and app directory
add_subdirectory(PPS)
add_subdirectory(app)
