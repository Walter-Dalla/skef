#include <stdlib.h>
#include <stdio.h>

char peek(char * string){
    return *string;
}


long double numero(char * string){
    long double result = 0;
    float contDiv = 1;
    int isFloatable = 0;

    while((peek(string) >= '0' && peek(string)<='9') || peek(string) == '.'){
        
        if(peek(string) == '.'){
            string++;
            isFloatable = 1;
            continue;
        }
        
        result = result * 10 + (peek(string) - '0');

        if(isFloatable == 1)
            contDiv *= 10;

        string++;
    }

    return result/contDiv;
}

int main(int argc, char const *argv[])
{
    long double numeber = numero("10.44");
    printf("Number: %Lf", numeber);
    return 0;
}
