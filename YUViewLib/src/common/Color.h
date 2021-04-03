/*  This file is part of YUView - The YUV player with advanced analytics toolset
 *   <https://github.com/IENT/YUView>
 *   Copyright (C) 2015  Institut für Nachrichtentechnik, RWTH Aachen University, GERMANY
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   In addition, as a special exception, the copyright holders give
 *   permission to link the code of portions of this program with the
 *   OpenSSL library under certain conditions as described in each
 *   individual source file, and distribute linked combinations including
 *   the two.
 *
 *   You must obey the GNU General Public License in all respects for all
 *   of the code used other than OpenSSL. If you modify file(s) with this
 *   exception, you may extend this exception to your version of the
 *   file(s), but you are not obligated to do so. If you do not wish to do
 *   so, delete this exception statement from your version. If you delete
 *   this exception statement from all source files in the program, then
 *   also delete it here.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <string>

class Color
{
public:
  Color() = default;
  Color(std::string name);
  Color(int R, int G, int B, int A = -1);

  int R() const { return this->values[0]; }
  int G() const { return this->values[1]; }
  int B() const { return this->values[2]; }
  int A() const { return this->values[3]; }
  int alpha() const { return this->values[3]; }
  int gray() const;

  void setAlpha(int alpha) { this->values[3] = alpha; }

  std::string toHex() const;

  bool operator!=(const Color &other) const
  {
    return values[0] != other.values[0] || values[1] != other.values[1] ||
           values[2] != other.values[2] || values[3] != other.values[3];
  }
  bool operator==(const Color &other) const
  {
    return values[0] == other.values[0] && values[1] == other.values[1] &&
           values[2] == other.values[2] && values[3] == other.values[3];
  }

private:
  int values[4]{0, 0, 0, 255};
};
