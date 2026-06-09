cmake_minimum_required(VERSION 4.0)
project(DynamicArraySpellbook VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(BUILD_SHARED_LIBS "Build using a shared library." ON)

set(LIB_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/daspllbk.c")

add_library(daspllbk ${LIB_SRC})

target_compile_definitions(daspllbk PRIVATE $<$<BOOL:${BUILD_SHARED_LIBS}>:DASPLLBK_EXPORTS>)

target_include_directories(daspllbk PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(daspllbk PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib/timey.lib" "${CMAKE_CURRENT_SOURCE_DIR}/lib/vibrant_logs.lib")

add_executable(daspllbk_test "${CMAKE_CURRENT_SOURCE_DIR}/example.c")
target_link_libraries(daspllbk_test PRIVATE daspllbk)

install(TARGETS daspllbk
	EXPORT daspllbk_targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT daspllbk_targets
	FILE daspllbk_targets.cmake
	NAMESPACE DynamicArraySpellbook::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/daspllbk)

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/daspllbk_config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/daspllbk_config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/daspllbk)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/daspllbk_config_version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion)

install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/daspllbk_config.cmake
	${CMAKE_CURRENT_BINARY_DIR}/daspllbk_config_version.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/daspllbk)
