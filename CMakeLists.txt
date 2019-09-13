cmake_minimum_required(VERSION 3.13)

project(pattern)

set(src_files
    creational/singleton_pattern.cpp
    creational/prototype_pattern.cpp)

set(exe_files
    singleton
    prototype)

set(entry_file
    main.cpp)

set(common_dir
    common/)

foreach(src ${src_files})
    string(REGEX REPLACE "([A-z]+/)+([A-z]+)_pattern\\.cpp" "\\2" exe ${src})
    add_executable(${exe} ${entry_file} ${src})
    target_include_directories(${exe} PRIVATE ${common_dir})
endforeach()
