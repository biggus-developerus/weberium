project(weberium-net VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenSSL REQUIRED)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_library(
    ${PROJECT_NAME} STATIC
    
    ${SRC_DIR}/net.cpp
    ${SRC_DIR}/socket.cpp
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC ${INC_DIR}
    ${PROJECT_NAME} PRIVATE ${SRC_DIR}
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE winmm ws2_32)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENSSL_LIBRARIES})