#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "includes/declare.h"

// declare.h
    // const char *f;

int main(int argc, char *argv[]){

    // Setting location
    setlocale(LC_ALL, "");

    // Setting values
    f = argv[1];

    if ( argv[1] == NULL || _check_f_exist_(f) != 1 ){ _skf_error_(1, "", "", 0); } else{ __parse__(); }
}