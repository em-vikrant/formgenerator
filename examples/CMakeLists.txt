project(FormGenerator)

# List of applicatoins to build (in examples directory).
set(EX_APPS test_app basic_app)

# Subdirectory addition to the build pack.
foreach(X IN LISTS EX_APPS)
    # Add subdirectory.
    message(STATUS "Adding \"${X}\" to build pack")
    add_subdirectory(${X})

    # Packaging the shared libraries with the sub directory added - WINDOWS.
    IF(WIN32)
        message(STATUS "SFML shared libs packing to ${X}")

        IF(${CMAKE_BUILD_TYPE} STREQUAL "DEBUG")
            configure_file(${SFML_LIB_PATH}/sfml-audio-d-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
            configure_file(${SFML_LIB_PATH}/sfml-graphics-d-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
            configure_file(${SFML_LIB_PATH}/sfml-network-d-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
            configure_file(${SFML_LIB_PATH}/sfml-system-d-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
            configure_file(${SFML_LIB_PATH}/sfml-window-d-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
        ELSE()
            configure_file(${SFML_LIB_PATH}/sfml-audio-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
            configure_file(${SFML_LIB_PATH}/sfml-graphics-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
            configure_file(${SFML_LIB_PATH}/sfml-network-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
            configure_file(${SFML_LIB_PATH}/sfml-system-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
            configure_file(${SFML_LIB_PATH}/sfml-window-2.dll ${CMAKE_SOURCE_DIR}/build/examples/${X} COPYONLY)
        ENDIF()
    ENDIF()
    message(STATUS "Adding \"${X}\" to build pack - done")
endforeach()
