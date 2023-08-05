project(FormGenerator)

#message(STATUS "Linking SFML libraries... ${CMAKE_SOURCE_DIR}/lib")
#set(LIBROOT ${CMAKE_SOURCE_DIR}/lib)

# All source files
#set(SRC
    #    ${LIBROOT}/sfml-audio-2.dll
    #${LIBROOT}/sfml-graphics-2.dll
    #${LIBROOT}/sfml-network-2.dll
    #${LIBROOT}/sfml-window-2.dll
    #   ${LIBROOT}/libsfml-audio.a
    #${LIBROOT}/libsfml-graphics.a
    #${LIBROOT}/libsfml-main.a
    #${LIBROOT}/libsfml-network.a
    #${LIBROOT}/libsfml-system.a
    #)

    #add_library(sfml ${SRC})
#set_target_properties(sfml PROPERTIES LINKER_LANGUAGE CPP)


#set(GCC_COVERAGE_COMPILE_FLAGS "-L${CMAKE_SOURCE_DIR}/lib")
#SET(GCC_COVERAGE_LINK_FLAGS    "-L${CMAKE_SOURCE_DIR}/lib -lsfml-graphics -lsfml-window -lsfml-system")

#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
#SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
