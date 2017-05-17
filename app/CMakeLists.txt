cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp/freetype271/inc)

add_library( testmain SHARED
                src/main/cpp/testmain.cpp
           )

add_library(freetype271 SHARED IMPORTED)
set_target_properties(freetype271 PROPERTIES IMPORTED_LOCATION ../../../../jniLibs/${ANDROID_ABI}/libfreetype271.so)

find_library( log-lib log )

target_link_libraries( testmain ${log-lib} freetype271)
