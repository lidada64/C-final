#include<stdio.h>
#include<stdarg.h>
int min(int count,...){
    int min,a;
    va_list(aq);
    va_start(aq,count);
    min=va_arg(aq,int);
    for(int i=2;i<=count;i++){
        if((a=va_arg(aq,int))<min){
            min=a;
        }
    }
    va_end(aq);
    return min;
    
}
int main(){
    int count=5;
    int a=min(count,1,2,3,4,5);
    printf("%d",a);
}