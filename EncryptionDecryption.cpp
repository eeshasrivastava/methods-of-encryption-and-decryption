#include<iostream>
#include <windows.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>

int x,y,n,phi,i,flag;
long int e[50], d[50], temp[50],j,m[50],en[50];
char msg[100];
int prime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

 HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
using namespace std;


void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

void fontsize(int a, int b){  
  PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
  lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
  GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
  lpConsoleCurrentFontEx->dwFontSize.X = a;  
  lpConsoleCurrentFontEx->dwFontSize.Y = b;  
  SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
 }  
 
 void welcome(){
 		HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE screen = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute(outcon, 0x0B);
	 fontsize(50, 50);  

    COORD max_size = GetLargestConsoleWindowSize( screen );

    char s[] = "WELCOME TO THE WORLD OF ENCRYPTION AND DECRYPTION";

    COORD pos;
    pos.X = (max_size.X - sizeof(s) ) / 2;
    pos.Y = max_size.Y / 2;
    SetConsoleCursorPosition( screen, pos );

    LPDWORD written;
    //WriteConsole( screen, s, sizeof(s), written, 0 );
	cout<<s<<endl;
 }
 int file(){
 	int i;
 	cout<<endl<<"Choose the type of input you want to give"<<endl<<endl;
 	cout<<"1.Through a String."<<endl<<"2.Through a local file in your system(.txt)."<<endl<<endl;
 	cout<<"Enter the option you want to choose : ";
 	cin>>i;
 	while(i>2){
	 
 	cout<<"Plz enter a valid option and try again : ";
	cin>>i;
	return i;
 	}
 }
 
 int type(){
 	int i;
 	cout<<"What you want to perform : "<<endl<<endl<<"1. Encryption"<<endl<<"2. Decryption"<<endl<<endl;
 	cout<<"Enter the option you want to choose : ";
 	cin>>i;
 	while(i>2){
	 
 	cout<<"Plz enter a valid option and try again : ";
	cin>>i;
}
	 return i;
 	
 }
 

void encryptDecrypt(char inpStr[])  //function used for encryption and decryption
{
    char xorKey='Q';      // Key for Encrytption using XOR encryption For Both 

    int len = strlen(inpStr);   //length of input string

    for (int i = 0; i < len; i++)
    {
        inpStr[i] = inpStr[i] ^ xorKey;
        printf("%c",inpStr[i]);
    }
}

int prime(long int pr)     //check whether the nubers are prime or not
{
	int i;
	int j= sqrt(pr);
	for(i=2;i<=j;i++)
	{
		if(pr%i==0)
		return 0;
	}
	return 1;
}
void encryption_key()  //fucntion to generate encyrption key 
{
	int k;
	k=0;
	for(i=2;i<phi;i++)
	{
		if(phi%i==0)
		continue;
		
		if(flag==1 && i!=x && i!=y)
		{
			e[k]=i;
			flag=cd(e[k]);
			if(flag>0)
			{
				d[k]=flag;
				k++;
			}
			if(k==99)
			break;
		}
	}
}
long int cd(long int a)
{
	long int k=1;
	while(1)
	{
		k=k+phi;
		if(k%a==0)
		return(k/a);
	}	
}



int en1(){
	
	char str[100];
   cout<<"\nPlease enter a string for Encryption : ";
   fflush(stdin);
   gets(str);
   for(int i=0;(i<100 && str[i]!='\0');i++)
   {
      str[i]=str[i]- (8 * 5 - 3);
   }
  printf("\nEncrypted string: %s\n", str);
 	return 0;
}
	

int en2(){
		char str[100];
   cout<<"\nPlease enter a string for Encryption : ";
   fflush(stdin);
   gets(str);
   for(int i=0;(i<100 && str[i]!='\0');i++)
   {
      str[i]=str[i]-28;
   }
  printf("\nEncrypted string: %s\n", str);
 	return 0;
	
}
int en3(){
	
	
		long int pt,ct,key= e[0],k,len;
	i=0;
	len=strlen(msg);
	while(i!=len)
	{
		pt=m[i];
		pt=pt-96;
		k=1;
		for(j=0;j<key;j++)
		{
			k=k*pt;
			k=k%n;
		}
		temp[i]=k;
		ct=k+96;
		en[i]=ct;
		i++;
	}
	en[i]=-1;
	printf("\n\n The encrypted message is: \n");
	for(i=0;en[i]!=-1;i++)
	printf("%c",en[i]);
	
}
int en4(){
	
	char inpString1[50];
    printf("\n\n Enter the string you want to encrypt: ");
    fflush(stdin);
    scanf("%[^\n]s",&inpString1);

    printf("\nEncrypted String: ");     //Encrypting the string
    fflush(stdin);
    encryptDecrypt(inpString1);
    printf("\n");
	
}

int dec1(){
	char str[100];
	cout<<"\nPlease enter a Encrypted string for Decrypt : ";
	 fflush(stdin);
   gets(str);
	for(int i=0;(i<100 && str[i]!='\0');i++)
	{   str[i]=str[i]+ (8 * 5 - 3);
    }
	printf("\nDecrypted string: %s\n", str);
}

int dec2(){
	char str[100];
	cout<<"\nPlease enter a Encrypted string for Decrypt : ";
	 fflush(stdin);
   gets(str);
	for(int i=0;(i<100 && str[i]!='\0');i++)
	{   str[i]=str[i]+28;
    }
	printf("\nDecrypted string: %s\n", str);
	
}
int dec3(){
char inpString1[50];
    printf("\n\n Enter the string you want to encrypt: ");
    fflush(stdin);
    scanf("%[^\n]s",&inpString1);

    printf("\n Decrypted String: ");     //Decrypting the string
    encryptDecrypt(inpString1);
    
    return 0;
	
}


int enc(){
	int i;
	cout<<"which algorithm you want to use to encryption:  "<<endl<<endl<<"1.Caesar Cipher Method(k1)"<<endl<<"2.Caesar Cipher Method(k2)"<<endl<<"3.RSA Method"<<endl<<"4.XOR Method"<<endl<<endl;
	cout<<"Enter the option you want to choose : ";
	cin>>i;
	while(i>4){
		cout<<"Plz enter a valid option and try again : ";
		cin>>i;
	}
	switch(i){
		case 1:
			en1();
			break;
		case 2:
			en2();
			break;
		case 3:
			x=7;
	y=13;
	flag=prime(x);
	if (flag==0)
	{
		printf("\n Invalid Input \n");
		exit(0);
	}
	flag=prime(y);
	if(flag==0||x==y)
	{
		printf("\n Invalid Number \n");
	}
	printf("\nEnter the message you want to encrypt:\n");
	fflush(stdin);
	scanf("%[^\n]s",&msg);
	for(i=0;msg[i]!=NULL;i++)
	 m[i]=msg[i];
	 n=x*y;
	 phi=(x-1)*(y-1);
	
	encryption_key();	
			en3();
			break;
		case 4:
			en4();
			break;
		
	}
	
	
}

int dec(){
	int i;
	cout<<"By which algorithm your data is encryption: "<<endl<<"1.Caesar Cipher Method(k1)"<<endl<<"2.Caesar Cipher Method(k2)"<<endl<<"3.XOR Method"<<endl<<endl;
	cout<<"Enter the option you want to choose : ";
	cin>>i;
	while(i>4){
		cout<<"Plz enter a valid option and try again : ";
		cin>>i;
	}
	switch(i){
		case 1:
			dec1();
			break;
		case 2:
			dec2();
			break;
		case 3:
			dec3();
			break;
	}
	
	
}
int Encrypt1();
int Decrypt2();
int Encryptview();
int Decryptview();

FILE *f1, *f2;
char ch;

fenc1(){
	 printf("\n");
    char file[30]; //to store the name of the file
    fflush(stdin);
    printf("Enter the file name with the extension .txt -> ");
    scanf("%[^\n]s",&file);
    f1=fopen(file,"r");
    if(f1==NULL)
    {
    	puts("FIle could not be found. Please check the name of the file again !");
	}
	f2=fopen("Encrypt.txt","w");
	if(f2==NULL)
		{
			puts("Target FILE is not found. Please check the name of the file again !");
		}
	while(1)
	{
		ch=fgetc(f1);
		if(ch==EOF)
		{
			printf("\nEncrypted Successfully\n");
			break;
		}
		else
		{
			ch=ch - (8 * 5 - 3);
			fputc(ch,f2);
		}
	}
	fclose(f1);
	fclose(f2);
	printf("\n");
	return 0;
	
}

fenc2(){
	printf("\n");
    char file[30]; //to store the name of the file
    fflush(stdin);
    printf("Enter the file name with the extension .txt -> ");
    scanf("%[^\n]s",&file);
    f1=fopen(file,"r");
    if(f1==NULL)
    {
    	puts("FIle could not be found. Please check the name of the file again !");
	}
	f2=fopen("Encrypt.txt","w");
	if(f2==NULL)
		{
			puts("Target FILE is not found. Please check the name of the file again !");
		}
	while(1)
	{
		ch=fgetc(f1);
		if(ch==EOF)
		{
			printf("\nEncrypted Successfully\n");
			break;
		}
		else
		{
			ch=ch - 28;
			fputc(ch,f2);
		}
	}
	fclose(f1);
	fclose(f2);
	printf("\n");
	return 0;

	
}

fdec1()
{
	
	 printf("\n");
    f1=fopen("Encrypt.txt","r");
    if(f1==NULL)
    {
    	puts("File could not be found. Please check the name of the file again !");
	}
	f2=fopen("Decrypt.txt","w");
	if(f2==NULL)
		{
			puts("FILE is not found. Please check the name of the file again !");
		}
	
	while(1)
	{
		ch=fgetc(f1);
		if(ch==EOF)
		{
			printf("\nDecrypted Successfully\n");
			break;
		}
		else
		{
			ch=ch+(8*5-3);
			fputc(ch,f2);
		}
	}
	fclose(f1);
	fclose(f2);
	printf("\n");
	return 0;}

fdec2()
{
	
 printf("\n");
    f1=fopen("Encrypt.txt","r");
    if(f1==NULL)
    {
    	puts("File could not be found. Please check the name of the file again !");
	}
	f2=fopen("Decrypt.txt","w");
	if(f2==NULL)
		{
			puts("FILE is not found. Please check the name of the file again !");
		}
	
	while(1)
	{
		ch=fgetc(f1);
		if(ch==EOF)
		{
			printf("\nDecrypted Successfully\n");
			break;
		}
		else
		{
			ch=ch+28;
			fputc(ch,f2);
		}
	}
	fclose(f1);
	fclose(f2);
	printf("\n");
	return 0;}

	int fenc(){
	int i;
	cout<<"which algorithm you want to use to encryption:  "<<endl<<endl<<"1.Caesar Cipher Method(k1)"<<endl<<"2.Caesar Cipher Method(k2)"<<endl<<endl;
	cout<<"Enter the option you want to choose : ";
	cin>>i;
	while(i>4){
		cout<<"Plz enter a valid option and try again : ";
		cin>>i;
	}
	switch(i){
		case 1:
			fenc1();
			break;
		case 2:
			fenc2();
			break;
	}
	
}

int fdec(){
	int i;
	cout<<"By which algorithm your data is encryption: "<<endl<<"1.Caesar Cipher Method(k1)"<<endl<<"2.Caesar Cipher Method(k2)"<<endl<<endl;
	cout<<"Enter the option you want to choose : ";
	cin>>i;
	while(i>4){
		cout<<"Plz enter a valid option and try again : ";
		cin>>i;
}
switch(i){
		case 1:
			fdec1();
			break;
		case 2:
			fdec2();
			break;
}
}
main(){
	
welcome();

delay(1.5);

cout<<endl<<endl<<endl<<endl<<endl<<endl<<("press any key to continue......");

getch();

system("cls");

fontsize(30,30);

int f=file();
system("cls");
int i=type();
system("cls");

if(f==1){
	if(i==1){
	enc();
	
}
	else {
		dec();
	}	
}

else{
	if(i==1){
	fenc();
}
	else {
	fdec();
	}	
}}
	




