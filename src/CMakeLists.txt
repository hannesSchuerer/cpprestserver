set(LIB_RESTSERVER_INCLUDE_SOURCES "irestserver.h" "restregistrator.h")
set(LIB_RESTSERVER_INCLUDES "./")

add_library(${LIB_RESTSERVER_NAME} STATIC ${LIB_RESTSERVER_INCLUDE_SOURCES})

target_link_libraries(
    ${LIB_RESTSERVER_NAME}
    PRIVATE spdlog::spdlog
    PRIVATE cxxopts::cxxopts
    PRIVATE cpprestsdk::cpprestsdk)

target_include_directories(${LIB_RESTSERVER_NAME}
                           PUBLIC ${LIB_RESTSERVER_INCLUDES})

add_subdirectory(core)
