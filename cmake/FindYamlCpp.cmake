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

find_path(YamlCpp_INCLUDE_PATH yaml-cpp/yaml.h)
find_library(YamlCpp_LIBRARY yaml-cpp)
if(YamlCpp_INCLUDE_PATH AND YamlCpp_LIBRARY)
  set(YamlCpp_FOUND TRUE)
endif(YamlCpp_INCLUDE_PATH AND YamlCpp_LIBRARY)
if(YamlCpp_FOUND)
  if(NOT YamlCpp_FIND_QUIETLY)
    message(STATUS "Found yaml-cpp: ${YamlCpp_LIBRARY}")
  endif(NOT YamlCpp_FIND_QUIETLY)
else(YamlCpp_FOUND)
  if(YamlCpp_FIND_REQUIRED)
    message(FATAL_ERROR "Could not find yaml-cpp library.")
  endif(YamlCpp_FIND_REQUIRED)
endif(YamlCpp_FOUND)
