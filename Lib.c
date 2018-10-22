#include <stdlib.h>
#include <stdio.h>


char* rem(char * string);
long double toNumber(char * string);
int isNumber(char * string);

char peek(char * string){
    return *string;
}

char* nextPeek(char * string){
    string++;
    if(*string == ' '){
        string++;
    }
        
return string;
}





//=10+10*10-(10-5) = 95;



int isNumber(char * string){
    if((peek(string) >= '0' && peek(string)<='9'))
        return 1;
    return 0;
}


long double sunAndSub(char * string, long double result){

    char signal = *string;
    
    long double number = 0;
    string = nextPeek(string);
    if(isNumber(string) == 1){
        
        number = toNumber(string);
        if(signal == '*'){
            result *= number;
        }
        else{
            if(number == 0)
                return 0;
            result /= number;   
        }
    }
    return result;
}


long double sunAndSub(char * string, long double result){

    char signal = *string;
    
    long double number = 0;
    string = nextPeek(string);
    if(isNumber(string) == 1){
        
        number = toNumber(string);
        if(signal == '+')
            result += number;
        else
            result -= number;   
    }
    return result;
}





long double toNumber(char * string){
    long double result = 0;
    float contDiv = 1;
    int isFloatable = 0;

    while(isNumber(string) || peek(string) == '.'){
        
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
    char * expressao = "+ 10";
    printf("%Lf\n", sunAndSub(expressao, 10));


    expressao = "* 10";
    printf("%Lf\n", multAndDiv(expressao, 10));


    long double numeber = toNumber("10.44");
    printf("Number: %Lf", numeber);
    return 0;
}
