 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>

 void input();
 void writefile();
 void search();
 void output();

 struct date{
	   int month;
	   int day;
	   int year;
	   };

  struct account {
	int number;
	char name[100];
	int acct_no;
	float mobile_no;
	char street[100];
	char city[100];
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
  }customer;
  int tl,sl,ts;
 void main()
	{
	  int i,n,j,k,h,m,s;
	  FILE *fptr;
	  int r=0;
	  char c[30];
	  char a[30][30];
	  char ch;
	  system("cls");

printf("   CUSTOMER BILLING SYSTEM & BOOK AVAILABILITY CHECKING SYSTEM:\n\n");
printf("==================================================================\n");
printf("\n1:    To Add Account on list\n");
	  printf("2:    To search Customer Account\n");
	  printf("3:    Check Availability of Books\n");
	  printf("4:    Exit\n");
printf("\n=================================================================\n");
	  do{
	       printf("\nSelect an option:");
	       scanf(" %c",&ch);
	  }while(ch<='0' || ch>'4');
	  switch(ch){
		case '1':
			system("cls");
			printf("\nHow many customer accounts do you want to add?");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				input();
				customer.newbalance=customer.oldbalance - customer.payment;
			writefile();
			}
			main();
		case '2':
			system("cls");
			printf("Search Options:\n");
			printf("\n1 --- Search by Customer Number\n");
			printf("2 --- Search by Customer Name\n");
			search();
			main();
		case '3':system("cls");
		printf("WELCOME TO PUBLICATIONS!");
		printf("\nChecking availability:\n");

    	  	printf("\nEnter number of books you want to search:");
      		scanf("%d",&m);
  	    	for(j=0;j<m;j++)
      		{
     		printf("\nEnter book%d name:",j+1);
       		scanf("%s",a[j]);
       		}	
       		fptr=fopen("books.txt","r");
	        for(j=0;j<m;j++)

                       {
   	                      rewind(fptr);
                               while(!feof(fptr))
                               {
        		              fscanf(fptr,"%s\n",c);

				      if(strcmp(a[j],c)==0)
                        		{
                                       printf("\n%s is available",a[j]);
                                       r++;
                                       break;

                                       }
                                       }
                                       }
                 fclose(fptr);
                 if(m==r)
		 {
                  printf("\nAll books are available\n");
		 }
                 else
                 {
                 printf("\n%d are available,%d aren't available",r,m-r); }
printf("\nThank you!");
printf("\nIf wait is over,Press 1:");
scanf("%d",&s);
main();
		 		 
		case '4':
			system("cls");
		
			printf("\nA Project by Abhinav,Mounika & Rachana");
			
			exit(1);
	  }
 }


   void input()
	{
	  FILE *fp=fopen("test.txt","rb");
	  fseek (fp,0,SEEK_END);
	  tl=ftell(fp);
	  sl=sizeof(customer);
	  ts=tl/sl;
	  fseek(fp,(ts-1)*sl,SEEK_SET);
	  fread(&customer,sizeof(customer),1,fp);
	  printf("\ncustomer no:%d\n",++customer.number);
	  fclose(fp);
	  printf("         Account number:");
	  scanf("%d",&customer.acct_no);
	  printf("\n       Name:");
	  scanf("%s",customer.name);
	  printf("\n       Mobile no:");
	  scanf("%f",&customer.mobile_no);
	  printf("\n       Street:");
	  scanf("%s",customer.street);
	  printf("\n       City:");
	  scanf("%s",customer.city);
	  printf("\n       Previous balance:");
	  scanf("%f",&customer.oldbalance);
	  printf("\n       Current payment:");
	  scanf("%f",&customer.payment);
	  printf("\n       Payment date(mm/dd/yyyy):");
	  scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
	  return;
   }

   void writefile()
   {
	  FILE *fp;
	  fp=fopen("test.txt","ab");
	  fwrite(&customer,sizeof(customer),1,fp);
	  fclose(fp);
	  return;
   }

   void search()
   {
	 char ch;
	 char nam[100];
	 int n,i,m=1;
	 FILE *fp;
	 fp=fopen("test.txt","rb");
	 do{
		printf("\nEnter your choice:");
		scanf(" %c",&ch);
	 }while(ch!='1' && ch!='2');
	 switch(ch){
	      case '1':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    do{
			printf("\nEnter Customer Number:");
			scanf("%d",&n);
			if(n<=0 || n>ts)
			printf("\nEnter correctly!\n");
			else{
			    fseek(fp,(n-1)*sl,SEEK_SET);
			    fread(&customer,sl,1,fp);
			    output();
			}
			printf("\n\nAgain?(y/n)");
			scanf(" %c",&ch);
		    }while(ch=='y');
		    fclose(fp);
		    break;
	      case '2':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    fseek(fp,(ts-1)*sl,SEEK_SET);
		    fread(&customer,sizeof(customer),1,fp);
		    n=customer.number;

		    do{
			printf("\nEnter the name:");
			scanf("%s",nam);
			fseek(fp,0,SEEK_SET);
			for(i=1;i<=n;i++)
			{
			     fread(&customer,sizeof(customer),1,fp);
			     if(strcmp(customer.name,nam)==0)
			     {
				output();
				m=0;
				break;
			     }
			}
			if(m!=0)
			printf("\n\nDoesn't exist\n");
			printf("\nAnother?(y/n)");
			scanf(" %c",&ch);
		    }while(ch=='y');
		    fclose(fp);
	      }
	      return;
	 }



   void output()
	 {
	   printf("\n\nCustomer no    :%d\n",customer.number);
	   printf("    Name 	   :%s\n",customer.name);
	   printf("    Mobile no      :%.f\n",customer.mobile_no);
	   printf("    Account number :%d\n",customer.acct_no);
	   printf("    Street         :%s\n",customer.street);
	   printf("    City           :%s\n",customer.city);
	   printf("    Old balance    :%.2f\n",customer.oldbalance);
	   printf("    Current payment:%.2f\n",customer.payment);
	   printf("    New balance    :%.2f\n",customer.newbalance);
	   printf("    Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	   
	    return;
	 }

