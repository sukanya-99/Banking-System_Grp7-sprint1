#include<stdio.h> // Include required header files
#include<ctype.h>
#include<stdlib.h>
#include<pthread.h>
#include"../Header/Utility.h"
#include"../Header/Function.h"
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER; //Initialize mutex
pthread_t thread_id; //Initialize thread id
int customerCorner()
{
	int choice=0;
	while(choice!=4)
	{

		//system("clear");

printf("\n\n\t\t\t\tCustomer Corner");
printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to Customer Facilities \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\t\t 1. Create Account\n\t\t 2. Do Transaction\n\t\t 3. View Balance\n\t\t 4. Back to Main Menu\n");
		printf("\n___________________\n\n");
		printf("\n   Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : createAccount(); // calls Create_Account from Function.c
				 break;
			case 2 : pthread_create(&thread_id,NULL,doTransaction,(void *)NULL); // starting a new thread in function calling process
				 pthread_join(thread_id,NULL); // this provides a mechanism allowing an application to wait for thread to terminate
				 break;
			case 3 : viewBalance();    // calls View_Balance from Function.c
				 break;
			case 4 : break;            //returns to main menu in The Banking System
			default : printf("\nInvalid Choice\n");
		}
	}
}

int bankerCorner()
{
	int choice=0;
	while(choice!=6)
	{
	   // system("clear");
printf("\n\n\t\t\t\tBanker's Corner");
printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to Banker's Corner \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\t\t 1. Edit Customer details\n\t\t 2. Delete Customer Details\n\t\t 3. Do Transfer\n\t\t 4. Get Transaction report\n\t\t 5. Get Customer Report\n\t\t 6. Back to Main Menu.\n");
		printf("\n_________________________\n\n");
		printf("\nEnter your Choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : editCustomer();   // calls Edit_Customer from Function.c
				 break;
			case 2 : deleteCustomer();  // calls Delete_Customer from Function.c
				 break;
			case 3 :pthread_create(&thread_id,NULL,doTransfer,(void *)NULL);// calls Do_Transfer from Function.c
			        pthread_join(thread_id,NULL);
				 break;
			case 4 : getTransactionReport();  // calls from Get_Transaction_Report from Function.c
				 break;
			case 5 : getCustomerReport(); // calls Get_Customer_Report from Function.c
				 break;
			case 6 : break;
			default : printf("\n Invalid Choice\n");
		}
	}
}
void *doTransaction()//allows user to withdraw and deposit amount
{
	int token,auto_token;
	time_t t1;
	int choice=0;
	double amount=0;
	char m_customer_id[20];
	double b_amount=0;
	printf("\nEnter\n1: Withdraw\n2. Deposit\n3. Back to menu\n");
	scanf("%d",&choice);
	if(choice==3)
		return 0;
	printf("\nEnter your Customer id\n");
	scanf("%s",m_customer_id);
	int flag=0;
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		if(strcmp(ptr->customer_id,m_customer_id)==0)
		{
		flag=1;
		break;
		}

	}
	if(flag==0)
	{
	printf("\n Customer ID  not found!!!\n");
			return 0;
	}
	srand((unsigned) time(&t1));//generates a random unique number for token
	auto_token=rand() % 50;
        pthread_mutex_lock(&lock); //release mutex object
	printf("\n Your token for current transaction is %d\n",auto_token);
	pthread_mutex_unlock(&lock); //lock a mutex object which identifies a mutex
	printf("\n PLEASE CONFIRM YOUR TOKEN\n");
	scanf("%d",&token);
	if(token==auto_token)//checks the token
	{

		if(choice==1)//withdraw option
		{
			for(ptr=start;(ptr)&&(strcmp(ptr->customer_id,m_customer_id)!=0);ptr=ptr->next);
			if(ptr==NULL)//checks if pointer is null then it will print id is not found else it will do transaction
			{
				printf("\n%s Customer id is not Found\n",m_customer_id);

				return 0;
			}
			else
			{
				printf("\nAvailable balance is: %7.2lf\n",ptr->balance);
				while(1)
				{
					printf("\nEnter Amount to withdraw:\n ");
					scanf("%lf",&amount);
					b_amount=ptr->balance-amount;


					if((strcmp(ptr->account_type,"SB")==0 && b_amount <5000) || (strcmp(ptr->account_type,"CA")==0 && b_amount < 10000)) //checks if account typr is SA then amount should be greater than 5000 and if account type is CA then amount should be greater than 10000.
					{
						printf("\nCannot Withdraw amount....Low Balance!!\n");
						break;
					}
					else if((strcmp(ptr->account_type,"SA")==0 && amount >50000) || ((strcmp(ptr->account_type,"CA")==0) && amount > 100000)) //check if account type is SA then amount should be less than 50000 and if account type is CA then amount should be less than 100000.
					{
						printf("\nAmount cannot be greater than 50000 for Savings Account and 100000 for Current Account\n");
						continue;
					}
					else
					{
						ptr->balance = ptr->balance-amount; //Storing transaction in pointer
						printf("\nCurrent Balance: %7.2lf\n",ptr->balance);
						printf("\nRs. %lf Withdrawn\n",amount);
						break;
					}
				}

			}
		}
		if(choice==2)//Deposit Option
		{
			for(ptr=start;(ptr)&&(strcmp(ptr->customer_id,m_customer_id)!=0);ptr=ptr->next);

				if(ptr==NULL) //checks if customer id is valid if not then it will print customer id not found
				{
					printf("\n%s Customer id not found\n",m_customer_id);

					return 0;
				}
				else
				{
					while(1)

					{
						printf("\nEnter Amount to deposit:\n ");
						scanf("%lf",&amount);
						if((strcmp(ptr->account_type,"SA")==0 && amount >50000) || ((strcmp(ptr->account_type,"CA")==0) && amount > 100000))//checks the condition if account type is SA then amount should be less than 50000 and if account type is CA then amount should be less than 100000
						{
							printf("\nAmount cannot be greater than 50000 for Savings Account and 100000 for Current Account\n");
							continue;
						}
						else
						{
							ptr->balance = ptr->balance+amount;//storing transaction in pointer
							printf("\nCurrent Balance: %7.2lf\n",ptr->balance);
							printf("\nRs. %lf Deposited\n",amount);
							break;
						}


					}
				}
			}

	}
	else
	{
		return 0;
	}
}

void *doTransfer()// Transfer money from one account to another account
{
	char s_account[20];
	char d_account[20];
	double amt;
	int token,auto_token;
	time_t t1;
	transact *new1=(transact *)malloc(sizeof(transact));//Dynamic memory allocation for transaction
	double amount=0,after_balance=0;
	int Banker_Pass=0;
	Banker_Pass=checkpassword(); //storing the password
	if(Banker_Pass==1)//checking the password and if its wroong it wiil print invalid password
	{
		printf("\nINVALID PASSWORD!!!\n");
		return 0;
	}
	else
	{

		printf("\n-------Transfor Money-------\n");


		printf("\nSource Account Customer ID-\n");
		scanf("%s",s_account);
		int flag=0;
		for(ptr=start;(ptr);ptr=ptr->next)
		{
			if(strcmp(ptr->customer_id,s_account)==0)
			{

				flag=1;
				break;

			}

		}
		if(flag==0)
		{
		printf("\nSource Account not Found!!!\n");
		return 0;
		}
		printf("\nDestination Account Number/Id\n");
		scanf("%s",d_account);
		flag=0;
		for(ptr=start;(ptr);ptr=ptr->next)
		{
			if(strcmp(ptr->customer_id,d_account)==0)
			{

				flag=1;
				break;
			}
		}
			if(flag==0){
				printf("\n Destination  account not found!!!\n");
				return 0;
			}
		printf("\nEnter Amount To Transfer\n");
		scanf("%lf",&amt);
		srand((unsigned) time(&t1)); //generates random unique token no
		auto_token=rand() % 50;
                pthread_mutex_lock(&lock); //lock mutex object

		printf("\n YOUR TOKEN FOR CURRENT TRANSACTION IS %d\n",auto_token);
                pthread_mutex_unlock(&lock); //release mutex object
		printf("\n PLEASE CONFIRM YOUR TOKEN\n");
		scanf("%d",&token);
		if(token==auto_token) //checks the token number
		{
			for(ptr=start;(ptr);ptr=ptr->next)
			{
				if((strcmp(ptr->customer_id,s_account)==0))
				{
					after_balance=ptr->balance-amt;
					while(1)
					{
						if((strcmp(ptr->account_type,"SB")==0 && after_balance<5000) || (strcmp(ptr->account_type,"CA")==0 && after_balance < 10000)) //checks if account type is SA then amount should be greater than 5000 and if account type is CA then amount should be greater than 10000
						{
							printf("Can't Transfer. You are at low balance\n");
							return 0;
						}

						if((strcmp(ptr->account_type,"SB")==0 && amt >50000) || (strcmp(ptr->account_type,"CA")==0 && amt > 100000)) //checks if account type is SA then amount should be less than 50000 and if account type is CA then amount should be less than 100000
						{
							printf("Amount cannot be greater than 50000 for Savings Account and 100000 for Current Account");
							continue;
						}
						else
						{
							printf("After deduction %7.2lf\n",after_balance);
							ptr->balance = ptr->balance-amt;//storing the amount in pointer
							printf("Rs. %lf Debited\n",amt);
							printf("Current Balance: %7.2lf\n",ptr->balance);
							break;
						}
					}

				}

				if(strcmp(ptr->customer_id,d_account)==0)
				{
					ptr->balance=ptr->balance+amt;//storing amount in pointer
					printf("Rs. %7.2lf credited to account\n",amt);
					printf("Your balance is Rs. %7.2lf\n",ptr->balance);
					//return 0;

				}
			}
		}
		else
		{
			printf("\n INVALID TOKEN!!!!!\n");
			return 0;
		}
		strcpy(new1->s_account,s_account);//storing local variable of source account  in structure variable to create linked list
		strcpy(new1->d_account,d_account);//storing local variable of destination account in structure variable to create linked list
		new1->amount=amt;
		if(!start1)//empty list
		{
			start1=new1;
			last1=new1;
			new1->next=NULL;


		}
		else
		{
			last1->next=new1;
			last1=new1;
			new1->next=NULL;

		}
		printf("\n");
	}
}

