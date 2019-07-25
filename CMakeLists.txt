project(ticket5344test)

if("${CLIENT_VERSION}x" STREQUAL "x")
    message(FATAL_ERROR "Please provide -DCLIENT_VERSION.")
endif ()

if("${LIB_DIR}x" STREQUAL "x")
    message(FATAL_ERROR "Please provide -DLIB_DIR.")
endif ()

message (STATUS "Using hazelcast installation at ${LIB_DIR}.")
message (STATUS "Using hazelcast cpp client version ${CLIENT_VERSION}.")

set (BITS 64)
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(PLATFORM Mac)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(PLATFORM Linux)
else()
    set(PLATFORM Windows)
endif()

link_libraries(pthread)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -O3")

include_directories(${LIB_DIR}/external/include ${LIB_DIR}/${PLATFORM}_${BITS}/hazelcast/include)
link_directories(${LIB_DIR}/${PLATFORM}_${BITS}/hazelcast/lib)
link_libraries(pthread HazelcastClient${CLIENT_VERSION}_64)

add_executable(ticket5344test main.cpp)