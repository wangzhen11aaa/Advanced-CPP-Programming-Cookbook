#
# Copyright (C) 2019 Rian Quinn <rianquinn@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# ------------------------------------------------------------------------------
# Header
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.6)
project(chapter13)

set(CMAKE_CXX_STANDARD 20)
add_compile_options("-fms-extensions")
include(ExternalProject)

list(APPEND RANGES_CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external/
    -DCMAKE_BUILD_TYPE=Debug
    -DRANGES_CXX_STD=2a
)

ExternalProject_Add(
    ranges
    URL https://github.com/ericniebler/range-v3/archive/0.9.1.zip
    URL_MD5 c21b136fd414f3a655f059e5cf85ec93
    CMAKE_ARGS ${RANGES_CMAKE_ARGS}
)
include_directories(${CMAKE_BINARY_DIR}/external/include)

# ------------------------------------------------------------------------------
# Recipe 01
# ------------------------------------------------------------------------------
add_custom_target(recipe01_examples)

function(example number)
    add_executable(recipe01_example${number} recipe01.cpp)
    target_compile_definitions(recipe01_example${number} PRIVATE EXAMPLE${number})
    add_dependencies(recipe01_examples recipe01_example${number})
endfunction(example)

example(01)
example(02)
example(04)

# ------------------------------------------------------------------------------
# Recipe 02
# ------------------------------------------------------------------------------
add_custom_target(recipe02_examples)

function(example number)
    add_executable(recipe02_example${number} recipe02.cpp)
    target_compile_definitions(recipe02_example${number} PRIVATE EXAMPLE${number})
    add_dependencies(recipe02_examples recipe02_example${number})
endfunction(example)

example(01)
example(03)

# ------------------------------------------------------------------------------
# Recipe 03
# ------------------------------------------------------------------------------
add_custom_target(recipe03_examples)

function(example number)
    add_executable(recipe03_example${number} recipe03.cpp)
    target_compile_definitions(recipe03_example${number} PRIVATE EXAMPLE${number})
    add_dependencies(recipe03_examples recipe03_example${number})
endfunction(example)

example(01)
example(02)
example(03)
example(04)
example(05)
example(06)

# ------------------------------------------------------------------------------
# Recipe 04
# ------------------------------------------------------------------------------
add_custom_target(recipe04_examples)

function(example number)
    add_executable(recipe04_example${number} recipe04.cpp)
    target_compile_definitions(recipe04_example${number} PRIVATE EXAMPLE${number})
    add_dependencies(recipe04_example${number} ranges)
    add_dependencies(recipe04_examples recipe04_example${number})
endfunction(example)

example(01)
example(02)
example(03)
example(04)
example(05)
example(06)

# ------------------------------------------------------------------------------
# Recipe 05
# ------------------------------------------------------------------------------
add_custom_target(recipe05_examples)

function(example number)
    add_executable(recipe05_example${number} recipe05.cpp)
    target_compile_definitions(recipe05_example${number} PRIVATE EXAMPLE${number})
    add_dependencies(recipe05_examples recipe05_example${number})
endfunction(example)

example(01)
