#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int ide,pc,q,p,final;
void loading(int j);
void acc_details(int i);
void withdraw(int a);
void deposit(int a);
void transaction_fund(int i);
int main_menu(int w);
void acc_delete(int i);
void paybill(int a);
void mob_bal(int a);
void close(void);
int menu(int q,int p);
struct date{
	char datee[10];
};
struct data{
	int pincode,id,deposit,withdraw,bankbalance;
	char nationality[10],name[10],address[20],phoneno[12];
	struct date dob;
}d[100];
int main()
{
	int i,key,ide,a,pc,choice2;
	char choice,g;      
	FILE *fa;
	system("color 70");
		fa=fopen("data.txt","r");
        printf("\n\n\t\t\tWELCOME TO ATM MACHINE");
        printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PLEASE ENTER LOGIN DETAILS \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\t\tEnter your id: ");
		scanf("%d",&ide);
		printf("\n\t\tEnter your pincode: ");
		scanf("%d",&pc);

		for(i=1;i<1000;i++){
				fscanf(fa,"%d%s%s%s%s%d%d%d%d",&d[i].id,&d[i].name,&d[i].dob,&d[i].phoneno,&d[i].nationality,&d[i].pincode,&d[i].bankbalance,&d[i].deposit,&d[i].withdraw);
		if(i==ide)
			{
				if(pc==d[i].pincode)
				{
					fclose(fa);
					menu(ide,pc);
				}
			}
						}
	for(i=ide;i<1000;i++){
		if((i==ide && pc!=d[i].pincode) || (i!=ide && pc==d[i].pincode) || (i!=ide && pc!=d[i].pincode) ){
		   printf("\n\nWrong id or password!!\a\a\a");
            printf("\n\t\tEnter 1 to try again and 0 to exit:");
            scanf("%d",&final);
            if (final==1)
                    {
						fclose(fa);
                        system("cls");
                        main();
                    }
            else if (final==0)
                    {
                    	fclose(fa);
                    system("cls");
                    close();
					exit(1);
					}
            else
                    {printf("\nInvalid!");
                    loading(1000000000);
                    system("cls");
                }
        }
        return 0;
}
}
void acc_details(int i){	
	system("color F1");
	printf("\n\n\t\tID: %d",d[i].id);
	printf("\n\t\tName: %s",d[i].name);
	printf("\n\t\tDate of birth: %s",d[i].dob);
	printf("\n\t\tPhone number: %s",d[i].phoneno);
	printf("\n\t\tNationality: %s",d[i].nationality);
	printf("\n\t\tBank Balance: %d",d[i].bankbalance);
}
void deposit(int a){
	int dep,sum,tem,pc,i=1;
	FILE *fp,*fp2;
	 fp=fopen("data.txt","r");
     fp2=fopen("temp.txt","w");    
while(fscanf(fp,"%d%s%s%s%s%d%d%d%d",&d[i].id,&d[i].name,&d[i].dob,&d[i].phoneno,&d[i].nationality,&d[i].pincode,&d[i].bankbalance,&d[i].deposit,&d[i].withdraw)!=EOF)
{
  if(a==d[i].id){
	tem=d[i].deposit;
	d[i].deposit=0;
		printf("\n\t\tENTER THE AMOUNT YOU WANT TO DEPOSIT:");
	scanf("%d",&dep);
	d[i].deposit=dep;
	d[i].bankbalance+=d[i].deposit;	
	fprintf(fp2,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[i].id,d[i].name,d[i].dob,d[i].phoneno,d[i].nationality,d[i].pincode,d[i].bankbalance,d[i].deposit,d[i].withdraw);
}else{
	fprintf(fp2,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[i].id,d[i].name,d[i].dob,d[i].phoneno,d[i].nationality,d[i].pincode,d[i].bankbalance,d[i].deposit,d[i].withdraw);
}
    i++;
}
	fclose(fp2);
	fclose(fp);
	remove("data.txt");
	rename("temp.txt","data.txt");
}
void withdraw(int a){
	int withdraw,sum,tem,pc,i=1;
	FILE *fp,*fp2;
	 fp=fopen("data.txt","r");
     fp2=fopen("temp.txt","w");   
while(fscanf(fp,"%d%s%s%s%s%d%d%d%d",&d[i].id,&d[i].name,&d[i].dob,&d[i].phoneno,&d[i].nationality,&d[i].pincode,&d[i].bankbalance,&d[i].deposit,&d[i].withdraw)!=EOF)
{
  if(a==d[i].id){
	tem=d[i].withdraw;
	d[i].withdraw=0;
	printf("\n\t\tENTER THE AMOUNT YOU WANT TO WITHDRAW:");
	scanf("%d",&withdraw);
	d[i].withdraw=withdraw;
	d[i].bankbalance=d[i].bankbalance-d[i].withdraw;

	fprintf(fp2,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[i].id,d[i].name,d[i].dob,d[i].phoneno,d[i].nationality,d[i].pincode,d[i].bankbalance,d[i].deposit,d[i].withdraw);
}
else{
	fprintf(fp2,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[i].id,d[i].name,d[i].dob,d[i].phoneno,d[i].nationality,d[i].pincode,d[i].bankbalance,d[i].deposit,d[i].withdraw);
}
    i++;
}
	fclose(fp2);
	fclose(fp);
	remove("data.txt");
	rename("temp.txt","data.txt");				
}
void paybill(int a){
	int withdraw,sum,tem,pc,i=1;
	FILE *fp,*fp2;
	 fp=fopen("data.txt","r");
     fp2=fopen("temp.txt","w");
while(fscanf(fp,"%d%s%s%s%s%d%d%d%d",&d[i].id,&d[i].name,&d[i].dob,&d[i].phoneno,&d[i].nationality,&d[i].pincode,&d[i].bankbalance,&d[i].deposit,&d[i].withdraw)!=EOF)
{
  if(a==d[i].id){
	tem=d[i].withdraw;
	d[i].withdraw=0;
	printf("\n\t\tENTER THE PAYMENT:");
	scanf("%d",&withdraw);
	d[i].withdraw=withdraw;
	d[i].bankbalance-=d[i].withdraw;
	fprintf(fp2,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[i].id,d[i].name,d[i].dob,d[i].phoneno,d[i].nationality,d[i].pincode,d[i].bankbalance,d[i].deposit,d[i].withdraw);
}
else{
	fprintf(fp2,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[i].id,d[i].name,d[i].dob,d[i].phoneno,d[i].nationality,d[i].pincode,d[i].bankbalance,d[i].deposit,d[i].withdraw);
}
    i++;
}
	fclose(fp2);
	fclose(fp);
	remove("data.txt");
	rename("temp.txt","data.txt");				
}
void mob_bal(int a){
	int withdraw,sum,tem,pc,i=1;
	FILE *fp,*fp2;
	 fp=fopen("data.txt","r");
     fp2=fopen("temp.txt","w");    
while(fscanf(fp,"%d%s%s%s%s%d%d%d%d",&d[i].id,&d[i].name,&d[i].dob,&d[i].phoneno,&d[i].nationality,&d[i].pincode,&d[i].bankbalance,&d[i].deposit,&d[i].withdraw)!=EOF)
{
  if(a==d[i].id){ 
  printf("\n\t\tYour mobile no: %s", d[i].phoneno);
	tem=d[i].withdraw;
	d[i].withdraw=0;
	printf("\n\t\tENTER AMOUNT OF BALANCE RECHARGE:");
	scanf("%d",&withdraw);
	d[i].withdraw=withdraw;
	d[i].bankbalance-=d[i].withdraw;

	fprintf(fp2,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[i].id,d[i].name,d[i].dob,d[i].phoneno,d[i].nationality,d[i].pincode,d[i].bankbalance,d[i].deposit,d[i].withdraw);
}
else{
	fprintf(fp2,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[i].id,d[i].name,d[i].dob,d[i].phoneno,d[i].nationality,d[i].pincode,d[i].bankbalance,d[i].deposit,d[i].withdraw);
}
    i++;
}
	fclose(fp2);
	fclose(fp);
	remove("data.txt");
	rename("temp.txt","data.txt");				


}
void loading(int j){   
int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void transaction_fund(int i){
	int r,amnt,a=1,tem;
	system("cls");
	printf("\n\n\t\t\tW E L C O M E");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BROCODE ATM MACHINE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\tENTER ID WHERE YOU WANT TO TRANSFER FUNDS");
	scanf("%d",&r);
	FILE *fa,*fb;
	fa=fopen("data.txt","r");
	fb=fopen("temp.txt","w");
while(fscanf(fa,"%d%s%s%s%s%d%d%d%d",&d[a].id,&d[a].name,&d[a].dob,&d[a].phoneno,&d[a].nationality,&d[a].pincode,&d[a].bankbalance,&d[a].deposit,&d[a].withdraw)!=EOF)
{
  if(i==d[a].id){
	tem=d[a].withdraw;
	d[a].withdraw=0;
	printf("\n\t\tEnter the amount you want to send..");
	scanf("%d",&amnt);
	d[a].withdraw=amnt;
	d[a].bankbalance=d[a].bankbalance-d[a].withdraw;
	fprintf(fb,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[a].id,d[a].name,d[a].dob,d[a].phoneno,d[a].nationality,d[a].pincode,d[a].bankbalance,d[a].deposit,d[a].withdraw);
}else{
	fprintf(fb,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[a].id,d[a].name,d[a].dob,d[a].phoneno,d[a].nationality,d[a].pincode,d[a].bankbalance,d[a].deposit,d[a].withdraw);
}
    a++;
}
	fclose(fa);
	fclose(fb);
	remove("data.txt");
	
	rename("temp.txt","data.txt");
	FILE *ff,*fs;
	ff=fopen("data.txt","r");
	fs=fopen("temp.txt","w");
a=1;				
while(fscanf(ff,"%d%s%s%s%s%d%d%d%d",&d[a].id,&d[a].name,&d[a].dob,&d[a].phoneno,&d[a].nationality,&d[a].pincode,&d[a].bankbalance,&d[a].deposit,&d[a].withdraw)!=EOF)
{
  if(r==d[a].id){
	tem=d[a].deposit;
	d[a].deposit=0;
	d[a].deposit=amnt;
	d[a].bankbalance+=d[a].deposit;
	fprintf(fs,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[a].id,d[a].name,d[a].dob,d[a].phoneno,d[a].nationality,d[a].pincode,d[a].bankbalance,d[a].deposit,d[a].withdraw);
}else{
	fprintf(fs,"\n%d%10s%10s%15s%10s%10d%10d%10d%10d",d[a].id,d[a].name,d[a].dob,d[a].phoneno,d[a].nationality,d[a].pincode,d[a].bankbalance,d[a].deposit,d[a].withdraw);
}
    a++;
}
	fclose(fs);
	fclose(ff);
	remove("data.txt");
	rename("temp.txt","data.txt");
}
int menu(int q, int p )
{
	int i,w,choice2;
	FILE *fp,*fa;
	char g;      
	fa=fopen("data.txt","r");
	system("color 70");
						printf("\n\n\t\tWait a second!\n\n\t\tLOADING YOUR ACCOUNT");
                        for(i=0;i<=6;i++)
                        {
                        loading(100000000);
                        printf(".");
                        }
					system("cls");
					system("color 75");
					printf("\n\n\t\t\tW E L C O M E");
                    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BROCODE ATM MACHINE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 1.Your account details\n\t\t\t\xDB\xDB\xDB\xDB\xB2 2.For Deposit\n\t\t\t\xDB\xDB\xDB\xDB\xB2 3.For Withdraw\n\t\t\t\xDB\xDB\xDB\xDB\xB2 4.For Bill Payment\n\t\t\t\xDB\xDB\xDB\xDB\xB2 5.For Fund Transfer\n\t\t\t\xDB\xDB\xDB\xDB\xB2 6.Mobile Recharge\n\t\t\t\xDB\xDB\xDB\xDB\xB2 7.Exit");
                    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					t();
					printf("\n\t\t\t Enter your choice: ");
					scanf("%d",&choice2);
					switch(choice2)
					{
						case 1:
							system("cls"); 
						    printf("\n\n\t\t\tW E L C O M E");
                    		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BROCODE ATM MACHINE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
							
							acc_details(q);
							fclose(fa);
							printf("\n\n\t\t1.Main Menu\n\t\t2.Exit");
							printf("\n\t\tEnter choice");
							scanf("%d", &w);
							if (w==1){
								menu(q,p);
							}
							else if(w==2){
								close();
							}
							else{
								printf("\n\t\tINVALID CHOICE ENTERED");
							}
						break;			
						case 2:

							system("cls");
							printf("\n\n\t\t\tW E L C O M E");
                    		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BROCODE ATM MACHINE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
							fclose(fa);
							deposit(q);
							for(i=0;i<=6;i++)
                        	{
                        	loading(100000000);
                        	printf("\n\t\t.");
                        	}
                        	printf("\n\n\t\tPlease collect your slip! Thankyou");
                        	printf("\n\n\t\t1.Main Menu\n\t\t2.Exit");
							printf("\n\t\tEnter choice");
							scanf("%d", &w);
							if (w==1){
								menu(q,p);
							}
							else if(w==2){
								close();
							}
							else{
								printf("\n\t\tINVALID CHOICE ENTERED");
							}
                        	break;
						case 3:
							system("cls");
							printf("\n\n\t\t\tW E L C O M E");
                    		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BROCODE ATM MACHINE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		                	fclose(fa);
							withdraw(q);			
		                	for(i=0;i<=6;i++)
                        	{
                        	loading(100000000);
                        	printf("\n\t\t.");
                        	}
                        	printf("\n\n\t\tPlease collect your slip! Thankyou");
                        	printf("\n\n\t\t1.Main Menu\n\t\t2.Exit");
							printf("\n\t\tEnter choice");
							scanf("%d", &w);
							if (w==1){
								menu(q,p);
							}
							else if(w==2){
								close();
							}
							else{
								printf("\n\t\tINVALID CHOICE ENTERED");
							}
			            	break;	
						case 4:
							system("cls");
							printf("\n\n\t\t\tW E L C O M E");
                    		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BROCODE ATM MACHINE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
							printf("\n\t\t1:Electricity Bills\n\t\t2:Water Bills\n\t\t3:Gas bills\n");
							fclose(fa);
							paybill(q);
							for(i=0;i<=6;i++)
                        	{
                        	loading(100000000);
                        	printf("\n\t\t.");
                        	}
							printf("\n\n\t\t""BILL PAYMENT SUCCESSFULL!");
                        	printf("\n\t\tPlease collect your slip! Thankyou");
                        	printf("\n\n\t\t1.Main Menu\n\t\t2.Exit");
							printf("\n\t\tEnter choice");
							scanf("%d", &w);
							if (w==1){
								menu(q,p);
							}
							else if(w==2){
								close();
							}
							else{
								printf("\n\t\tINVALID CHOICE ENTERED");
							}
                        	break;
						case 5:
							system("cls");
							fclose(fa);
							transaction_fund(q);
							for(i=0;i<=6;i++)
                        	{
                        	loading(100000000);
                        	printf("\n\t\t.");
                        	}
							printf("\n\n\t\t""FUND TRANSFER SUCCESSFULL!");
							printf("\n\n\t\t1.Main Menu\n\t\t2.Exit");
							printf("\n\t\tEnter choice");
							scanf("%d", &w);
							if (w==1){
								menu(q,p);
							}
							else if(w==2){
								close();
							}
							else{
								printf("\n\t\tINVALID CHOICE ENTERED");
							}
							break;						
						case 6:
							system("cls");
							printf("\n\n\t\t\tW E L C O M E");
                    		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BROCODE ATM MACHINE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
							fclose(fa);
							mob_bal(q);
							for(i=0;i<=6;i++)
                        	{
                        	loading(100000000);
                        	printf("\n\t\t.");
                        	}
                        	printf("\n\t\tBalance recharged successfully\n");
                        	printf("\n\n\t\t1.Main Menu\n\t\t2.Exit");
							printf("\n\t\tEnter choice");
							scanf("%d", &w);
							if (w==1){
								menu(q,p);
							}
							else if(w==2){
								close();
							}
							else{
								printf("\n\t\tINVALID CHOICE ENTERED");
							}
                        	break;
                        case 7: 
                            fclose(fa);
							close();
                            
                            break;
						default:
							fclose(fa);
							printf("\nWRONG INPUT....");
							for(i=0;i<=6;i++)
                        	{
                        	loading(100000000);
                        	printf(".");
                        	}
                        	system("cls");
							printf("\n\n\t\t1.Reset choice?\n\t\t2.Exit");
							printf("\n\t\tEnter choice");
							scanf("%d", &w);
							if (w==1){
								menu(q,p);
							}
							else if(w==2){
								close();
							}
							else{
								printf("\n\t\tINVALID CHOICE ENTERED");
							}
							break; 
					}
				}
void close(void)
{
	system("cls");
    printf("\n\n\n\n\t\tATM PROJECT PRESENTED TO YOU BY BROCODE!");
    }
    
int t(void) 
{
time_t t;
time(&t);
printf("\n\t\t\tDate and time%s\n",ctime(&t));
}                                                                                                                                                                                                                                                                             
