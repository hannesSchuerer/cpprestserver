set(CORE_SOURCES "log.cpp" "utils.cpp")
set(CORE_INCLUDE_SOURCES "log.h" "utils.h")
set(CORE_INCLUDES "./")

target_sources(${LIB_RESTSERVER_NAME} PRIVATE ${CORE_SOURCES} ${CORE_INCLUDE_SOURCES})

target_include_directories(${LIB_RESTSERVER_NAME} PRIVATE
    ${CORE_INCLUDES})
