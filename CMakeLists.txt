cmake_minimum_required(VERSION 3.10)
project(ProjectEuler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find all source files
file(GLOB SOURCE_FILES "*.cpp")

# Create an executable for each source file
foreach(source ${SOURCE_FILES})
    # Get just the filename without extension
    get_filename_component(executable_name ${source} NAME_WE)
    
    # Create executable
    add_executable(${executable_name} ${source})
    
    # For Windows, add .exe extension
    if(WIN32)
        set_target_properties(${executable_name} PROPERTIES SUFFIX ".exe")
    endif()
endforeach()

# Copy data files to build directory
file(GLOB DATA_FILES "doc/*.txt")
foreach(data_file ${DATA_FILES})
    get_filename_component(data_file_name ${data_file} NAME)
    
    # Configure to copy file to build directory
    add_custom_command(
        TARGET ${executable_name}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${data_file}
        ${CMAKE_BINARY_DIR}/bin/doc/${data_file_name}
    )
endforeach()