/** @file
	@brief Header

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#ifndef INCLUDED_LuaStackChecker_h_GUID_70c9303b_cb66_46c9_9646_c600aad60947
#define INCLUDED_LuaStackChecker_h_GUID_70c9303b_cb66_46c9_9646_c600aad60947

// Internal Includes
// - none

// Library/third-party includes
#ifdef LUACPP_LUA_INCLUDE
#include LUACPP_LUA_INCLUDE
#else
extern "C" {
#include <lua.h>
#include <lauxlib.h>
}
#endif

// Standard includes
// - none



namespace luacpputils {

/// Class providing RAII-style verification that you're leaving the Lua stack
/// the way you want to leave it.
	class StackChecker {
		public:
			StackChecker(lua_State * L, int difference = 0)
				: _L(L)
				, _diff(difference)
				, _file(NULL)
				, _line(0)
				, _top(lua_gettop(L)) {}
			StackChecker(lua_State * L, const char * file, int line, int difference = 0)
				: _L(L)
				, _diff(difference)
				, _file(file)
				, _line(line)
				, _top(lua_gettop(L)) {}
			~StackChecker() {
				int currentTop = lua_gettop(_L);
				if (currentTop != _top + _diff) {
					if (_file) {
						luaL_error(_L, "StackChecker error for scope opened at %s:%d: Expected top to be %d + %d, got %d", _file, _line, _top, _diff, currentTop);
					} else {
						luaL_error(_L, "StackChecker error: Expected top to be %d + %d, got %d", _top, _diff, currentTop);
					}
				}
			}
		private:
			lua_State * _L;
			int _diff;
			const char * _file;
			int _line;
			int _top;
	};

} // end of namespace luacpputils

#endif // INCLUDED_LuaStackChecker_h_GUID_70c9303b_cb66_46c9_9646_c600aad60947
