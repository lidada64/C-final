#include <stdio.h>



typedef struct i
{
    int a;
    float b;
    char c[100];
}A;
A f[5];
int main(){
for (int i = 0; i < 5; i++)
{
    printf("Enter the number: ");
    scanf("%d",f[i].a);
}

}
    
