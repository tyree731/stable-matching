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

link_directories (
  ${Boost_LIBRARY_DIRS}
  ${YamlCpp_LIBRARY_DIRS}
)
include_directories (
  ${Boost_INCLUDE_DIRS}
  ${YamlCpp_INCLUDE_DIRS}
)

add_executable(stable_matching main.cxx entity.cxx)
target_link_libraries(stable_matching boost_program_options yaml-cpp)
