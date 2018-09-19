#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __SkfPrint{
    int a;
    char *__string__;
}SkfPrint__;

typedef struct __SkfDefine{
    int b;
    char *__string__;
}SkfDefine__;

typedef struct __SkfIf{
    int c;
}SkfIf__;

typedef struct __structures__{
    struct __SkfPrint *__skf_print__;
    struct __SkfDefine *__skf_define__;
    struct __SkfIf *__skf_if__;
}Structures_;

struct __structures__ *__skf_print(){

    struct __structures__ *_var = malloc(1024);
    _var->__skf_print__ = malloc(1024);
    _var->__skf_define__ = malloc(1024);
    _var->__skf_print__->__string__ = malloc(1024);
    _var->__skf_define__->__string__ = malloc(1024);
    strcpy(_var->__skf_print__->__string__, "bolotona");
    strcpy(_var->__skf_define__->__string__, "sgloob sgloob doo");


    return _var;
}

typedef struct skfprint{

        char **__str;


}____SKF_print;



int main(){

    //struct __structures__ *a = __skf_print();
    //struct skfprint *b = malloc(1024);
    //b->__str = malloc(1024);
    //strcpy(b->__str, "abacate");
    //strcpy(b->__str[0], "abacate");

    //printf("%s\n", b->__str[0]);

    struct skfprint *A = malloc(1024);
    A->__str = (char **)malloc(1024);
    A->__str[0] = (char *)malloc(1024);
    A->__str[1] = (char *)malloc(1024);
    A->__str[2] = (char *)malloc(1024);

    strcpy(A->__str[0], "abacate");
    strcpy(A->__str[1], "is");
    strcpy(A->__str[2], "good");
    
    puts(A->__str[0]);
    puts(A->__str[1]);
    puts(A->__str[2]);

    free(A->__str[0]);
    free(A->__str[1]);
    free(A->__str[2]);
    free(A->__str);
    free(A);
    

    
    /*A[0] = (char *)malloc(1024);
    A[1] = (char *)malloc(1024);
    A[2] = (char *)malloc(1024);
    A[21] = (char *)malloc(1024);

    strcpy(A[0], "abacate");
    strcpy(A[1], "bem");
    strcpy(A[2], "louco");
    strcpy(A[21], "loucasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsasdjsbjfbhdfbjsdfbsjdbfjsdfbsdho");


    if ( A[1] == NULL){ puts("E nullll"); }

    puts(A[0]);
    puts(A[1]);
    puts(A[2]);
    puts(A[21]);*/

    //printf("%s\n", a->__skf_print__->__string__);

    
    
}