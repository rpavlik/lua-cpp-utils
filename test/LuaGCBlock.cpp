
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
