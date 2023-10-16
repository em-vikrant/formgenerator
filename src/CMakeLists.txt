project(FormGenerator)

# Project include and source directory path.
set(INCROOT ${PROJECT_SOURCE_DIR}/../inc)
set(SRCROOT ${PROJECT_SOURCE_DIR}/FormGenerator)

# All source files
set(SRC
    ${INCROOT}/FormGenerator/Widget.hpp
    ${SRCROOT}/Widget.cpp
    ${INCROOT}/FormGenerator/Button.hpp
    ${SRCROOT}/Button.cpp
    ${INCROOT}/FormGenerator/TextBox.hpp
    ${SRCROOT}/TextBox.cpp
    ${INCROOT}/FormGenerator/FormGenerator.hpp
    ${SRCROOT}/FormGenerator.cpp
    )

# Add library
add_library(form_generator ${SRC})

# Set the include folder paths
target_include_directories(form_generator PUBLIC "${INCROOT}")
target_include_directories(form_generator PUBLIC "${SFML_INC_PATH}")
target_link_libraries(form_generator PRIVATE -L${SFML_LIB_PATH})

IF(${CMAKE_BUILD_TYPE} STREQUAL "DEBUG")
    target_link_libraries(form_generator PRIVATE sfml-audio-d)
    target_link_libraries(form_generator PRIVATE sfml-graphics-d)
    target_link_libraries(form_generator PRIVATE sfml-network-d)
    target_link_libraries(form_generator PRIVATE sfml-system-d)
    target_link_libraries(form_generator PRIVATE sfml-window-d)
ELSE()
    target_link_libraries(form_generator PRIVATE sfml-audio)
    target_link_libraries(form_generator PRIVATE sfml-graphics)
    target_link_libraries(form_generator PRIVATE sfml-network)
    target_link_libraries(form_generator PRIVATE sfml-system)
    target_link_libraries(form_generator PRIVATE sfml-window)
ENDIF()
