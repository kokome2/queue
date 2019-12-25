## cmake 최소 필요 버전
cmake_minimum_required (VERSION 3.5.1)
  
## 프로젝트명
project (queue)
set(CMAKE_CXX_STANDARD 17)

add_executable(queue main.cpp queue.h)