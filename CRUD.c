Program Code
#include<stdio.h>
#include<conio.h>
void add();
void update();
void del();
void search();
struct student
	{
	int id;
	int roll;
	int grade;
	char name[20];
	char gender[20];
	char stream[20];
	char section[20];
	char address[20];
	char email[50];
	int mobile[50];
	};
	
void main()
{
	int choice;
	while(choice!=5)
	{
		printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *       Welcome      *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n <*<*<* Student Record Management >*>*>* \n");
		printf("\n 1. Add \n");
		printf("\n 2.delete \n");
		printf("\n 3.search \n");
		printf("\n 4.update \n");
		scanf("%d",& choice);
		switch (choice)
		{
			case 1:
				add();
				break;
				
				case 2:
					del();
					printf("\n enter any key to continue\n");
					getch();
					break;
					
					case 3:
					search();
					printf("\n enter any key to continue \n");
					getch();
					break;
					
					case 4:
					update();
					printf("\n enter any key to continue \n");
					break;
				
				
		}
	}
}
void add()
{
	char a;
	FILE *fp;
	struct student add;
	do
	{
		system("cls");
		fp=fopen("std.txt","a");
		printf("\n enter roll:\t\t");
		scanf("%d",&add.roll);
		printf("\nenter name:\t\t");
		scanf("%s",&add.name);
		printf("\nEnter id:\t\t ");
        scanf("%d",&add.id);
        printf("\n Enter stream :\t\t ");
        scanf("%s",&add.stream);
        printf("\nEnter gender : ");
        scanf(" %s",&add.gender);
        printf("\nEnter grade :\t\t ");
        scanf("%d",&add.grade);
        printf("\nEnter section :\t\t ");
        scanf("%s",&add.section);
        printf("\nEnter address :\t\t ");
        scanf("%s",&add.address);
        printf("\nEnter email address :\t\t ");
        scanf("%s",&add.email);
        printf("\nEnter mobile no : \t\t");
        scanf("%d",&add.mobile);
        
		fwrite(&add,sizeof(struct student),1,fp);
		
		printf("\n Do you want more:\t");
		scanf(" %c",&a);
	}while(a=='y'|| a=='Y');
	fclose(fp);
}

void search()
{
	struct student search;
	int found=0;
	int roll;
	FILE *fp;
	fp=fopen("std.txt","r");
	printf("\n**<SEARCH STUDENT>**\n");
	printf("enter roll:\t");
	scanf("%d",&roll);
	while(fread(&search,sizeof(struct student),1,fp))
	{
		if(search.roll==roll)
		{
			found=1;
		printf("\n1. student name is %s",search.name);
		printf("\n2. student roll is %d",search.roll);
		printf("\n3. student id is %d",search.id);
		printf("\n4. student grade is %d",search.grade);
		printf("\n5. student mobile no is %d",search.mobile);
		printf("\n6. student email is %s",search.email);
		printf("\n7. student address is %s",search.address);
		printf("\n8. student gender is %s",search.gender);
		printf("\n9. student section is %s",search.section);
		printf("\n10. student stream is %s",search.stream);
		}
	}
	if(!found)
	{
		printf("\n \t................Record not found...............\n");
	}
}

void del()
{
	struct student del;
	FILE *fp ;
	FILE *fp1;
	fp=fopen("std.txt","r");
	fp1=fopen("temp.txt","w");
	int roll;
	int found=0;
	printf("\n enter roll:");
	scanf("%d",&roll);
	while(fread(&del,sizeof(struct student),1,fp))
	{
		if(del.roll==roll)
		{
			found=1;
		}
		else
		{
			fwrite(&del,sizeof(struct student),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found)
	{
		remove("std.txt");
		rename("temp.txt","std.txt");
		printf("\n<<**{~RECORD DELETE %d~}**>>\n",roll);
	}
	if(!found)
	{
		printf("\n \t\tRECORD NOT FOUND\t\t\n");
	}
}

void update()
{
    int roll, found=0;
    FILE *fp ,*fp1;
    
    struct student update;
    printf("UPDATE RECORD");
	printf("Enter roll of student to update: ");
    scanf("%d",&roll);
    fp = fopen("std.txt","r");
    fp1 = fopen ("temp.txt", "w"); 
	while(fread(&update,sizeof(struct student),1,fp))
    {
        if(update.roll==roll)
		{
		found=1;
		}
		else
		{
		fwrite(&update,sizeof( struct student),1,fp1);
    	}
        
	}
	if(found==1)
	{
		update.roll=roll;
		printf("\n\t\tEnter Name : \t\t");
	   	scanf("%s",&update.name);
     	printf("\n\t\tEnter id of student :\t\t ");
		scanf("%d",&update.id);
		printf("\n\t\tEnter grade of student : \t\t");
		scanf("%s",&update.grade);
		printf("\n\t\tEnter section of student : \t\t");
 		scanf("%s",&update.section);
		printf("\n\t\tEnter address of student : \t\t");
		scanf("%s",&update.address);
		printf("\n\t\tEnter email:\t\t");
		scanf("%s",&update.email);
		printf("\n\t\t Enter gender: \t\t");
 		scanf("%s",&update.gender);
 		printf("\n\t\tEnter stream of student : \t\t");
		scanf("%d",&update.stream);
			fwrite(&update,sizeof(struct student), 1, fp1);
	}

	fclose(fp);
    fclose(fp1);
	if(found==1)
    {
    	remove("std.txt");
    	rename("temp.txt","std.txt");
	}
    printf("\n Press any key to continue.\n ");
}

