cmake_minimum_required(VERSION 4.0)
project(DynamicArraySpellbook VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(dynamic_array_spellbook INTERFACE)

target_include_directories(dynamic_array_spellbook INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(dynamic_array_spellbook INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/lib/timey.lib" "${CMAKE_CURRENT_SOURCE_DIR}/lib/vibrant_logs.lib")

add_executable(dynamic_array_spellbook_test "${CMAKE_CURRENT_SOURCE_DIR}/example.c")
target_link_libraries(dynamic_array_spellbook_test PRIVATE dynamic_array_spellbook)

install(TARGETS dynamic_array_spellbook
	EXPORT dynamic_array_spellbook_targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT dynamic_array_spellbook_targets
	FILE dynamic_array_spellbook_targets.cmake
	NAMESPACE DynamicArraySpellbook::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dynamic_array_spellbook)

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/dynamic_array_spellbook_config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/dynamic_array_spellbook_config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dynamic_array_spellbook)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/dynamic_array_spellbook_config_version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion)

install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/dynamic_array_spellbook_config.cmake
	${CMAKE_CURRENT_BINARY_DIR}/dynamic_array_spellbook_config_version.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dynamic_array_spellbook)
