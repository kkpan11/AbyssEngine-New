/**
* Copyright (C) 2021 Tim Sarbin
* This file is part of AbyssEngine <https://github.com/AbyssEngine>.
*
* AbyssEngine is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* AbyssEngine is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with AbyssEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../engine/engine.h"
#include "libabyss/utils.h"
#include "scripting.h"

int abyss_lua_file_exists(lua_State *l) {
   LCHECK_NUMPARAMS(1)
   LCHECK_STRING(1);

   const char *path = lua_tostring(l, 1);

   char *path_tmp = strdup(path);
   const char *path_new = util_fix_mpq_path(path_tmp);

   bool exists = loader_file_exists(engine_get_loader(engine_get_global_instance()), path_new);
   lua_pushboolean(l, exists);

   free(path_tmp);

   return 1;
}