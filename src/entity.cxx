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

#include "entity.h"

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
#include <utility>

namespace {
  const int NO_CHOICE = -1;
}

Entity::Entity(const std::string& name)
  : name_(name)
  , current_choice_(NO_CHOICE)
{
}

Entity::Entity(std::string&& name)
  : name_(name)
  , current_choice_(NO_CHOICE)
{
}

const std::string& Entity::name() const
{
  return name_;
}

Entity* Entity::current_choice() const
{
  if (current_choice_ == NO_CHOICE)
    return NULL;

  if (current_choice_ < 0 || current_choice_ >= preferences_vector_.size())
    return NULL;

  return preferences_vector_[current_choice_].first;
}

bool Entity::has_chosen(const Entity& entity) const
{
  int index = Entity::find_entity_(entity);
  if (index == NO_CHOICE)
    return false;

  return preferences_vector_[index].second;
}

bool Entity::less_than_current_choice(const Entity& entity) const
{
  assert(current_choice_ == NO_CHOICE || preferences_vector_.empty());
  if (current_choice_ == NO_CHOICE || preferences_vector_.empty())
    return false;

  int index = Entity::find_entity_(entity);
  if (index == NO_CHOICE)
    return true;

  return (index > current_choice_);
}

int Entity::find_entity_(const Entity& entity) const
{
  auto it = std::find_if(preferences_vector_.begin(), preferences_vector_.end()
                       , [&, entity](const std::pair<Entity*, bool>& e) {
			   return (e.first == &entity);
			 });

  if (it == preferences_vector_.end()) {
    return NO_CHOICE;
  }
  return std::distance(preferences_vector_.begin(), it);
}
