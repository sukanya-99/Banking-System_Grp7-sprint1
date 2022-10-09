#include <stdio.h> //Include required header files
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pthread.h>
#include<time.h>
#include "../Header/Utility.h"
#include "../Header/Function.h"

int createAccount() //This function is to create an account

{
	char name[50];
	char aadhar_no[13];
	char customer_id[20];
	int len=0;
	char password[10];
	char account_type[5];
	double amount;
	new_acc = (customer *) malloc(sizeof(customer)); //Memory allocation for customer structure
	printf("\n\n Create Your Account\n");
	while(1)
	{
		printf("\nEnter Your Name:\n");
		fflush(stdin);
		scanf("%s",name);
		int len;
		int flag=0;
		for(int i=0;i<strlen(name);i++)
		{
			if(!isalpha(name[i])) //check() function is used to check whether the name is in number or alphabet, if number then it return 0
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("Invalid name!! Name should contain only alphabets\n");
			continue;
		}
		len=strlen(name);
		if(len<3||len>20) //Checks the length of the name, as it should not be less than 3 and greater than 20
		{
			printf("Invalid Length!! Length should not exceed 20 charecters\n");
			continue;
		}
		else
		{
			break;
		}
	}
		long int aadhar;
		int flag=0;
		while(1)
		{
			printf("\nEnter aadhar no:\n");
			scanf("%ld",&aadhar);
			for(ptr=start;(ptr);ptr=ptr->next)
			{
				if(ptr->aadhar_no==aadhar)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				printf("Already exist!!");
				return 0;
			}
			if(aadhar<100000000000 || aadhar>999999999999) //Checking the length of Aadhar number as it should be of 12 digits only else it will print invalid message
			{
				printf("\nInvalid Length!! Length should only of 12 digits.\n");
				continue;
			}


			else{
				break;
			}
		}
			sprintf(aadhar_no,"%ld",aadhar); //stores integer in string

//	printf("\nEnter your password: \n");
//	scanf("%s",password);
        char *pr=getpassword(); //storing password in pointer

	while(1)
	{
		//Taking input of account type
		printf("\nEnter your account type:\n");
	        scanf("%s",account_type);
		if((strcmp(account_type,"SB")==0) ||(strcmp(account_type,"CA")==0)) //To check account type. It should be SA or CA.
		{

			break;
		}
		else{
			printf("\nInvalid account type!!\n");
		     continue;
		}
	}

	while(1)
	{
		//Taking the input of amount
        	printf("\nEnter your amount:\n");
	        scanf("%lf",&amount);
			if((strcmp(account_type,"SB")==0 && amount<5000) || (strcmp(account_type,"CA")==0 && amount < 10000)) //Checking if Account type is SA and then amount should be greater than 5000 and if account type is CA then amount should be greater than 10000
			{
				printf("\nMinimum amount should not be less than 5000 SA and less than 10000 for CA\n");
				continue;
			}
			else
			{
				break;
			}
	}

       	strcpy(customer_id,account_type); //Copying account type in customer id
        strcat(customer_id,aadhar_no); //Concatenate customer id and addhar no

	strcpy(new_acc->name,name); // Storing local variable of name in pointer of customer structure
	strcpy(new_acc->customer_id,customer_id); //Storing  local customer_id in pointer of customer structure
	new_acc->aadhar_no=aadhar; //Typecasting and storing it in pointer
	strcpy(new_acc->password,pr); //storing password in pointer of customer structure
	strcpy(new_acc->account_type,account_type); //Storing accont type in pointer of customer structure
	new_acc->balance=amount; //storing amount in pointer

	printf("\nYour account is created successfully!!!!\n");
      customer_id[strlen(customer_id)]='\0';
        printf("\nThis is your customer id: %s\n",customer_id);
	if(!start)
	{
		start=new_acc;
		new_acc->next=NULL;
	}
	/*else if(strcmp(new_acc->customer_id, start->customer_id)<0)
	{
		new_acc->next=start;
		start=new_acc;
	}*/
	else
	{
		for(ptr=start;(ptr) &&(strcmp( ptr->customer_id, new_acc->customer_id)<0);prev= ptr ,ptr=ptr->next);
		prev->next=new_acc;
		new_acc->next=ptr;
	}
	printf("\n");
}

int viewBalance() //View balance of customer by accepting customer id
{
	if(!start) //checking if list is empty
	{
		printf("\nThere are no records in system\n");
		return(1);
	}
	char m_customer_id[20];
	printf("\nEnter Customer id:\n");
	scanf("%s",m_customer_id);
	for(ptr=start;(ptr) &&(strcmp( ptr->customer_id,m_customer_id)<0);ptr=ptr->next);
	if(strcmp(ptr->customer_id,m_customer_id)!=0) //if pointer id NULL then customer is not found
	{
		printf("\n %s Customer id not found\n",m_customer_id);
		return(1);
	}
	printf("\nBalance is %.2lf\n",ptr->balance);

}

int customer_file_to_list() //Inserting recrods from file to list
{
	FILE *fp;                                    //File  Pointer
	if((fp=fopen("Customer_File","rb")) == NULL) //Opening a binary file for reading
	{
		return (1);
	}
	new_acc = (customer *)calloc(1,sizeof(customer));        //Allocating Dynamic memory
	fread(new_acc,sizeof(customer),1,fp);                //reading file
	while(!feof(fp))
	{
		//after reading data from file , inserting into the linked list
		if(!start)
		{
			start=last=new_acc;
			new_acc->next=NULL;
		}
		else
		{
			last->next=new_acc;
			last=new_acc;
			new_acc->next=NULL;
		}
		new_acc=(customer *) calloc(1,sizeof(customer)); //Dynamically allocating memory
		fread(new_acc,sizeof(customer),1,fp);         //reading file
	}
}

int customer_list_to_file() //For inserting records in customer file from list
{
	FILE *fp;                                    //File pointer
	fp=fopen("Customer_File","wb");              //opening the binary file in write mode
	for(ptr=start; (ptr);ptr=ptr->next)
	{
		fwrite(ptr,sizeof(customer),1,fp);       //Writing in file
	}
	fclose(fp);                                 //closing the file
}

int getCustomerReport() //View customer report
{
	//after reading data from file ,inserting into the linked list
	if(!start)
	{
		printf("\nEmpty File...No records in file\n");
		return(1);
	}
	printf("\n--Customer Report--\n");
	printf("\n CUSTOMER_ID    AADHAR_NO      NAME    PASSWORD    ACCOUNT_TYPE     BALANCE\n\n");
	for(ptr=start;ptr;ptr=ptr->next)
	{
		printf("\n %s        %ld        %s         %s        %s         %8.21f \n",ptr->customer_id,ptr->aadhar_no,ptr->name,ptr->password,ptr->account_type,ptr->balance);
}

}

int editCustomer() //Edit the details of customer details with all validations
{
	char  m_customer_id[20];
	int flag=0;
	char name[30];
	char  m_account_type[10];
	char m_aadhar_no[15];

	printf("\nEnter the customer id\n");
	scanf("%s",m_customer_id);
	for(ptr=start; (ptr) &&(strcmp(ptr->customer_id,m_customer_id)!=0);ptr=ptr->next);


	if(!ptr)
	{
		printf("\n%d Customer id not found\n",m_customer_id);
		return(1);
	}
	printf("\nThe old customer name %s , account type %s and balance of customer id %s is %7.21f\n",ptr->name,ptr->account_type,ptr->customer_id,ptr->balance);

	while(1)

	{
		sprintf(m_aadhar_no,"%ld",ptr->aadhar_no);
		//Taking input of customer name
		printf("\nEnter Your Name:\n");
		fflush(stdin);
		scanf("%s",name);
		int len;
		int flag=0;
		for(int i=0;name[i]!='\0';i++)
		{
			if(!isalpha(name[i])) //isalpha() function is used to check if user gives numbers in name section then it will not accept the name
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("Invalid name.Name should contain only alphabets\n");
			continue;
		}
		len=strlen(name);
		if(len<3||len>20) //Checking that length of the name should be less than 20 and greater than 3
		{
			printf("Invalid Length.Length should not exceed 20 charecters\n");
			continue;
		}
		else
		{
			break;
		}
	}
	while(1) //edit account type
	{
		printf("\nEnter the new account type\n");
		scanf("%s",&m_account_type);
		if((strcmp(m_account_type,"SB")==0) || (strcmp(m_account_type,"CA")==0))
		{

			if(strcmp(m_account_type,"CA")==0)
			{
				if(ptr->balance<10000)
				{
					printf("\nMinimum account balance of CA should be more than Rs10000\n");
					continue;
				}
				else
				{
					strcpy(ptr->account_type,m_account_type);
					strcpy(ptr->customer_id,m_account_type);
					strcat(ptr->customer_id,m_aadhar_no);
					printf("New account type : %s",ptr->customer_id);

					break;
				}
			}
			else if(strcmp(m_account_type,"SA")==0)
			{

				strcpy(ptr->account_type,m_account_type);
				strcpy(ptr->customer_id,m_account_type);
				strcat(ptr->customer_id,m_aadhar_no);
				printf("\nNew account type : %s",ptr->customer_id);
				break;
			}
		}
		else
		{
			printf("\nInvalid account type\n");
			continue;
		}
	}
	strcpy(ptr->name,name);
}

int deleteCustomer() //Delete customer details
{
	if(!start)
	{
		printf("\nEmpty Records\n");
		return(1);
	}
	char  m_customer_id[20];
	printf("\nEnter the Customer id\n");
	scanf("%s",m_customer_id);
	if(strcmp(m_customer_id,start->customer_id)==0)
	{
		ptr=start;
		start=ptr->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) &&(strcmp (ptr->customer_id,m_customer_id)!=0);prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\n%s Customer id not found\n",m_customer_id);
			return(1);
		}
		printf("\nThe record of customer id %s deleted succesfully\n\n",ptr->customer_id);
		prev->next=ptr->next;
		free(ptr);
	}
}

int banker_file_to_list() //For insering records in list from banker file
{
	transact *last;         //last pointer
	FILE *fp;
	if((fp=fopen("Transaction_File","rb"))==NULL)  //Opening the binary file in read mode
	{
		printf("\nEmpty File...No records in file\n");
		return 1;
	}
	new1=(transact *)calloc(1,sizeof(transact)); //Dynamically allocating memory for new1 for bankers
	fread(new1,sizeof(transact),1,fp);     //reading file
	while(!feof(fp))
	{
		//after reading data from file inserting into linked list
		if(!start1)
		{
			start1=last=new1;
			new1->next=NULL;
		}
		else
		{
			last->next=new1;
			last=new1;
			new1->next=NULL;
		}
		new1=(transact *)calloc(1,sizeof(transact));
		fread(new1,sizeof(transact),1,fp);
	}
}

int banker_list_to_file()
{
	FILE *fp;                                  //File pointer
	fp=fopen("Transaction_File","wb");         //opening the binary file in write mode
	for(ptr1=start1;(ptr1);ptr1=ptr1->next)    //appending data at the end
	{
		fwrite(ptr1,sizeof(transact),1,fp);      //writing in file banker
	}
	fclose(fp);  //closing the file
}

int getTransactionReport() //display transaction report*
{

	if(!start1)
	{
		printf("Empty List\n");
		return(1);
	}
	printf("\n--Transaction Report--\n");
	printf("\n SOURCE   DESTINATION    AMOUNT\n\n");
	for(ptr1=start1;ptr1;ptr1=ptr1->next)
	{

		printf("\n %s         %s           %7.21f \n",ptr1->s_account,ptr1->d_account,ptr1->amount);
	}

}

