# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Copyright 2011, Stephen Tyree
# Licensed under the GPL Version 3 license.
# http://www.gnu.org/licenses/gpl.html 

#### Project information ####
set(VER_MAJOR "0")
set(VER_MINOR "1")
set(VER_PATCH "0")
set(VERSION   "${VER_MAJOR}.${VER_MINOR}.${VER_PATCH}")
message(STATUS "Configuring StableMatching ${VERSION}")
project(StableMatching)

cmake_minimum_required(VERSION 2.6)

#### Need boost and yaml-cpp ####
set(CMAKE_MODULE_PATH ${StableMatching_SOURCE_DIR}/cmake)
find_package(Boost COMPONENTS program_options REQUIRED)
find_package(YamlCpp REQUIRED)

#### So we can build outside of the main directory ####
include_directories (${CMAKE_CURRENT_BINARY_DIRS})

#### Set global CXX Flags for the project ####
set(CMAKE_CXX_FLAGS "-std=c++0x")

#### Begin building ####
add_subdirectory(src)

#### Build tests ####
enable_testing()
add_subdirectory(test)
