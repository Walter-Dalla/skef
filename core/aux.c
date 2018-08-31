#include <stdio.h>
#include "includes/declare.h"

// [FUNCTION]: Check file existence
int _check_f_exist_(char *filename){
    FILE *__check_file__;

    if ( (__check_file__ = fopen(filename, "r")) ){
        fclose(__check_file__);
        return 1;
    }
    else{
        return 0;
    }
}