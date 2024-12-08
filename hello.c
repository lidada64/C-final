#include<stdio.h>
int max(int x, int y){
    return x>y?x:y;
}



int main(){
    int a,b,c,d;
    scanf("%d%d%d",&a,&b,&c);
    int (*p)(int a,int b)=max;
    d=p(p(a,b),c);
    printf("%d",d);
}