/*

    skfio.h -> This file handle all skfio.c function declarations & function structs

~ Gabriel Julio dos Santos
*/

/*

    This file is part of Skef Programming Language.

*/

#ifndef SKFIO_H
#define SKFIO_H


/*
    __Arrangement will save the sequence of printable string

    S -> String
    V -> Variable 
    F -> Function
    C -> Class

*/

typedef struct {

    char **__string;
    char **__variables;
    char **__functions;
    char **__methods;
    char *__Arrangement;
    
} ____SKF_OBJ_print__;

typedef struct {

    char **__strings;
    char **__variables;
    char **__functions;
    char **__methods;
    char *__Arrangement;

} ____SKF_OBJ_StringType; 



// skfio.c Functions
void ____SKF_print__(char *__string__, int __line__);
void ___SKF_var__(char *__string__, int __line__);

#endif