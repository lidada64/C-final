// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // 定义产品结构体
// typedef struct {
//     char name[50];     // 名称
//     int quantity;      // 数量
//     char taste[50];    // 口味
//     float price;       // 单价
// } Product;

// // 定义分类信息
// #define MAX_PRODUCTS 10
// Product main_course[MAX_PRODUCTS] = {
//     {"Rice", 0, "", 5.0},
//     {"Noodles", 0, "", 6.0}
// };
// Product cold_dishes[MAX_PRODUCTS] = {
//     {"Cucumber Salad", 0, "", 8.0},
//     {"Wood Ear Salad", 0, "", 10.0}
// };
// Product hot_dishes[MAX_PRODUCTS] = {
//     {"Lamb Soup", 0, "", 20.0},
//     {"Big Plate Chicken", 0, "", 40.0},
//     {"Shredded Potatoes", 0, "", 12.0}
// };

// // 函数声明
// void displayMenu();
// void addProduct(Product products[], int size);
// void displayCategory(Product products[], int size);
// void saveToFile(const char *filePath, Product *main, int mainSize, Product *cold, int coldSize, Product *hot, int hotSize);

// int main() {
//     int choice;
//     const char *filePath = "C:\\Users\\12281\\Desktop\\stash.txt";

//     printf("Welcome to the Chinese Restaurant Inventory System!\n");
//     do {
//         displayMenu();
//         printf("Please select an option (enter 0 to exit): ");
//         scanf("%d", &choice);
//         getchar(); // 清理缓冲区

//         switch (choice) {
//             case 1:
//                 printf("\nMain Course:\n");
//                 displayCategory(main_course, 2);
//                 break;
//             case 2:
//                 printf("\nCold Dishes:\n");
//                 displayCategory(cold_dishes, 2);
//                 break;
//             case 3:
//                 printf("\nHot Dishes:\n");
//                 displayCategory(hot_dishes, 3);
//                 break;
//             case 4:
//                 printf("\nAdd Main Course:\n");
//                 addProduct(main_course, 2);
//                 break;
//             case 5:
//                 printf("\nAdd Cold Dish:\n");
//                 addProduct(cold_dishes, 2);
//                 break;
//             case 6:
//                 printf("\nAdd Hot Dish:\n");
//                 addProduct(hot_dishes, 3);
//                 break;
//             case 0:
//                 saveToFile(filePath, main_course, 2, cold_dishes, 2, hot_dishes, 3);
//                 printf("Data saved, thank you for using the system!\n");
//                 break;
//             default:
//                 printf("Invalid choice, please try again!\n");
//         }
//     } while (choice != 0);

//     return 0;
// }

// // 显示主菜单
// void displayMenu() {
//     printf("\n========== Main Menu ==========");
//     printf("\n1. View Main Course\n2. View Cold Dishes\n3. View Hot Dishes");
//     printf("\n4. Add Main Course\n5. Add Cold Dish\n6. Add Hot Dish\n0. Exit\n");
// }

// // 显示分类信息
// void displayCategory(Product products[], int size) {
//     float totalPrice = 0;
//     int totalQuantity = 0;

//     printf("\n%-10s%-10s%-10s%-10s\n", "Name", "Quantity", "Taste", "Price");
//     for (int i = 0; i < size; i++) {
//         printf("%-10s%-10d%-10s%-10.2f\n", products[i].name, products[i].quantity, products[i].taste, products[i].price);
//         totalQuantity += products[i].quantity;
//         totalPrice += products[i].quantity * products[i].price;
//     }
//     printf("\nTotal Quantity: %d, Total Price: %.2f\n", totalQuantity, totalPrice);
// }

// // 添加产品信息
// void addProduct(Product products[], int size) {
//     int index;
//     printf("Enter the product ID (0-%d): ", size - 1);
//     scanf("%d", &index);
//     getchar(); // 清理缓冲区

//     if (index >= 0 && index < size) {
//         printf("Enter quantity: ");
//         scanf("%d", &products[index].quantity);
//         getchar();
//         printf("Enter taste description: ");
//         fgets(products[index].taste, 50, stdin);
//         products[index].taste[strcspn(products[index].taste, "\n")] = 0; // 去掉换行符
//         printf("Information updated!\n");
//     } else {
//         printf("Invalid ID!\n");
//     }
// }

// // 保存数据到文件
// void saveToFile(const char *filePath, Product *main, int mainSize, Product *cold, int coldSize, Product *hot, int hotSize) {
//     FILE *file = fopen(filePath, "a"); // 追加模式
//     if (!file) {
//         printf("Unable to open file!\n");
//         return;
//     }

//     fprintf(file, "\nMain Course:\n");
//     for (int i = 0; i < mainSize; i++) {
//         fprintf(file, "%s,%d,%s,%.2f\n", main[i].name, main[i].quantity, main[i].taste, main[i].price);
//     }

//     fprintf(file, "\nCold Dishes:\n");
//     for (int i = 0; i < coldSize; i++) {
//         fprintf(file, "%s,%d,%s,%.2f\n", cold[i].name, cold[i].quantity, cold[i].taste, cold[i].price);
//     }

//     fprintf(file, "\nHot Dishes:\n");
//     for (int i = 0; i < hotSize; i++) {
//         fprintf(file, "%s,%d,%s,%.2f\n", hot[i].name, hot[i].quantity, hot[i].taste, hot[i].price);
//     }

//     fclose(file);
// }

//以下是光标功能


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Function to find the next number in the file
// int findNumber(FILE *file, char target) {
//     char ch;
//     while ((ch = fgetc(file)) != EOF) {
//         if (ch == target) {
//             return 1; // Found the target number
//         }
//     }
//     return 0; // Target number not found
// }

// // Function to move the cursor to a specific position
// void moveCursor(FILE *file, int lines) {
//     char ch;
//     int lineCount = 0;
//     while ((ch = fgetc(file)) != EOF) {
//         if (ch == '\n') {
//             lineCount++;
//         }
//         if (lineCount == lines) {
//             break;
//         }
//     }
// }

// int main() {
//     const char *filePath = "C:\\Users\\Desktop\\stash.txt";
//     FILE *file = fopen(filePath, "r");
//     int currentNumber = 1; // Start with '1'
//     int found;

//     while (1) {
//         rewind(file); // Reset file pointer to the beginning
//         printf("Searching for '%d'...\n", currentNumber);
//         found = findNumber(file, currentNumber + '0');

//         if (!found) {
//             printf("Project not created\n");
//             break;
//         }

//         printf("Found '%d', moving cursor 4 lines forward...\n", currentNumber);
//         rewind(file); // Reset file pointer to the beginning
//         moveCursor(file, 4);

//         currentNumber++; // Increment to the next number
//     }

//     fclose(file);
//     return 0;
// }
// #include <stdio.h>
// #define File "C:\\Users\\12281\\Desktop\\stash.txt"

// int main() {
//     printf("Which kind of food you want to add (1-3):\n");
//     int t;
//     char ch;
//     char point;

//     // 用户选择
//     do {
//         printf("1.staple\t2.cold_dish\t3.hot_dish\n");
//         printf(" >: ");
//         scanf("%d", &t);
//     } while (t != 1 && t != 2 && t != 3);

//     switch (t) {
//         case 1: point = 'A'; break;
//         case 2: point = 'B'; break;
//         case 3: point = 'C'; break;
//     }

//     // 打开文件
//     FILE *p = fopen(File, "r");
//     if (p == NULL) {
//         perror("无法打开文件");
//         return 1;
//     }

//     long position = 0;
//     int found = 0;

//     // 遍历文件，寻找目标字符
//     while ((ch = fgetc(p)) != EOF) {
//         if (ch == point) {
//             position = ftell(p); // 保存当前字符位置
//             found = 1;
//             break;
//         }
//     }

//     if (found) {
//         printf("Found %c at position %ld\n", point, position);

//         // 移动到下一行起始位置
//         while ((ch = fgetc(p)) != EOF) {
//             if (ch == '\n') { // 检测换行符
//                 break; // 停止在换行符后
//             }
//         }

//         // 确保跳过空行
//         while ((ch = fgetc(p)) != EOF) {
//             if (ch != '\n' && ch != '\r') { // 跳过空行
//                 fseek(p, -1, SEEK_CUR); // 将指针移动到有效字符位置
//                 break;
//             }
//         }

//         // 打印结果
//         printf("File pointer is now at: '%c'\n", fgetc(p));
//         printf("%d\n",ftell(p));
//     } else {
//         printf("Character %c not found in the file.\n", point);
//     }
    
//     fclose(p);
//     return 0;
// }


// 以下是update system
/*#include <stdio.h>
#define File "C:\\Users\\12281\\Desktop\\stash.txt"

int main() {
    printf("Which kind of food you want to add (1-3):\n");
    int t;
    char ch;
    char point;

    // 用户选择
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

    // 打开文件
    FILE *p = fopen(File, "r");
    if (p == NULL) {
        perror("无法打开文件");
        return 1;
    }

    long position = 0;
    int found = 0;

    // 遍历文件，寻找目标字符
    while ((ch = fgetc(p)) != EOF) {
        if (ch == point) {
            position = ftell(p); // 保存当前字符位置
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Found %c at position %ld\n", point, position);

        // 移动到下一行起始位置
        while ((ch = fgetc(p)) != EOF) {
            if (ch == '\n') { // 检测换行符
                break; // 停止在换行符后
            }
        }

        // 确保跳过空行
        while ((ch = fgetc(p)) != EOF) {
            if (ch != '\n' && ch != '\r') { // 跳过空行
                fseek(p, -1, SEEK_CUR); // 将指针移动到有效字符位置
                break;
            }
        }

        // 打印结果
        printf("File pointer is now at: '%c'\n", fgetc(p));
        printf("%d\n",ftell(p));
    } else {
        printf("Character %c not found in the file.\n", point);
    }
    
    fclose(p);
    return 0;
}

*/

// 以下是 remove system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define File "C:\\Users\\12281\\Desktop\\stash.txt"

void remove_dishes_by_type(int dish_type) {
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

    int ch, current_type, dish_count = 1;
    int inside_category = 0, inside_dish = 0;

    while ((ch = fgetc(original)) != EOF) {
        if (ch >= 'A' && ch <= 'Z' && fgetc(original) == '.') {
            // 进入新的分类
            fputc(ch, temp);
            fputc('.', temp);
            fputc('\n', temp);
            inside_category = 1;
            dish_count = 1; // 重置菜品计数
        } else if (ch == '1' || ch == '2') {
            current_type = ch - '0'; // 提取菜品类型
            if (current_type == dish_type) {
                // 跳过当前菜品
                while ((ch = fgetc(original)) != EOF && ch != '$') {
                    // 忽略菜品内容
                }
                fgetc(original); // 跳过换行符
            } else {
                // 重新编号并保留菜品
                fprintf(temp, "%d", dish_count++);
                while ((ch = fgetc(original)) != EOF) {
                    fputc(ch, temp);
                    if (ch == '$') {
                        fputc('\n', temp);
                        break;
                    }
                }
            }
        } else {
            fputc(ch, temp);
        }
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

    printf("所有类型为 '%d' 的菜品删除成功，并重新编号！\n", dish_type);
}

int main() {
    int dish_type;
    printf("请输入要删除的菜品类型（1 或 2）：");
    scanf("%d", &dish_type);

    if (dish_type == 1 || dish_type == 2) {
        remove_dishes_by_type(dish_type);
    } else {
        printf("无效的菜品类型！请输入 1 或 2。\n");
    }

    return 0;
}
