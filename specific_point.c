#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    char target_char = 'X'; // 这里假设你要找的字符是 'X'
    long position = 0;

    // 打开文件
    file = fopen("C:\\Users\\12281\\Desktop\\stash.txt", "r");
    if (file == NULL) {
        perror("无法打开文件");
        return 1;
    }

    // 遍历文件直到找到目标字符
    while ((ch = fgetc(file)) != EOF) {
        if (ch == target_char) {
            // 找到了目标字符，保存当前位置
            position = ftell(file);
            break;
        }
    }

    // 如果未找到目标字符，position 保持为 0
    if (position != 0) {
        // 移动到目标字符的前一个位置
        if (fseek(file, position - 1, SEEK_SET) != 0) {
            perror("fseek 失败");
            fclose(file);
            return 1;
        }
        
        // 在这里你可以执行一些操作，如读取或写入
        printf("文件指针现在指向 %c\n", fgetc(file)); // 应该打印出目标字符前的字符
    } else {
        printf("未找到指定字符\n");
    }

    fclose(file);
    return 0;
}