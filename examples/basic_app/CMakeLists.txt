project(FormGenerator)

add_executable(basic_app main.cpp)
target_link_libraries(basic_app PRIVATE form_generator)

