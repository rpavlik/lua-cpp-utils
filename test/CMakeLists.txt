
if(BUILD_TESTING)
	foreach(HEADER ${ALLHEADERS})
		string(REPLACE ".h" "" SHORTNAME "${HEADER}")
		configure_file(test_headercompile.cpp.in "${CMAKE_CURRENT_BINARY_DIR}/test_headercompile_${SHORTNAME}.cpp" @ONLY)

		add_executable(test_headercompile_${SHORTNAME} "${CMAKE_CURRENT_BINARY_DIR}/test_headercompile_${SHORTNAME}.cpp")
		target_link_libraries(test_headercompile_${SHORTNAME} ${LUA_LIBRARIES})
	endforeach()
endif()
