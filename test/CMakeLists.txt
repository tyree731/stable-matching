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

#### Build Google Test ####
add_subdirectory(contrib)
set(gtest_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/contrib/gtest/include)
set(gtest_LIBRARY_DIRS ${CMAKE_CURRENT_BINARY_DIR}/contrib/gtest)

link_directories (
  ${gtest_LIBRARY_DIRS}
)
include_directories (
  ${gtest_INCLUDE_DIRS}
)

add_executable(test_matching test.cxx)
target_link_libraries(test_matching gtest)

ADD_TEST(test_matching_1 test_matching)
