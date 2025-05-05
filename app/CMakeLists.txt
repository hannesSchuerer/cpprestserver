set(APP_SOURCES "main.cpp")
set(APP_INCLUDES "./")

add_executable(${APP_NAME} ${APP_SOURCES})

target_link_libraries(${APP_NAME}
    PRIVATE ${LIB_RESTSERVER_NAME})

target_include_directories(${APP_NAME} PUBLIC ${APP_INCLUDES})
