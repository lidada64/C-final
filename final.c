#include<stdio.h>
#include<string.h>


int l=0,o=0,k=0,pos,count=0;
typedef struct food
{
    char name[100];
    int price;
    int num;
    char taste[100];
}A;
char category[3][20]={"1.staple","2.cold dish","3.hot dish"};
A a[5000];
A L[1000],O[1000],K[1000];
A *p[3]={L,O,K};

void delete_item(int category, int index) {
    int *str = (category == 0) ? &l : (category == 1) ? &o : &k;
    A *array = (category == 0) ? L : (category == 1) ? O : K;
    if (index < 0 || index >= *str) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < *str - 1; i++) {
        array[i] = array[i + 1];
    }//move the location of previous data
    (*str)--;//update counter"l/o/k"
    printf("Item deleted successfully!\n");
}



void edit(int a,int d){
    int b,i=0,c;
    printf("Here are name(s) of dish(es)\n");
    for(i;i<d;++i){
        printf("%d.%s\n",i+1,(p[a]+i)->name);
    }
    printf("Which would you like to edit?\n");
    scanf("%d",&b);
    if(0<b&&b<=(i+1)){
        change:
        printf("What would you like to change?\n1.price\n2.quantity\n3.taste\n");
        scanf("%d",&c);
        if(c!=1&&c!=2&&c!=3){
            printf("---------------------------\nPlease enter vaild number\n---------------------------\n");
            goto change;
        }//determine whether the number is vaild
        else{
            int pr,nu;
            char ta[20]; 
        switch (c)
        {
        case 1:
        printf("key in new price: ");
        scanf("%d",&pr);
        (p[a]+b-1)->price=pr;
        break;
        case 2:
        printf("key in new quantity: ");
        scanf("%d",&nu);
        (p[a]+b-1)->num=nu;
        break;
        case 3:
        printf("key in new taste: ");
        scanf("%s",ta);
        strcpy((p[a]+b-1)->taste,ta);
        break;
        }
        printf("Edit successfully\nNow the information of this dish are as follows\n");
        printf("----------\nName:%s\nPrice:%d\nQuantity:%d\nTaste:%s",(p[a]+b-1)->name,(p[a]+b-1)->price,(p[a]+b-1)->num,(p[a]+b-1)->taste);
    }
      
    }
    else
    {
    printf("---------------------------\nPlease enter valid number\n---------------------------\n");
    }
}//edit system

int main(){
   
    printf("welcome to my Chinese resturant!\n");
    main_page://main page
    if(count>3){
            count=3;
        }
    printf("Enter the number to use correspond fuciton\n");
    printf("1.Menu\t\t2.Add/Remove\t\t3.Exit\n");
    int choice,choice2,choice3,d,b;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    printf("----------MENU----------\n");
    if(count==0){
    printf("You have not add dishes\n------------------------\n");
    goto main_page;
    }   
    for(int n=0;n<3;n++){
        
        int *size0 = (n == 0) ? &l : (n == 1) ? &o : &k;
        int sum_p=0,sum_n=0;
        printf("------------------------\n");
        if(n==0)
            printf("|\t%s\t|\n",category[n]);
        else if(n==1)
            printf("|      %s\t|\n",category[n]);              
        else
            printf("|       %s\t|\n",category[n]);
        printf("------------------------\n");//category
    for(int m=0;m<(*size0);m++){
            printf("----------\nName:%s\nPrice:%d\nQauntity:%d\nTaste:%s\n",(p[n]+m)->name,(p[n]+m)->price,(p[n]+m)->num,(p[n]+m)->taste);
            sum_p+=(((p[n]+m)->price)*((p[n]+m)->num));
            sum_n+=(p[n]+m)->num;//each dishes
        }
        printf("--------------------\n");
        printf("Total Price: %d\nTotal Quantity: %d\n",sum_p,sum_n);
        printf("--------------------\n");
      
    }//Menu fucntion
    int y;
    after_MENU:
    printf("\nYou want:\n1.Back to main page\t2.Add/remove\t3.change datas\n");
    scanf("%d",&y);
    switch (y)
    {
    case 1:
    goto main_page;
    break;//to main page
    case 2:
    goto update;
    break;//to update
    case 3:
    printf("Which kind of dish you want to edit\n");
        printf("1.staple\t\t2.cold dish\t\t3.hot dish\n");
        scanf("%d",&choice2);
        if((choice2==1&&l==0)||(choice2==2&&o==0)||(choice2==3&&k==0)){
        printf("ERROR\n");
        goto main_page;
        }
        
        switch (choice2)//update data
        {
        case 1:
            edit(0,l);
            break;
        case 2:
            edit(1,o);
            break;
        case 3:
            edit(2,k);
            break;
        default:
        printf("---------------------------\nPlease enter valid number\n---------------------------\n");
        goto after_MENU;
            break;
        }
    default:
    printf("---------------------------\nPlease enter valid number\n---------------------------\n");
    goto after_MENU;
        break;
    }//edit function
    
    
    case 2:
    update://update page
        printf("Which fuction?\n1.append\t2.remove\n");
        scanf("%d",&choice3);
        if(choice3==1){
            printf("How many dishes you want to add?\n");
            scanf("%d",&d);
            for(int i=0;i<d;i++){
                printf("The type of this dish:\n1.staple\t2.cold dish\t3.hot dish\n");
                scanf("%d",&b);
                switch(b){
                    case 1:pos=l,l++;break;
                    case 2:pos=o,o++;break;
                    case 3:pos=k,k++;break;
                default:
                    printf("please enter vaild number\n");
                    goto update;
                    break;
                }
                printf("\n--------------------\nEnter your %d dish:",i+1);
                scanf("%s",a[i].name);
                printf("--------------------\nprice: ");
                scanf("%d",&a[i].price);
                printf("\nquantity: ");
                scanf("%d",&a[i].num);
                printf("\ntaste: ");
                scanf("%s",a[i].taste);
                
    p[b-1][pos]=a[i];//a是大存储区，其他是小存储区
    count++;
            }
            printf("Add successfully\n");
            goto main_page;
    }
    
        else if(choice3==2){
            int e,f;
            printf("How many dishes you want to delete?\n");
            scanf("%d",&e);
            if(e>(l+o+k)){
                printf("ERROR\tThe number of delete is more than what we have now\n");
                goto update;
                }
            for(int i=0;i<e;i++){
            printf("What's the type of the dish %d?\n1.staple\t2.cold dish\t3.hot dish\n",i+1);
            scanf("%d",&f);
            if(f!=1&&f!=2&&f!=3){
                printf("please enter valid number\n");
                goto update;
            }
            else{
                int v;
                int *size = (f == 1) ? &l : (f == 2) ? &o : &k;
                for(int m=0;m<(*size);m++)
                {
                printf("%d.%s\n",m+1,(p[f-1]+m)->name);
                }
                printf("Which you would delete?\n");
                scanf("%d",&v);
                delete_item(f-1,v-1);
                printf("Delete successfully\n");
                goto main_page;
                }
           
            }
    }

    else{
       printf("---------------------------\nPlease enter valid number\n---------------------------\n");
        goto main_page;
    }
    
    
 //add/remove function
    case 3:
        printf("Looking forward to the next visit\n");
        return 0;//exit
        
    default:
        printf("---------------------------\nPlease enter valid number\n---------------------------\n");
        goto main_page;
    }//invalid number
}
