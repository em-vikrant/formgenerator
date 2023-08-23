project(FormGenerator)

message(STATUS "Building source files... ${PROJECT_SOURCE_DIR}")
set(INCROOT ${PROJECT_SOURCE_DIR}/../include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/FormGenerator)

# All source files
set(SRC
    ${SRCROOT}/Widget.cpp
    ${SRCROOT}/Button.cpp
    ${SRCROOT}/TextBox.cpp
    ${SRCROOT}/FormGenerator.cpp
    )

add_library(form_generator ${SRC})

target_include_directories(form_generator PUBLIC "${INCROOT}")

