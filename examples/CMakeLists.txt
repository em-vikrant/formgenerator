project(FormGenerator)

# Add option for applications
option(BASIC_APP "ADD APP DIRECTORY" ON)

IF(BASIC_APP)
    message(STATUS "Basic app compilation set to on")
    add_subdirectory(basic_app)
ENDIF()