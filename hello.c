#include<stdio.h>
#include<string.h>


typedef struct book
{
    char a[100];
    int b;
}book;


int main(){
    int k=0,h;
    printf("输入书的数量");
    scanf("%d",h);
    char g[100];
    book arr[h];
    for(int i=0;i<h;i++){
        printf("输入书名和价格\n");
        scanf("%c%d",arr[i].a,&(arr[i].b));
        if(arr[i].b>=k){
            k=arr[i].b;
            strcpy(g,arr[i].a);
        }
    }
    print("最贵的书是%s,price%d",g,k);
}