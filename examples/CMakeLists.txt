project(FormGenerator)

add_executable(test_fg main.cpp)

target_link_libraries(test_fg PRIVATE form_generator)
#target_link_libraries(test_fg PRIVATE sfml)

target_link_directories(test_fg PUBLIC "${CMAKE_SOURCE_DIR}/lib")

#set(SFML_LIBS "${CMAKE_SOURCE_DIR}/lib")
IF(${CMAKE_BUILD_TYPE} STREQUAL "DEBUG")
    target_link_libraries(test_fg PRIVATE sfml-audio-d)
    target_link_libraries(test_fg PRIVATE sfml-graphics-d)
    target_link_libraries(test_fg PRIVATE sfml-network-d)
    target_link_libraries(test_fg PRIVATE sfml-system-d)
    target_link_libraries(test_fg PRIVATE sfml-window-d)
ELSE()
    target_link_libraries(test_fg PRIVATE sfml-audio)
    target_link_libraries(test_fg PRIVATE sfml-graphics)
    target_link_libraries(test_fg PRIVATE sfml-network)
    target_link_libraries(test_fg PRIVATE sfml-system)
    target_link_libraries(test_fg PRIVATE sfml-window)
ENDIF()


