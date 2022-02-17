#include <stdio.h>

int main (){
    bool test = 0;
    printf("%s\n", test ? "1":"0");
    fputs(test ? "true":"false", stdout);
}