#include <stdio.h>

void pow(int a,int b){

    if (b == 1){
        return 0;
    }
    return a**b;
}
int main(){
    int a;
    int b;
    int c;
    a=2;
    b=5;
    c = pow(a,b);
    printf("%d",c);
}