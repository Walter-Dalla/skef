#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/declare.h"

void _ExtractString_(int _InitPCall_, char* __string__, int __line__){
    
}

void _skf_print_(char *__string__, int __line__){

    int i = 1;

    while(1){
        if ( __string__[4+i] == ' ' ){
            i += 1;
            continue;
        }
        else if ( __string__[4+i] == '(' ){
            _ExtractString_(4+i, __string__, __line__);
            break;
        }
        else{printf("found init in position: %d\n", i);
            _skf_error_(2, __string__, f, __line__);
            exit(1);
        }
    }

    
}