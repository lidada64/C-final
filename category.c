#include<stdio.h>
#define File "C:\\Users\\12281\\Desktop\\stash.txt"

int main(){
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
            return 1;
        }
        printf("File is point to %c\n", fgetc(p)); // 应该打印出目标字符前的字符
        printf("%ld\n",position);
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
     printf("File is point to %c\n", fgetc(p)); 
        printf("%ld\n",position);
        fclose(p);
}
