#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_LEN 80
#define NUM_LEN 80
#define MAX_LEN 100

struct person
{
	char name[NAME_LEN];
	char num[NUM_LEN];
};
struct person peoples[MAX_LEN];
int count=0;

void menu();
void addp();
void searchp();
void showp();
 
int main()
{
    while(1)
	{
		menu();
	    printf("请输入你的选择：\n");
	    int choice;
	    scanf("%d",&choice);
	    if(choice<0||choice>4)
	        printf("没有该选项，请重新输入：\n");
	    if(choice==4)
	    {
	        printf("谢谢您的使用，再见！\n");
            exit(0);
	    }
	    switch(choice)
	    {
		    case 1:addp();
			    break;
		    case 2:searchp();
		        break;
		    case 3:showp();
		        break;
		    default:
			    break;
	    }
    }
	return 0;
}

void menu()
{
	printf("****************************\n");
	printf("*******欢迎使用通讯录*******\n");
	printf("********1.添加联系人********\n");
	printf("********2.查找联系人********\n");
	printf("********3.展示联系人********\n");
	printf("********4.退出通讯录********\n");
	printf("****************************\n");
}

void addp()
{
	FILE *fp;
	char ch;
	char name1[NAME_LEN],num1[NUM_LEN];
	if((fp=fopen("phone.txt","a"))==NULL)
	{
		printf("无法打开文件！\n");
		exit(1);
	}
    printf("请输入姓名和号码：\n");
	scanf("%s%s",name1,num1);
    strcpy(peoples[count].name,name1);
    strcpy(peoples[count].num,num1);
    count++;
    fwrite(&count,sizeof(int),1,fp);
    fwrite(&peoples[count], sizeof(struct person), 1, fp);
	fclose(fp);
}

void searchp()
{
	FILE *fp;
	int i;
	char name1[NAME_LEN];
	
	if((fp=fopen("phone.txt","r"))==NULL)
	{
		printf("无法打开文件！\n");
		exit(1);
	}
	printf("请输入要查找的联系人：\n");
	fscanf(stdin,"%s",name1);
	
	for(i=0;i<count;i++)
	{
		if(strcmp(name1,peoples[i].name)==0)
		{
			printf("%s的电话号码为：%s\n",name1,peoples[i].num);
			return;
		}
	}
	printf("没有找到该联系人。\n");
	fclose(fp);
}

void showp()
{
	FILE *fp;
	int i;
	if((fp=fopen("phone.txt","r"))==NULL)
	{
		printf("无法打开文件！\n");
		exit(1);
	}
	printf("展示所有联系人\n");
	printf("序号\t\t\t\t姓名\t\t\t\t号码\t\t\t\t\n");
	
	for(i=0;i<count;i++)
	{
		printf("%d\t\t\t\t%s\t\t\t\t%s\t\t\t\t\n",
		i,peoples[i].name,peoples[i].num);
	}
	printf("联系人展示结束。\n");
	fclose(fp);
}

