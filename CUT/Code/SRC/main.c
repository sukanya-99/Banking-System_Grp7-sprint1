#include <stdio.h>   //Including required Header files
#include<stdlib.h>
#include "Function.h"
#include "Utility.h"
#include "Functions.c"
#include "Utilities.c"
#include "Password.c"
void gotoxy(int x, int y) // Sets co-ordinates in (x,y)
{
	printf("%c[%d;%df",0x2B,y,x);//-----
}
int main()               // This is the Main function.
{

	customer_file_to_list(); //Calling file to list function of customer corner
	start=ptr=last=prev=new_acc=NULL; //Declares all pointer of customer structure as NULL
	start1=last1=ptr1=new1=NULL; //Declares all pointer of transaction structure as NULL
	int choice=0;
	int Banker_pass=0;
	while(choice!=3)
	{
	        system("clear");

printf("\n\n\t\t\t\tBanking System");
printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to XYZ Bank \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\t\t 1. Customer Corner\n\t\t 2. Banker's Corner\n\t\t 3. Exit\n");
		printf("\n__________________________\n\n");
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: customerCorner();  // Calling Customer_Corner function
				break;
			case 2: Banker_pass=checkpassword(); // Check banker's password
				if(Banker_pass==1)
				{
					printf("\nINVALID PASSWORD!!\n");
					continue;
				}
				else
				{
					bankerCorner();  // Calling Banker_Corner function
				}
				break;
			case 3: break;
			default: printf("\nInvalid Choice\n");
		}
	}
	if(start)
		customer_list_to_file(); // Calling  the list to file function of customer corner

	if(start1)
		banker_list_to_file();  //Calling list to file  function for bankers corner

  system("read a");
}
