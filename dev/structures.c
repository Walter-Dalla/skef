#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct __obj_string__ {

    char str[];

};

struct __obj_string__ *__extract__(){

    struct __obj_string__ *std = malloc(10);
    std->str = malloc(6);

    //std->x = (int)malloc(10*sizeof(int));

    strcpy(std->str, "peness");

    return std;
}

int main(){

    struct __obj_string__ *__show__ = malloc(20);

    __show__ = __extract__();



    //printf("%d\n", __show__->x);
    printf("%s\n", __show__->str);
    
    /*char jooj[size][size];
    strcpy(jooj, "print (\"abacate\")");
    printf("%s\n", jooj[0]);*/

    //char **_str = (char **) malloc(10*sizeof(char**));





}