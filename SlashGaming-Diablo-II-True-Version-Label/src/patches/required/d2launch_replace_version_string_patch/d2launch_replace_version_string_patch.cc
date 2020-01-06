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

#include "d2launch_replace_version_string_patch.hpp"

#include "d2launch_replace_version_string_patch_1_05b.hpp"
#include "d2launch_replace_version_string_patch_1_09b.hpp"
#include "d2launch_replace_version_string_patch_1_09d.hpp"
#include "d2launch_replace_version_string_patch_1_13c.hpp"

namespace sgd2tvl::patches {

std::vector<mapi::GamePatch> Make_D2Launch_ReplaceVersionStringPatch() {
  d2::GameVersion running_game_version_id = d2::GetRunningGameVersionId();

  switch (running_game_version_id) {
    case d2::GameVersion::k1_05B:
    case d2::GameVersion::k1_06B: {
      return Make_D2Launch_ReplaceVersionStringPatch_1_05B();
    }

    case d2::GameVersion::k1_09B: {
      return Make_D2Launch_ReplaceVersionStringPatch_1_09B();
    }

    case d2::GameVersion::k1_09D: {
      return Make_D2Launch_ReplaceVersionStringPatch_1_09D();
    }

    case d2::GameVersion::k1_13C: {
      return Make_D2Launch_ReplaceVersionStringPatch_1_13C();
    }

    default: {
      return {};
    }
  }
}

} // namespace sgd2tvl::patches
