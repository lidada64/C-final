#include <stdio.h>
#include <string.h>

int l = 0, o = 0, k = 0, count = 0;

typedef struct food {
    char name[100];
    int price;
    int num;
    char taste[100];
} A;

char category[3][20] = {"1.staple", "2.cold dish", "3.hot dish"};
A a[5000];
A L[1000], O[1000], K[1000];
A *p[3] = {L, O, K};

void edit(int category) {
    int dish_index, choice;
    int max_items = (category == 0 ? l : (category == 1 ? o : k));

    for (int i = 0; i < max_items; i++) {
        printf("%d. %s\n", i + 1, p[category][i].name);
    }

    printf("Select the dish to edit (1-%d): ", max_items);
    scanf("%d", &dish_index);

    if (dish_index < 1 || dish_index > max_items) {
        printf("Invalid selection.\n");
        return;
    }

    dish_index--; // Convert to zero-based index

    while (1) {
        printf("What would you like to change?\n1. Price\n2. Quantity\n3. Taste\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int new_price;
            printf("Enter new price: ");
            scanf("%d", &new_price);
            p[category][dish_index].price = new_price;
            break;
        } else if (choice == 2) {
            int new_quantity;
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);
            p[category][dish_index].num = new_quantity;
            break;
        } else if (choice == 3) {
            char new_taste[100];
            printf("Enter new taste: ");
            scanf("%s", new_taste);
            strcpy(p[category][dish_index].taste, new_taste);
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Edit successful!\nUpdated details:\n");
    printf("Name: %s\nPrice: %d\nQuantity: %d\nTaste: %s\n",
           p[category][dish_index].name,
           p[category][dish_index].price,
           p[category][dish_index].num,
           p[category][dish_index].taste);
}

int main() {
    printf("Welcome to my Chinese restaurant!\n");

    while (1) {
        printf("\nEnter the number to use the corresponding function:\n");
        printf("1. Menu\t2. Add/Remove\t3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("---------- MENU ----------\n");
                if (count == 0) {
                    printf("You have not added any dishes yet.\n");
                } else {
                    for (int n = 0; n < 3; n++) {
                        printf("\nCategory: %s\n", category[n]);
                        printf("-------------------------\n");

                        int sum_p = 0, sum_n = 0;
                        int max_items = (n == 0 ? l : (n == 1 ? o : k));

                        for (int m = 0; m < max_items; m++) {
                            printf("%d. %s\nPrice: %d\nQuantity: %d\nTaste: %s\n",
                                   m + 1,
                                   p[n][m].name,
                                   p[n][m].price,
                                   p[n][m].num,
                                   p[n][m].taste);
                            sum_p += p[n][m].price;
                            sum_n += p[n][m].num;
                        }

                        printf("Total Price: %d\nTotal Quantity: %d\n", sum_p, sum_n);
                        printf("-------------------------\n");
                    }
                }
                break;
            }

            case 2: {
                printf("Which function?\n1. Add\t2. Remove\n");
                int sub_choice;
                scanf("%d", &sub_choice);

                if (sub_choice == 1) {
                    printf("How many dishes do you want to add?\n");
                    int d;
                    scanf("%d", &d);

                    for (int i = 0; i < d; i++) {
                        printf("Enter the type of this dish:\n1. Staple\t2. Cold Dish\t3. Hot Dish\n");
                        int b;
                        scanf("%d", &b);

                        if (b < 1 || b > 3) {
                            printf("Invalid category.\n");
                            continue;
                        }

                        int pos = (b == 1 ? l++ : (b == 2 ? o++ : k++));

                        printf("Enter the name of dish %d: ", i + 1);
                        scanf("%s", a[i].name);

                        printf("Enter price: ");
                        scanf("%d", &a[i].price);

                        printf("Enter quantity: ");
                        scanf("%d", &a[i].num);

                        printf("Enter taste: ");
                        scanf("%s", a[i].taste);

                        p[b - 1][pos] = a[i];
                        count++;
                    }
                } else if (sub_choice == 2) {
                    printf("How many dishes do you want to remove?\n");
                    int d;
                    scanf("%d", &d);

                    for (int i = 0; i < d; i++) {
                        printf("Enter the type of the dish:\n1. Staple\t2. Cold Dish\t3. Hot Dish\n");
                        int b;
                        scanf("%d", &b);

                        if (b < 1 || b > 3) {
                            printf("Invalid category.\n");
                            continue;
                        }

                        int max_items = (b == 1 ? l : (b == 2 ? o : k));

                        for (int m = 0; m < max_items; m++) {
                            printf("%d. %s\n", m + 1, p[b - 1][m].name);
                        }

                        printf("Select the dish to remove: ");
                        int v;
                        scanf("%d", &v);

                        if (v < 1 || v > max_items) {
                            printf("Invalid selection.\n");
                            continue;
                        }

                        for (int m = v - 1; m < max_items - 1; m++) {
                            p[b - 1][m] = p[b - 1][m + 1];
                        }

                        if (b == 1) l--;
                        if (b == 2) o--;
                        if (b == 3) k--;

                        count--;
                    }
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            }

            case 3:
                printf("Looking forward to your next visit!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}
