#include<stdio.h>
#include<conio.h>

struct STUDENT
{
	int age,roll_no,prn,maths,physics,computational_science,total;
	int fundamental_programming;
	char name[20];
	float avg;

};

int main()
{

	void add();
    void displayAll();
	void record();
	void del();
	void marksheet();
	void modify();

	int i,count=0,a,n=0;
	/*printf("\n\t========================================================\n");
	printf("\t\t\t VIIT COLLEGE OF ENGINEERING,PUNE\n");
	printf("\n\t========================================================\n");
	printf("\n\t\t\t   STUDENT RECORD BOOK\n");
	printf("\n\t========================================================\n");*/

		while(1)
		{

        printf("\n\n\t\t\t\t========================================================\n");
        printf("\t\t\t\t\t VIIT COLLEGE OF ENGINEERING,PUNE\n");
        printf("\n\t\t\t\t========================================================\n");
        printf("\n\t\t\t\t\t\t   STUDENT RECORD BOOK\n");
        printf("\n\t\t\t\t========================================================\n");
		printf("\n\t\t\t\t------------------------------------------------------------");
		printf("\n\t\t\t\t\tChoose an option from below:");
		printf("\n\t\t\t\t------------------------------------------------------------");
		printf("\n\t\t\t\t\t\t1.Add a record");
		printf("\n\t\t\t\t\t\t2.Delete a record");
		printf("\n\t\t\t\t\t\t3.Modify a record");
		printf("\n\t\t\t\t\t\t4.Generate Mark Sheet");
		printf("\n\t\t\t\t\t\t5.Search a record");
		printf("\n\t\t\t\t\t\t6.Display all records");
		printf("\n\t\t\t\t\t\t7.exit");
		printf("\n\t\t\t\t------------------------------------------------------------\n");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
			{

				add();
				printf("\n\nPress any key to go to Main Menu..");
				system("cls");
			getch();
			system("cls");

				break;
			}
			case 2:
			{

				del();
				break;
			}
			case 3:
			{

				modify();
				break;
			}
			case 4:
			{
				marksheet();
				printf("\n\nPress any key to go to Main Menu..");
			getch();
				break;
			}
			case 5:
			{
				record();
				break;
			}
			case 6:
			{
				displayAll();
				break;
			}
			case 7:
			{
				exit(0);
			}

		}
	}
}

void add()
{


		system("cls");
		int i;
		struct STUDENT s;
		int size;
		FILE *fp;
		size=sizeof(s);
		fp=fopen("MINI_PROJECT_IN_C.DAT","ab");
 		printf("ENTER NAME:\n");
		scanf("%s",&s.name);
		printf("\nENTER ROLL NO. TO ADD:\n");
		scanf("%d",&s.roll_no);
		printf("\nENTER PRN NO. TO ADD:\n");
		scanf("%d",&s.prn);
		printf("\nENTER AGE:\n");
		scanf("%d",&s.age);
		printf("\nENTER MATHS MARKS:\n");
		scanf("%d",&s.maths);
		printf("ENTER PHYSICS MARKS:\n");
		scanf("%d",&s.physics);
		printf("ENTER COMPUTATIONAL SCIENCE MARKS:\n");
		scanf("%d",&s.computational_science);
		printf("ENTER FUNDAMENTAL PROGRAMMING MARKS:\n");
		scanf("%d",&s.fundamental_programming);

		s.total=s.maths+s.physics+s.computational_science+s.fundamental_programming;
		s.avg=s.total/4;
		fwrite(&s,size,1,fp);
		fclose(fp);
		printf("\nRecord Successfully Added");
		sleep(3);
}

void displayAll()
{
        system("cls");
        FILE *fp;
        struct STUDENT s;

        fp=fopen("MINI_PROJECT_IN_C.DAT","rb");

        printf("\n\t\t=================================================================================\n\n");
        printf("\t\t\t\t DETAILS OF ALL STUDENTS\n\n");
        printf("\t\t==================================================================================\n\n");


        while(1)
        {
        fread(&s,sizeof(s),1,fp);

        if(feof(fp))
        {
        break;
        }
        printf("\t\t\tNAME : %s\t\t",s.name);
		printf("\t\tROLL NO.: %d\n",s.roll_no);
        printf("\t\t\tPRN NO.: %d\t\t",s.prn);
		printf("\t\tAGE : %d\t\n\n",s.age);
		printf("\t\t\t\t--------------------------\n");
		printf("\t\t\t\t\t#MARKS#\n\n");
		printf("\t\t\t\t--------------------------\n");
		printf("\t\t\t\tPHYSICS:%d\t\n\n",s.physics);
		printf("\t\t\t\tCOMPUTATIONAL SCIENCE:%d\t\n\n",s.computational_science);
		printf("\t\t\t\tMATHS:%d\t\n\n",s.maths);
		printf("\t\t\t\tFUNDAMENTAL PROGRAMMING:%d\n\n",s.fundamental_programming);
		printf("\t\t-------------------------------------------------------------------------------\n\n");
		printf("\t\t\t\tTOTAL MARKS:%d\n\n",s.total);
		printf("\t\t\t\tAVERAGE:%f\n\n",s.avg);
	printf("\t\t===============================================================================\n\n");
	printf("\t\t===============================================================================\n\n");
}
	printf("************************************************************************************************************************\n\n");
    fclose(fp);
    printf("Enter any key to continue");
    sleep(3);



}

void record()
{
        system("cls");
        FILE *fp;
        struct STUDENT s;
        int id,found=0;
        fp=fopen("MINI_PROJECT_IN_C.DAT","rb");
        printf("\nEnter Roll no. of student:");
        scanf("%d",&id);
        while(1)
        {
        fread(&s,sizeof(s),1,fp);
        if(feof(fp))
        {
        break;
        }
        if(s.roll_no==id)
        {
        found=1;
        printf("\n\t\t===========================================================================\n\n");
        printf("\t\t\t\t Student Record of %s\n\n",s.name);
        printf("\t\t=============================================================================\n\n");

        printf("\t\t\tNAME : %s\t\t",s.name);
		printf("\t\tROLL NO.: %d\n",s.roll_no);
        printf("\t\t\tPRN NO.: %d\t\t",s.prn);
		printf("\t\tAGE : %d\t\n\n",s.age);
		printf("\t\t\t\t--------------------------\n");
		printf("\t\t\t\t\t#MARKS#\n\n");
		printf("\t\t\t\t--------------------------\n");
		printf("\t\t\t\tPHYSICS:%d\t\n\n",s.physics);
		printf("\t\t\t\tCOMPUTATIONAL SCIENCE:%d\t\n\n",s.computational_science);
		printf("\t\t\t\tMATHS:%d\t\n\n",s.maths);
		printf("\t\t\t\tFUNDAMENTAL PROGRAMMING:%d\n\n",s.fundamental_programming);
		printf("\t\t----------------------------------------------------------------------------\n\n");
		printf("\t\t\t\tTOTAL MARKS:%d\n\n",s.total);
		printf("\t\t\t\tAVERAGE:%f\n\n",s.avg);
	printf("\t\t===============================================================================\n\n");
	printf("==================================================================================================================\n\n");
}
}
        if(found==0)
        {
        printf("\nSorry No Record Found");
        }
fclose(fp);
}

void del()
{
        system("cls");
        FILE *fp,*fp1;
        struct STUDENT s,s1;
        int id,found=0;

        fp=fopen("MINI_PROJECT_IN_C.DAT","rb");
        fp1=fopen("temp.dat","wb");

        printf("\nEnter student roll no. you want to Delete: \n");
        scanf("%d",&id);
        while(1)
        {
        fread(&s,sizeof(s),1,fp);

        if(feof(fp))
        {
        break;
        }
        if(s.roll_no==id)
        {
        found=1;
        printf("\nRecord Deleted !!!!!!!!!!!!!!!!!!!\n\n");
        }
        else
        {
        fwrite(&s,sizeof(s),1,fp1);
        }
}
        fclose(fp);
        fclose(fp1);

        if(found==0)
        {
        printf("\nSorry No Record Found !!!!!!!!!!!!!!!!!!!1\n\n");
        }
        else
        {
        fp=fopen("MINI_PROJECT_IN_C.DAT","wb");
        fp1=fopen("temp.dat","rb");

        while(1)
        {
        fread(&s,sizeof(s),1,fp1);

        if(feof(fp1))
        {
        break;
        }
        fwrite(&s,sizeof(s),1,fp);
}
}
fclose(fp);
fclose(fp1);
}

void marksheet()
{
        system("cls");
        FILE *fp;
        struct STUDENT s;
        int id,found=0;
        fp=fopen("MINI_PROJECT_IN_C.DAT","rb");
        printf("\nEnter Roll no. of student:");
        scanf("%d",&id);
        while(1)
        {
        fread(&s,sizeof(s),1,fp);
        if(feof(fp))
        {
        break;
        }
        if(s.roll_no==id)
        {
        found=1;
          printf("\n\n\t\t\t\t===============================================================\n");
        printf("\t\t\t\t\t VIIT COLLEGE OF ENGINEERING,PUNE\n");
        //printf("\n\t\t\t\t========================================================\n");
        printf("\n\t\t\t\t===============================================================\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tStudent Marksheet of %s\n\n",s.name);
        printf("\t\t\t\t=================================================================\n\n");


		printf("\t\t\t\t\tNAME:%s\t\t",s.name);
		printf("\tROLL NO.:%d\t\t\n\n",s.roll_no);
		printf("\t\t\t\t\tPRN NO.:%d\t\t",s.prn);
		printf("\tAGE : %d\t\t\n\n",s.age);
		printf("\n\t\t\t\t\t\tMATHS                   :  %d\t\t\t\t\t\n\n",s.maths);
		printf("\t\t\t\t\t\tPHYSICS                 :  %d\t\t\t\t\t\n\n",s.physics);
		printf("\t\t\t\t\t\tCOMPUTATIONAL SCIENCE   :  %d\t\t\t\t\t\n\n",s.computational_science);
		printf("\t\t\t\t\t\tFUNDAMENTAL PROGRAMMING :  %d\n\n",s.fundamental_programming);
		printf("\t\t\t\t==============================================================\n");
		printf("\t\t\t\t\t\tTOTAL:%d\t\t",s.total);
		printf("AVERAGE:%2f\t\n",s.avg);

    printf("\t\t\t\t================================================================\n\n");
}
}
        if(found==0)
        {
        printf("\nSorry No Record Found");
        }
fclose(fp);

}


void modify()
{
        system("cls");
        FILE *fp,*fp1;
        struct STUDENT s;
        int id,found=0;

        fp=fopen("MINI_PROJECT_IN_C.DAT","rb");
        fp1=fopen("temp.dat","wb");

        printf("\nEnter student roll no you want to Modify : \n");
        scanf("%d",&id);

        while(1)
        {
        fread(&s,sizeof(s),1,fp);

        if(feof(fp))
        {
        break;
        }
        if(s.roll_no==id)
        {
        found=1;
		printf("\nENTER NEW ROLL NO.\n");
		scanf("%d",&s.roll_no);
		printf("\nENTER NEW PRN NO.:\n");
		scanf("%d",&s.prn);
		//fflush(stdin);
		printf("\nENTER NAME\n");
		scanf("%s",&s.name);
		printf("\nENTER AGE:\n");
		scanf("%d",&s.age);
		printf("\n\nENTER MATHS MARKS:\n");
		scanf("%d",&s.maths);
		printf("ENTER PHYSICS MARKS:\n");
		scanf("%d",&s.physics);
		printf("ENTER COMPUTATIONAL SCIENCE MARKS:\n");
		scanf("%d",&s.computational_science);
		printf("ENTER FUNDAMENTAL PROGRAMMING MARKS:\n");
		scanf("%d",&s.fundamental_programming);
		s.total=s.maths+s.physics+s.computational_science+s.fundamental_programming;
		s.avg=s.total/4;
		printf("\n\nRecord successfully modified...\n\n");
fwrite(&s,sizeof(s),1,fp1);

sleep(5);
}
        else
        {
        fwrite(&s,sizeof(s),1,fp1);
        }
}
fclose(fp);
fclose(fp1);

        if(found==0)
        {
        printf("Sorry No Record Found\n\n");
        }
        else
        {
        fp=fopen("MINI_PROJECT_IN_C.DAT","wb");
        fp1=fopen("temp.dat","rb");

        while(1)
        {
        fread(&s,sizeof(s),1,fp1);

        if(feof(fp1))
        {
        break;
        }
fwrite(&s,sizeof(s),1,fp);
}

}
fclose(fp);
fclose(fp1);
}
