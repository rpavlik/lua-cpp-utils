# Embedded build for LuaBind
# 2009-2010 Ryan Pavlik <rpavlik@iastate.edu>
# http://academic.cleardefinition.com/
# Iowa State University HCI Graduate Program/VRAC

set(ALLHEADERS
	LuaGCBlock.h
	LuaStackChecker.h
	LuaUserdata.h)
set(ALLHEADERS ${ALLHEADERS} PARENT_SCOPE)

add_custom_target(lua-cpp-utils SOURCES ${HEADERS})

