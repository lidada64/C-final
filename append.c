#include<stdio.h>
#include<string.h>//引入为了防止文件里出现大写
#define File "C:\\Users\\12281\\Desktop\\stash.txt"

  typedef struct hot_dish
    {	
        int num3;
       float price3;
        char name3[20];
        char tasteC[20];
      
    }C; 
int main(){
  int i;
   beginning:
    printf("How many food you would like to add: ");
    scanf("%d",&i);
   C c;
FILE *ap=fopen(File,"r+");//记得要写关闭
    if(i<=0){
        printf("ERROR!!!!");
        goto beginning;
    }
    else
    for(int j=0;j<i;j++){
    printf("---------------------------------\nEnter details of dish %d ",j+1);
    printf("name: ");
    scanf("%s",c.name3);
    printf("---------------------------------\n");
    printf("\nprice: ");
    scanf("%f",&c.price3);
    printf("\nquantitiy: ");
    scanf("%d",&c.num3);
    printf("\ntaste: ");
    scanf("%s",c.tasteC);
    fprintf(ap,"\n\n%-10s\n  price:%-10f\n  quantitiy:%-10d\n  taste:%-10s\n",c.name3,c.price3,c.num3,c.tasteC);
    }
    fclose(ap);
}