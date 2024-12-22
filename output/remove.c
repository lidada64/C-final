#include<stdio.h>
#define File "C:\\Users\\12281\\Desktop\\stash.txt"




void delete(int position){
     
    FILE *p=fopen(File,"r");
    fseek(p,position,SEEK_SET);//之前没有移动
    char ch;
    int current_pos=position;
    int seek=0;
   while ((ch = fgetc(p)) != EOF && ch != 'E'){//不能重复调用fgetc因为指针会向后移动两次
     int i=0;
     char line[100];
     if(ch=='>'){
          i++;
          printf("%d",i);
          printf("%s",fgets(line,100,p));
          current_pos=ftell(p);
     }//编号系统
        current_pos++;
        seek++;

   }
   
   int rm,num,a[100];
   printf("How many dished you want to remove? ");//加入批量删除功能
     scanf("%d",&num);
     printf("Which shall be remove? ");
     for(int j=0;j<num;j++){
          scanf("%d",&rm);
          printf("\nAnd then?\n");
          a[j]=rm;
     }
     printf("The number(s) of dish(es) you want to remove is(are): ");
     for (int j=0; j<num; j++)
     {
          printf("%d ",a[j]);
     }
     printf("\n");
   fseek(p,-seek,SEEK_CUR);//回到大类开头
   current_pos=ftell(p);//大类开头
   FILE *temp=fopen("temp.txt","a");
   while((ch=fgetc(p))!=EOF&&ch!='E'){
     int n=0;//
     
     if(ch=='>'){
          n++;
     for(int i=0;i<num;i++){//检测是否是指定的菜品
          if(a[i]==n){
               while(ch!='$'){
                    fseek(p,1,SEEK_CUR);
                    //跳过功能
          }
           fseek(p,1,SEEK_CUR);
          }
          else
               putc(ch,temp);
     }
    
     
   }
  
    
}
 while ((ch=fgetc(p))!=EOF)
     {
          putc(ch,temp);//把剩下的数据都复制给temp
          seek++;//记录从大类开头到文件结尾的位置
     }
fseek(p,-seek,SEEK_CUR);//指针移动到大类后面
char te;//记录temp文件的char
fseek(temp,0,SEEK_SET);//指针移动到临时文件的开头
while((te=fgetc(temp))!=EOF){
     fputc(te,p);
}
printf("Remove successfully");
fclose(p);
fclose(temp);
remove("temp.txt");
}