cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")


foreach(p CMP0071) # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    if(POLICY ${p})
        cmake_policy(SET ${p} NEW)
    endif()
endforeach()

project(Dialog)
find_package(Qt5 REQUIRED COMPONENTS Concurrent Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SRC
	stylesheet.cpp
	customdialog.cpp
	)

set(HEADERS
	customdialog.h
	stylesheet.h
	)

    set(LIBS Qt5::Concurrent Qt5::Widgets)

if(MSVC)
    add_definitions("-D_CRT_SECURE_NO_WARNINGS" "-DNOMINMAX")
    # Disable ZERO_CHECK if need be
    # set(CMAKE_SUPPRESS_REGENERATION true)
endif()


add_executable(${CMAKE_PROJECT_NAME} MACOSX_BUNDLE main.cpp ${SRC} ${HEADERS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${LIBS})
