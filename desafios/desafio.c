#include <stdio.h>

int main(){

    int number;
    int a =0;
    int i=1;

    printf("Hello World!\n");
    printf("ingrese in parametro n:");
    scanf("%d", &number);
    printf("se ingresó el numero:%d \n", number);

    while(i<=number){
        a = a+i;
        i=i+1;
    }

    printf("la suma de todos los números hasta n %d es:\n", number);
    printf(":%d\n",a);

}