project(FormGenerator)

add_executable(test_app main.cpp)
target_link_libraries(test_app PRIVATE form_generator)

