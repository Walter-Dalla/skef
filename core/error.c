#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes/declare.h"

void __skf_error__(int __err_number__, char *__err_line__, char *__filename__, int __line_num__, ...){

    switch (__err_number__){
        case 1:

            if ( f == NULL ) f = "";
            fprintf(stdout, "\n    ┌─[ERROR]: Cannot open argued file in current conjuncture\n");
            fprintf(stdout, "    └─────► '%s'\n\n", f);
            exit(1);

        case 2:
        
            fprintf(stdout, "\n    ┌─[ERROR:%d]: In file: \"%s\", there is a name not defined\n", __line_num__, __filename__);
            fprintf(stdout, "    └─────► '%s'\n\n", __err_line__);
            return;
        
        case 3:
            fprintf(stdout, "\n    ┌─[ERROR:%d]: In file: \"%s\", there is an invalid syntax\n", __line_num__, __filename__);
            fprintf(stdout, "    └─────► '%s'\n\n", __err_line__);
            return;


        default:
            printf("[ERROR]: An strange error has occured\n");
    }

}