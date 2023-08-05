project(FormGenerator)

add_executable(test_fg main.cpp)

target_link_libraries(test_fg PRIVATE form_generator)
#target_link_libraries(test_fg PRIVATE sfml)

target_link_directories(test_fg PUBLIC "${CMAKE_SOURCE_DIR}/lib")

#set(SFML_LIBS "${CMAKE_SOURCE_DIR}/lib")
target_link_libraries(test_fg PRIVATE sfml-audio)
target_link_libraries(test_fg PRIVATE sfml-graphics)
target_link_libraries(test_fg PRIVATE sfml-network)
target_link_libraries(test_fg PRIVATE sfml-system)
target_link_libraries(test_fg PRIVATE sfml-window)

# Binary Packaging.
# Packaging the shared libraries with the directory containing the executable.
configure_file(${CMAKE_SOURCE_DIR}/lib/sfml-audio-2.dll ${CMAKE_SOURCE_DIR}/build/examples COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/lib/sfml-graphics-2.dll ${CMAKE_SOURCE_DIR}/build/examples COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/lib/sfml-network-2.dll ${CMAKE_SOURCE_DIR}/build/examples COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/lib/sfml-system-2.dll ${CMAKE_SOURCE_DIR}/build/examples COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/lib/sfml-window-2.dll ${CMAKE_SOURCE_DIR}/build/examples COPYONLY)
