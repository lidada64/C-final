#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define File "C:\\Users\\12281\\Desktop\\stash.txt"

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

            fprintf(temp/*插入在临时文件里*/, "\n\n>.%-10s\n  price:%-10f\n  quantity:%-10d\n  taste:%-10s\n$\n"/*插入"j"作为命名符"&"作为一种菜品的终止符,>作为起始符"*/,
               c.name3, c.price3, c.num3, c.tasteC);/*删除了j的标序作用*/
              
    }

    // **Step 3: 复制目标位置后的数据**
    while ((ch = fgetc(original)) != EOF) {
        fputc(ch, temp);
    }

    fclose(original);
    fclose(temp);

    // **Step 4: 替换原文件**
    if (remove(File) != 0) {
        perror("cant remove original file");
        return;
    }

    if (rename("temp.txt", File) != 0) {
        perror("cant rename temp file");
        return;
    }
//删A，B，C后名称
    printf("Add successfully!\n");
}

long move() {
    printf("Which kind of food you want to add (1-3):\n");
    int t;
    int ch; // 注意：fgetc 的返回值应为 int
    char point;
    do {
        printf("1.staple\t2.cold_dish\t3.hot_dish\n");
        printf(" >: ");
        scanf("%d", &t);
    } while (t != 1 && t != 2 && t != 3);

    switch (t) {
        case 1: point = 'A'; break;
        case 2: point = 'B'; break;
        case 3: point = 'C'; break;
    }

    long position = 0; // 记录指针位置
    FILE *p = fopen(File, "r");
    if (p == NULL) {
        perror("cant open file");
        return -1;
    }
    while ((ch = fgetc(p)) != EOF) {
        if (ch == point) {
            position = ftell(p);
            break;
        }
    }
    fclose(p);
    return position;
}
void delete(long position) {
    FILE *original = fopen(File, "r");
    if (original == NULL) {
        perror("无法打开原文件");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("无法创建临时文件");
        fclose(original);
        return;
    }

    fseek(original, position, SEEK_SET); // 移动到目标大类位置

    int ch, dish_count = 1, current_dish = 0; // 新的菜品编号和当前菜品编号
    int a[100], num; // 存储需要删除的菜品编号

    // 输入需要删除的菜品编号
    printf("How many dishes you want to remove? ");
    scanf("%d", &num);
    printf("Which dishes to remove? ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }

    // 遍历文件内容
    while ((ch = fgetc(original)) != EOF && ch != 'E') {
        if (ch == '>') { // 新菜品的开始
            current_dish++;
            int to_delete = 0;

            // 检查当前菜品是否需要删除
            for (int i = 0; i < num; i++) {
                if (a[i] == current_dish) {
                    to_delete = 1;
                    break;
                }
            }

            if (to_delete) {
                // 跳过当前菜品内容
                while ((ch = fgetc(original)) != EOF && ch != '$');
                continue;
            } else {
                // 保留菜品并重新编号
                fprintf(temp, ">.%d", dish_count++); // 重新编号
                while ((ch = fgetc(original)) != EOF) {
                    fputc(ch, temp);
                    if (ch == '$') {
                        fputc('\n', temp);
                        break;
                    }
                }
            }
        } else {
            // 非菜品部分直接复制
            fputc(ch, temp);
        }
    }

    // 将剩余内容复制到临时文件
    while ((ch = fgetc(original)) != EOF) {
        fputc(ch, temp);
    }

    fclose(original);
    fclose(temp);

    // 替换原文件
    if (remove(File) != 0) {
        perror("无法删除原文件");
        return;
    }

    if (rename("temp.txt", File) != 0) {
        perror("无法重命名临时文件");
        return;
    }

    printf("Remove successfully!\n");
}

int main() {
    int fuc;
    long position = move(); // 获取目标位置
    error:
    printf("Which function you want to use?\n1.append\t2.remove\n>:");
    scanf("%d",&fuc);
    switch(fuc){
        case 1:
        if (position > 0) {
        append_at_position(position); // 在指定位置追加数据
        } else {
        printf("cant find the position\n");
        }
        break;
        case 2:
        if (position > 0) {
        delete(position); // 删除功能
        } else {
        printf("cant find the position\n");
        }
        break;
        default:
        printf("error\n");
        goto error;//如果错了的话可以跳到原来的位置
        
    }
    
    return 0;
}
