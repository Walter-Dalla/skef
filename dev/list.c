#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct __flist{

    char *__VarName__;
    char *__VarData__;
    char *__VarType__;
    struct __flist *next;

} __Skf_FunctionList__;

int __IsAlreadyDef__(__Skf_FunctionList__ *__List__, char* __VarName){

    __Skf_FunctionList__ *aux;

    for ( aux = __List__; aux != NULL; aux = aux->next ){

        if ( aux->__VarName__[0] == __VarName[0] ){
            if ( strcmp(aux->__VarName__, __VarName) == 0 ){
                return 1;
            }
            else{
                continue;
            }
        }
    }
    return 0;

}

__Skf_FunctionList__ *__concat__(__Skf_FunctionList__ *__List__, char *__VarName, char* __VarType, char* __VarData){

    __Skf_FunctionList__ *aux;

    for ( aux = __List__; aux != NULL; aux = aux->next ){

        if ( aux->__VarName__[0] == __VarName[0] ){
            if ( strcmp(aux->__VarType__, __VarType) != 0 ){
                /*__skf_error__*/ printf("Impossible to concat '%s' with '%s'\n", aux->__VarType__, __VarType);
                free(aux);
                free(__List__);
                exit(0);
            }

            if ( strcmp(aux->__VarName__, __VarName) == 0 ) {
                aux->__VarData__ = (char*) realloc(aux->__VarData__, 2048);
                strcat(aux->__VarData__, __VarData);
                //strcpy(aux->__VarType__, __VarType);
                continue;
            }
            else{
                continue;
            }
        }
    }
    return __List__;
}

__Skf_FunctionList__ *__replace__(__Skf_FunctionList__ *__List__, char *__VarName, char* __VarType, char* __VarData){

    __Skf_FunctionList__ *aux;

    for ( aux = __List__; aux != NULL; aux = aux->next ){

        if ( aux->__VarName__[0] == __VarName[0] ){
            if ( strcmp(aux->__VarName__, __VarName) == 0 ){
                //strcpy(__List__->__VarData__, __VarData);
                //strcpy(__List__->__VarType__, __VarType);
                strcpy(aux->__VarData__, __VarData);
                strcpy(aux->__VarType__, __VarType);
                continue;
            }
            else{
                continue;
            }
        }
    }
    return __List__;
}


__Skf_FunctionList__ *__insert__(__Skf_FunctionList__ *__List__, char *__VarName, char* __VarType, char* __VarData){

    __Skf_FunctionList__ *__NewVar__ = (__Skf_FunctionList__*) malloc(1024);

    __NewVar__->__VarName__ = malloc(1024);
    __NewVar__->__VarData__ = malloc(1024);
    __NewVar__->__VarType__ = malloc(1024);


    strcpy(__NewVar__->__VarName__, __VarName);
    strcpy(__NewVar__->__VarData__, __VarData);
    strcpy(__NewVar__->__VarType__, __VarType);
    __NewVar__->next = __List__;
    return __NewVar__;
}

void __Show__(__Skf_FunctionList__ *__List__){
    __Skf_FunctionList__ *aux;
    for ( aux=__List__; aux!=NULL; aux=aux->next ){
        printf("[%s] %s = %s\n",aux->__VarType__, aux->__VarName__, aux->__VarData__);
    }

}

__Skf_FunctionList__ *____VarAlocation(__Skf_FunctionList__ *__VarList__, char *__VarName, char *__VarType, char *__VarData, int __ReplaceT){

    int n = __IsAlreadyDef__(__VarList__, __VarName);

    // Value replace for already declared variables
    if ( n == 1 && __ReplaceT == 0 ){
        __VarList__ = __replace__(__VarList__, __VarName, __VarType, __VarData);
        return __VarList__;
    }

    // Value concatenation for already declared variables
    else if ( n == 1 && __ReplaceT == 1 ){
        __VarList__ = __concat__(__VarList__, __VarName, __VarType, __VarData);
    }

    // Variable declarations
    else if ( n == 0 && __ReplaceT == 0 ){
        __VarList__ = __insert__(__VarList__, __VarName, __VarType, __VarData);
        return __VarList__;
    }

    // Error handling for varieble concatenation
    else if ( n == 0 && __ReplaceT == 1 ){
        printf("[x] Undeclared var: %s\n", __VarName);
        free(__VarList__);
        exit(0);

    }

}

int main(){

    __Skf_FunctionList__ *__VarList__ = NULL;
    __VarList__ = ____VarAlocation(__VarList__, "nome", "str", "rulio", 0);
    __VarList__ = ____VarAlocation(__VarList__, "nome", "str", "sdsd", 1);
    __VarList__ = ____VarAlocation(__VarList__, "nome", "str", "23232", 1);
    __VarList__ = ____VarAlocation(__VarList__, "nome", "str", "eita", 1);
    __VarList__ = ____VarAlocation(__VarList__, "n1", "int", "2323", 0);


    
    __Show__(__VarList__);
    free(__VarList__);



}