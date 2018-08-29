#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "includes/declare.h"

void _ExtractString_(int _InitPCall_, char* __string__, int __line__){
    char *_SkfPrintableString_ = calloc(strlen(__string__), sizeof(char *));
    int i=1, n=2, cont=0, _SkfParsedSize_=0;

    while (1){
        if ( __string__[_InitPCall_+i] == '"' ){
            while(1){
              
                if ( __string__[_InitPCall_ + n] == '"'){
                    if ( __string__[(_InitPCall_+n)-1] == '\\' ){
                        strcat(_SkfPrintableString_, "\""); n++; continue;
                    }
                    else{
                        _SkfParsedSize_ = strlen(_SkfPrintableString_);
                        memcpy(&_SkfPrintableString_[_SkfParsedSize_], "\n", 1);
                        write(1, _SkfPrintableString_, _SkfParsedSize_+2);
                        free(_SkfPrintableString_);
                        return;
                        // _PrintParsedString_();
                    }
                }
                
                else { _SkfPrintableString_[cont] = __string__[_InitPCall_+n]; cont++; n++; continue;}
            }
        }
        else if( __string__[_InitPCall_+i] == ' ' || __string__[_InitPCall_+i] == '\t' ){ 
            i++;
            n++;
            continue;
        }

        else { /* _skf_FunctionCall_() */ _skf_error_(3, __string__, f, __line__); exit(1); }
    }
}


void _skf_print_(char *__string__, int __line__){

    int i = 1;

    while(1){
        if ( __string__[4+i] == ' ' ){
            i++;
            continue;
        }
        else if ( __string__[4+i] == '(' ){
            _ExtractString_(4+i, __string__, __line__);
            break;
        }
        else{
            _skf_error_(2, __string__, f, __line__);
            exit(1);
        }
    }

    
}