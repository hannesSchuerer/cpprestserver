set(LIB_RESTSERVER_SOURCES "restserver.cpp" "restregistrator.cpp")
set(LIB_RESTSERVER_INCLUDE_SOURCES "restserver.h" "restregistrator.h")
set(LIB_RESTSERVER_INCLUDES "./")

add_library(${LIB_RESTSERVER_NAME} STATIC ${LIB_RESTSERVER_SOURCES} ${LIB_RESTSERVER_INCLUDE_SOURCES})

target_link_libraries(${LIB_RESTSERVER_NAME} PUBLIC
    spdlog::spdlog
    cxxopts::cxxopts
    cpprestsdk::cpprestsdk)

target_include_directories(${LIB_RESTSERVER_NAME} PUBLIC
    ${LIB_RESTSERVER_INCLUDES})
