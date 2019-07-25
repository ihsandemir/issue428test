project(ticket5344test)

set (LIB_DIR /Users/ihsan/Desktop/cpp)
set(PLATFORM Mac_64)
set (CLIENT_VERSION 3.10.1)

link_libraries(pthread)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -O3")

include_directories(${LIB_DIR}/external/include ${LIB_DIR}/${PLATFORM}/hazelcast/include)
#[[
include_directories(~/Desktop/work/src/hazelcast-cpp-client/external/release_include ~/Desktop/work/src/hazelcast-cpp-client/hazelcast/generated-sources/include ~/Desktop/work/src/hazelcast-cpp-client/hazelcast/include)
]]

link_directories(${LIB_DIR}/${PLATFORM}/hazelcast/lib)
#[[
link_directories(~/Desktop/work/src/hazelcast-cpp-client/cmake-build-release)
]]
link_libraries(pthread HazelcastClient${CLIENT_VERSION}_64)

add_executable(ticket5344test main.cpp)