#include<stdio.h>
#include<string.h>//引入为了防止文件里出现大写
#define File "C:\\Users\\12281\\Desktop\\stash.txt"
//这个代码功能，将文件中的数据放在数组中，更新后在输入进文件

  typedef struct hot_dish
    {	
        int num3;
       float price3;
        char name3[20];
        char tasteC[20];
      
    }C; 
void append(int position){
    int i;
   beginning:
    printf("How many food you would like to add: ");
    scanf("%d",&i);
   C c;
FILE *ap=fopen(File,"r+");//记得要写关闭
fseek(ap,position,SEEK_SET);
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
}//append system
int move(){
    printf("Which kind of food you want to add(1-3):\n");
    int t;
    char ch;//指针寻找字符
    char point;
    do{
    printf("1.staple\t2.cold_dish\t3.hot_dish\n");
    printf(" >: ");
    scanf("%d",&t);
    }while(t!=1&&t!=2&&t!=3);
    switch (t)
    {   
        case 1:
        point='A';//指针要找到的字符
        break;
        case 2:
        point='B';
        break;
        case 3:
        point='C';
        break;
    }
    long position=0;//指针位置
    //将分类前数字标志改为大写字母
    FILE *p=fopen(File,"r");
    while ((ch = fgetc(p)) != EOF) {
        if (ch == point) {
            // 找到了目标字符，保存当前位置
            position = ftell(p);
            break;
        }
    }//从文件开头遍历文件
       if (position != 0) {
        // 移动到目标字符的前一个位置
        if (fseek(p, position - 1, SEEK_SET/*文件开头*/) != 0) {
            perror("fseek 失败");
            fclose(p);
            
        }
        }  
        while((ch = fgetc(p)) != EOF){
            if(ch=='\n'||ch=='E'){
                position=ftell(p);
                break;
            }
            }
        while ((ch = fgetc(p)) != EOF) {
            if (ch != '\n' && ch != '\r') { // 跳过空行
                fseek(p, -1, SEEK_CUR); // 将指针移动到有效字符位置
                break;
            }
        }
        return position;
}//pointer movement system

int main()
{
    int position=move();
    append(position);
    
}