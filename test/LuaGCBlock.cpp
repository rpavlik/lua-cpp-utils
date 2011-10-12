/**	@file
	@brief	Minimal test of the LuaGCBlock class

	@date	2011

	@author
	Ryan Pavlik ( <rpavlik@iastate.edu> http://academic.cleardefinition.com/ ),
	Iowa State University
	Virtual Reality Applications Center and
	Human-Computer Interaction Graduate Program
 */

/*
 Copyright Iowa State University 2011
 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or copy at
 http://www.boost.org/LICENSE_1_0.txt)
 */


#include <lua-cpp-utils/LuaGCBlock.h>
extern "C" {
#include <lauxlib.h>
#include <lualib.h>
}


int main(int /*argc*/, char* /*argv*/[]) {

	lua_State *L = lua_open();
	{
		luacpputils::LuaGCBlock stateBlock(L);
		luaL_openlibs(stateBlock.state());
	}
	lua_close(L);
	return 0;
}
