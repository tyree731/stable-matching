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

#ifndef _ENTITY_H
#define _ENTITY_H

#include <string>
#include <vector>
#include <utility>

/*! \class Entity
 *  \brief An entity in the stable marriage problem.
 *
 *  This class holds all of the requisite methods and variables necessary
 *  in order to calculate the solution to the stable marriage problem.
 */
class Entity {
public:
  explicit Entity(const std::string& name);
  explicit Entity(std::string&& name);

  const std::string& name() const;
  Entity* current_choice() const;

  /*! \fn has_chosen(const Entity& entity) const
   *  \brief Returns whether current_choice has ever been Entity entity.
   *
   *  The stable marriage algorithm needs to know whether or not a given
   *  entity was ever chosen before in order to avoid cycles. This function
   *  tells it whether current_choice would ever have returned entity.
   */
  bool has_chosen(const Entity& entity) const;

  /*! \fn less_than_current_choice(const Entity& entity) const
   *  \brief Returns whether entity has a lower index than current_choice().
   *
   *  The stable marriage algorithm needs to know the relative order of
   *  preference of two Entitys for a given entity. This function determines
   *  this based on their index within the preferences_vector_.
   */
  bool less_than_current_choice(const Entity& entity) const;

private:
  /*! \fn find_entity_(const Entity& entity) const
   *  \brief Finds the index of entity in preferences_vector_.
   *  
   *  Finds the index of entity in preferences_vector_.
   */
  int find_entity_(const Entity& entity) const;

  std::string name_;
  std::vector<std::pair<Entity*, bool>> preferences_vector_;
  int current_choice_;
};

#endif /**** _ENTITY_H ****/
