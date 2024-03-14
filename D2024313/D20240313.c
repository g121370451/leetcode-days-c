#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* maximumOddBinaryNumber(char* s){
    int i = 0;
    int count_one = 0;
    int count_zero = 0;
    while(s[i]!='\0'){
        if (s[i] == '1')
        {
            ++count_one;
        }else{
            ++count_zero;
        }
        i++;
    }
    i=0;
    while(count_one-1){
        s[i++] = '1';
        --count_one;
    }
    while(count_zero){
        s[i++] = '0';
        --count_zero;
    }
    s[i] = '1';
    return s;
}
int main(){
    char a[] = "1";
    char *b = maximumOddBinaryNumber(a);
    int i = 0;
    while(b[i]!='\0'){
        printf("%c",b[i]);
        ++i;
    }
    return 0;
}