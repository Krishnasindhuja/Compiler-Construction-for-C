cmake_minimum_required(VERSION 3.5)
project(proj2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    backend-x86.c
    backend-x86.h
    bucket.c
    bucket.h
    defs.h
    encode.c
    encode.h
    gram.y
    main.c
    Makefile
    message.c
    message.h
    README.txt
    scan.l
    symtab.c
    symtab.h
    test.c
    tree.c
    tree.h
    types.c
    types.h
    utils.c)

add_executable(proj2 ${SOURCE_FILES})