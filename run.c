#include <stdio.h>

int main() {
    int N, i, j, spaces, stars;

    printf("Enter a odd number N：");
    scanf("%d", &N);

    // 检查输入是否为奇数
    if (N % 2 == 0 || N <= 0) {
        printf("输入的数字不是正奇数。\n");
        return 1;
    }

    // 上半部分（包含中间行）
    for (i = 1; i <= (N / 2) + 1; i++) {
        spaces = (N / 2) + 1 - i;
        stars = 2 * i - 1;

        for (j = 1; j <= spaces; j++) {
            printf(" ");
        }
        for (j = 1; j <= stars; j++) {
            printf("*");
        }
        printf("\n");
    }

    // 下半部分
    for (i = (N / 2); i >= 1; i--) {
        spaces = (N / 2) + 1 - i;
        stars = 2 * i - 1;

        for (j = 1; j <= spaces; j++) {
            printf(" ");
        }
        for (j = 1; j <= stars; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
