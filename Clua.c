
#include"include/lua.h"
#include"include/lualib.h"
#include"include/lauxlib.h"
#define DEBUG false

#if DEBUG
#include <stdio.h>
void stackDump(lua_State *L)
{
	int i;
	int top = lua_gettop(L);

	for(i = 1; i <= top; i++) {
		int t = lua_type(L, i);
		switch(t) {
			case LUA_TNIL:
				printf("nil");
				break;
			case LUA_TBOOLEAN:
				printf(lua_toboolean(L, i) ? "true" : "false");
				break;
			case LUA_TNUMBER:
				printf("%g", lua_tonumber(L, i));
				break;
			case LUA_TSTRING:
				printf("%s", lua_tostring(L, i));
				break;

			default:
				printf("%s", lua_typename(L, t));
		}
		printf(" ");
	}
	printf("\n\n");
}
#endif

int main()
{
    lua_State* L = luaL_newstate();
    lua_Debug ar;
    const char *name;
    luaL_openlibs(L);//init lua

    lua_getglobal(L, "require");
    lua_pushfstring(L, "modules/Engine");
    lua_call(L, 1, 1); //local Engine = require"modules/Engine"
    
    lua_call(L, 0, 0); //Engine()

    lua_close(L);
}