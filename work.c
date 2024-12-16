#include<stdio.h>
int add(int a,int b){
    return a+b;
}
    typedef struct staple
    {
       int num1 ;
       int price;
       char sourceA[50];
       char tasteA[20];
       int addA;
    }A;

    typedef struct cold_dish
    {
        int num2;
        int price3;
        char sourceB[50];
        char tasteB[20];
        int addB;
    }B;
    typedef struct hot_dish
    {
        int num3;
        int price3;
        char sourceC[50];
        char tasteC[20];
        int addC;
    }C;
void append(){
    
}
int main(){
    printf("welcome to my Chinese resturant!\n");
    skip://这是一个飞雷神标记
    printf("Enter the number to use correspond fuciton\n");
    printf("1.Menu\t\t2.Add/Remove\t\t3.Exit\n");
    int choice,choice2;
    scanf("%d",&choice);
    switch (choice)//现阶段难题：要将数据存储到文本里而且要永久存储
    {
    case 1:

    case 2:
        printf("Which kind of dish you want to edit\n");
        printf("1.staple\t\t2.cold dish\t\t3.hot dish\n");
        scanf("%d",&choice2);
        switch (choice2)
        {
            case 1:
            case 2:
            case 3:
        }
    default:
        printf("Looking forward to the next visit\n");
        return 0;
    }
    
}