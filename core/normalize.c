#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/declare.h"

char *_CoreFunctions_[] = {"print", "echo"};

char *_RemoveSpace_init_(char *string){
    while(1){
        if ( string[0] == ' ' || string[0] == '\t' ){ string++; } else { return string; }
    }
}

int _Confirm_Identify_FunctionCall_(char *_String_, char *_StringMacro_){
    int i=0;
    int _StringSize_ = strlen(_String_);
    int _MacroSize_ = strlen(_StringMacro_);
    while( i < _MacroSize_ ){

        if ( _String_[i] == _StringMacro_[i] ){ i++; continue; } else{ return 0; }
    }

    if ( _String_[_MacroSize_] != ' ' && _String_[_MacroSize_] != '(' ){
        return 0; 
    }
    else{ 
        return 1; 
    }
}

char *_Identify_FunctionCall_(char *string){

    int n = sizeof(_CoreFunctions_)/sizeof(_CoreFunctions_[0]);
    int cont = 0;

    if  ( *string == '\0' ){
        return "[END_OF_STR]";
    }

    for ( cont=0; cont < n; cont++ ){
        if ( _CoreFunctions_[cont] == NULL ){
            return "[NULL]";
        }
        if ( strstr(string, _CoreFunctions_[cont]) != NULL ){
            if ( _Confirm_Identify_FunctionCall_(string, _CoreFunctions_[cont]) == 1 ){
                return _CoreFunctions_[cont];
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }    
        //return "[NAME_NOT_FOUND]";
    }
    return "[NAME_NOT_FOUND]";
}