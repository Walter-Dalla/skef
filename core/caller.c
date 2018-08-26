#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/declare.h"

void __parse__(){

    fp = fopen(f, "r");
    fseek(fp, 0L, SEEK_END);
    _FileSize_ = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // _check_first_()

    char *_LineAUX_ = malloc(2*_FileSize_);
    char *_LineFunction_ = malloc(2*_FileSize_);

    while ( fgets(_LineAUX_, 2*_FileSize_, fp) != NULL ){
        _LineCounter_ ++;

        if ( *_LineAUX_ == '\0' || *_LineAUX_ == '\n' ){
            continue;
        }

        if ( *_LineAUX_ == EOF ){
            free(_LineAUX_);
            exit(0);
        }

        _LineAUX_ = _RemoveSpace_init_(_LineAUX_);
        _LineFunction_ = _Identify_FunctionCall_(_LineAUX_);

        if ( strcmp("[NAME_NOT_FOUND]", _LineFunction_) == 0 ){
            _skf_error_(2, _LineAUX_, f, _LineCounter_);
            exit(1);
        }

    }
    free(_LineAUX_);
    //free(_LineFunction_);
}