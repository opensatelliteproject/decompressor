cmake_minimum_required (VERSION 2.6)
project (satdecompress)
enable_language(C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)


# Version
set(VERSION_INFO_MAJOR_VERSION 1)
set(VERSION_INFO_MINOR_VERSION 0)
set(VERSION_INFO_MAINT_VERSION 0git)

add_definitions(-DMAJOR_VERSION=${VERSION_INFO_MAJOR_VERSION})
add_definitions(-DMINOR_VERSION=${VERSION_INFO_MINOR_VERSION})
add_definitions(-DMAINT_VERSION=${VERSION_INFO_MAINT_VERSION})
add_definitions(-DGIT_SHA1=${GIT_SHA1})

# Flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3 -fPIC")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

# Source Code
file(GLOB SOURCES *.c)

add_library (${PROJECT_NAME} SHARED ${SOURCES})
add_library (${PROJECT_NAME}-static STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME}-static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Links
target_link_libraries (${PROJECT_NAME} sz)
target_link_libraries (${PROJECT_NAME} aec)

if(WIN32)
  target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static")
endif()

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
file(GLOB HEADERS *.h)

install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

# Debian Package
SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Lucas Teske")
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libaec0")
SET(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Decompressing Library for Satellite Projects")
INCLUDE(CPack)
