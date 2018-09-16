#include "includes/includes.h"

// declare.h
    // const char *f;

int main(int argc, char *argv[]){

    // Setting location
    setlocale(LC_ALL, "");

    // Setting values
    f = argv[1];

    if ( argv[1] == NULL || !_CheckFileExistence_(f) ){ __skf_error__(1, "", "", 0); } else{ __parse__(); }
}