cmake_minimum_required(VERSION 3.10)

project(gzcom_dll LANGUAGES CXX)

file(GLOB GZCOM_DLL_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/gzcom-dll/src/*.cpp"
)

add_library(gzcom_dll STATIC
    ${GZCOM_DLL_SOURCES}
)

target_include_directories(gzcom_dll PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/gzcom-dll/include"
)

if (MSVC)
    target_compile_definitions(gzcom_dll PUBLIC _CRT_SECURE_NO_WARNINGS)
    target_compile_options(gzcom_dll PRIVATE
        /W3
        /sdl
    )
endif()

target_compile_features(gzcom_dll PUBLIC cxx_std_20)
