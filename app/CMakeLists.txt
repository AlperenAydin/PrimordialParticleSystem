add_executable(app main.cpp)
target_include_directories(PPS_lib PUBLIC ./)
target_link_libraries(app PRIVATE PPS_lib)
