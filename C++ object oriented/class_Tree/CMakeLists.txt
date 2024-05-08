cmake_minimum_required(VERSION 3.18)
project(NegativeExpressions)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(NegativeExpressions
        expr_tree.hpp
        expr_tree_negation.cxx
        expr_tree_negation.hpp
        expr_tree_number.cxx
        expr_tree_number.hpp
        expr_tree_subtraction.cxx
        expr_tree_subtraction.hpp
        main.cxx
        parser.cxx
        parser.hpp)
