cmake_minimum_required(VERSION 3.8)
project(ex02)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES Player.h Cell.cpp Cell.h Board.cpp Board.h GenralDef.h GameRules.h Point.cpp Point.h Printer.h ConsolePrinter.cpp ConsolePrinter.h HumanPlayer.cpp HumanPlayer.h ReversiDefaultRules.cpp ReversiDefaultRules.h GameManager.cpp GameManager.h AIPlayer.cpp AIPlayer.h GameState.cpp GameState.h main.cpp)
add_executable(ex02 ${SOURCE_FILES})