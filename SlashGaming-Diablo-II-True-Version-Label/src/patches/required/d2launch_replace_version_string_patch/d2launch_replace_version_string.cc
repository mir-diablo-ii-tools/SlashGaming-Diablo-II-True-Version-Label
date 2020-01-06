/**
 * SlashGaming Diablo II True Version Label
 * Copyright (C) 2020  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II True Version Label.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "d2launch_replace_version_string.hpp"

#include <windows.h>

namespace sgd2tvl::patches {

void __cdecl SGD2TVL_D2Launch_WriteVersionString(
    char* version_string
) {
  constexpr int major_version_number = 1;
  int minor_version_number = 0;
  char revision = '\0';
  std::string_view additional_text = "";

  switch (d2::GetRunningGameVersionId()) {
    case d2::GameVersion::k1_05B: {
      minor_version_number = 5;
      revision = 'b';
      break;
    }

    case d2::GameVersion::k1_06B: {
      minor_version_number = 6;
      revision = 'b';
      break;
    }

    case d2::GameVersion::k1_09B: {
      minor_version_number = 9;
      revision = 'b';
      break;
    }

    case d2::GameVersion::k1_09D: {
      minor_version_number = 9;
      revision = 'd';
      break;
    }

    case d2::GameVersion::k1_10Beta: {
      minor_version_number = 10;
      additional_text = "Beta";
      break;
    }

    case d2::GameVersion::k1_10SBeta: {
      minor_version_number = 10;
      revision = 's';
      additional_text = "Beta";
      break;
    }

    case d2::GameVersion::k1_11B: {
      minor_version_number = 11;
      revision = 'b';
      break;
    }

    case d2::GameVersion::k1_13ABeta: {
      minor_version_number = 13;
      revision = 'a';
      additional_text = "PTR";
      break;
    }

    case d2::GameVersion::k1_13C: {
      minor_version_number = 13;
      revision = 'c';
      break;
    }

    case d2::GameVersion::k1_13D: {
      minor_version_number = 13;
      revision = 'd';
      break;
    }
  }

  std::snprintf(
      version_string,
      32,
      "v %d.%02d%c",
      major_version_number,
      minor_version_number,
      revision
  );
}

} // namespace sgd2tvl::patches
