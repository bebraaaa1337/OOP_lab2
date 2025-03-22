cmake_minimum_required(VERSION 3.10)
project(MyCppProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIBS "Build shared library" ON)
enable_testing()

# Добавьте для совместимости с STL в DLL
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS")
endif()

add_library(MyLibrary SHARED
    src/library.cpp
    include/library.hpp
)

target_compile_definitions(MyLibrary PRIVATE 
    MYLIBRARY_EXPORTS
    -D_WINDLL  # Для правильной работы STL в DLL
)

# Экспорт символов
target_compile_definitions(MyLibrary PRIVATE MYLIBRARY_EXPORTS)

# Публичные заголовки
target_include_directories(MyLibrary PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Настройки компилятора
if(MSVC)
    target_compile_options(MyLibrary PRIVATE /W4 /WX)
else()
    target_compile_options(MyLibrary PRIVATE -Wall -Wextra -Wpedantic -Werror -fPIC)
endif()

# Тесты
find_package(GTest CONFIG REQUIRED)  # Используем CONFIG
add_executable(MyLibraryTests tests/test_basic.cpp)
target_link_libraries(MyLibraryTests
  PRIVATE
  MyLibrary
  GTest::gtest_main 
)

add_test(NAME MyLibraryTests COMMAND MyLibraryTests)