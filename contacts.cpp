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
	    printf("���������ѡ��\n");
	    int choice;
	    scanf("%d",&choice);
	    if(choice<0||choice>4)
	        printf("û�и�ѡ����������룺\n");
	    if(choice==4)
	    {
	        printf("лл����ʹ�ã��ټ���\n");
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
	printf("*******��ӭʹ��ͨѶ¼*******\n");
	printf("********1.�����ϵ��********\n");
	printf("********2.������ϵ��********\n");
	printf("********3.չʾ��ϵ��********\n");
	printf("********4.�˳�ͨѶ¼********\n");
	printf("****************************\n");
}

void addp()
{
	FILE *fp;
	char ch;
	char name1[NAME_LEN],num1[NUM_LEN];
	if((fp=fopen("phone.txt","a"))==NULL)
	{
		printf("�޷����ļ���\n");
		exit(1);
	}
    printf("�����������ͺ��룺\n");
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
		printf("�޷����ļ���\n");
		exit(1);
	}
	printf("������Ҫ���ҵ���ϵ�ˣ�\n");
	fscanf(stdin,"%s",name1);
	
	for(i=0;i<count;i++)
	{
		if(strcmp(name1,peoples[i].name)==0)
		{
			printf("%s�ĵ绰����Ϊ��%s\n",name1,peoples[i].num);
			return;
		}
	}
	printf("û���ҵ�����ϵ�ˡ�\n");
	fclose(fp);
}

void showp()
{
	FILE *fp;
	int i;
	if((fp=fopen("phone.txt","r"))==NULL)
	{
		printf("�޷����ļ���\n");
		exit(1);
	}
	printf("չʾ������ϵ��\n");
	printf("���\t\t\t\t����\t\t\t\t����\t\t\t\t\n");
	
	for(i=0;i<count;i++)
	{
		printf("%d\t\t\t\t%s\t\t\t\t%s\t\t\t\t\n",
		i,peoples[i].name,peoples[i].num);
	}
	printf("��ϵ��չʾ������\n");
	fclose(fp);
}

