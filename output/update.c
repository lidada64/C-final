#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define File "C:\\Users\\12281\\Desktop\\stash.txt"
//此时大写字母后不加类别名称
typedef struct hot_dish {
    int num3;
    float price3;
    char name3[20];
    char tasteC[20];
} C;

void append_at_position(long position) {
    int i;
    
beginning:
    printf("How many food you would like to add: ");
    scanf("%d", &i);
    if (i <= 0) {
        printf("ERROR!!!!");
        goto beginning;
    }

    C c;
    FILE *original = fopen(File, "r");
    if (original == NULL) {
        perror("cant open original file");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("cant create temp file");
        fclose(original);
        return;
    }

    // **Step 1: 复制到目标位置前的数据**
    long current_pos = 0;
    int ch;
    while (current_pos < position && (ch = fgetc(original)) != EOF) {
        fputc(ch, temp);
        current_pos++;
    }

    // **Step 2: 插入新数据**
    for (int j = 0; j < i; j++) {
        printf("---------------------------------\nEnter details of dish %d ", j + 1);
        printf("name: ");
        scanf("%s", c.name3);
        printf("---------------------------------\n");
        printf("\nprice: ");
        scanf("%f", &c.price3);
        printf("\nquantity: ");
        scanf("%d", &c.num3);
        printf("\ntaste: ");
        scanf("%s", c.tasteC);

        fprintf(temp, "\n\n>%-10s\n  price:%-10f\n  quantity:%-10d\n  taste:%-10s\n$\n",
                c.name3, c.price3, c.num3, c.tasteC);
    }

    // **Step 3: 复制目标位置后的数据**
    while ((ch = fgetc(original)) != EOF) {
        fputc(ch, temp);
    }

    fclose(original);
    fclose(temp);

    // **Step 4: 替换原文件**
    if (remove(File) != 0) {
        perror("cant delete orignal file");
        return;
    }

    if (rename("temp.txt", File) != 0) {
        perror("cant rename file");
        return;
    }

    printf("Add successfully!\n");
}
long move(){
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
       }
        fseek(p,0,SEEK_CUR);
        position=ftell(p);
     fclose(p);
     return position;
   
}

void delete(int position){
    
    FILE *pc=fopen(File,"r");
    fseek(pc,position,SEEK_CUR);
    char ch;
    int seek=0;
    int i;
   while ((ch = fgetc(pc)) != EOF && ch != 'E') {
    char line[100];
    if (ch == '>') { // 菜品的起始标志
        fgets(line, sizeof(line), pc); // 读取菜品名称
        printf("Dish %d: %s", i + 1, line + 1); 
        i++;
    } else {
        // 跳过无关行
        fgets(line, sizeof(line), pc);
    }
    fclose(pc);
}
}
int main(){
    long position = move(); // 获取目标位置
    if (position > 0) {
        append_at_position(position); // 在指定位置追加数据
    } else {
        printf("cant find the position\n");
    }
    delete(position);
    return 0;
}

