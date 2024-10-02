cmake_minimum_required(VERSION 3.0)

project(TD07)

file(GLOB CPP_FILES src/*.cpp)

foreach(CPP_NAME ${CPP_FILES})
    get_filename_component(EXECUTABLE_NAME ${CPP_NAME} NAME_WE) 
    add_executable(${EXECUTABLE_NAME} ${CPP_NAME}) 
    target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)
    
endforeach()