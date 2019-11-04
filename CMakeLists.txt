cmake_minimum_required(VERSION 3.15)
project(Dominos)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dominos main.cpp CPlayer.cpp CPlayer.h CBoard.cpp CBoard.h CDomino.cpp CDomino.h CDeck.cpp CDeck.h)