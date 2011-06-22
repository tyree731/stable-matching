/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2011, Stephen Tyree
 * Licensed under the GPL Version 3 license.
 * http://www.gnu.org/licenses/gpl.html
*/

#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

namespace bpo=boost::program_options;

int error(const bpo::options_description& description) {
  std::cerr << description << std::endl;
  return EXIT_FAILURE;
}

int main(int argc, char** argv)
{
  bpo::options_description description("Allowed Options");
  description.add_options()
    ("help", "produce help message")
    ("mentors", bpo::value<std::string>(), "YAML file containing mentors")
    ("mentees", bpo::value<std::string>(), "YAML file containing mentees")
    ;
 
  bpo::variables_map vm;
  bpo::store(bpo::parse_command_line(argc, argv, description), vm);
  bpo::notify(vm);

  if (vm.count("help") || !vm.count("mentors") || !vm.count("mentees")) {
    return error(description);
  }

  std::string mentors_file = vm["mentors"].as<std::string>();
  std::string mentees_file = vm["mentees"].as<std::string>();

  return EXIT_SUCCESS;
}
