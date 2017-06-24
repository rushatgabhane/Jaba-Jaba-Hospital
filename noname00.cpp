#include <iostream.h>
#include <stdio.h>
#include <conio.h>
<<<<<<< HEAD
//Function prototypes
void getdoctor();       //To assign a doctor to a patient
void addPatient();      //To add a patient
void removePatient();   //To archive patient records
void menu();            //To output the main menu
void encrypt();         //To encrypt passwords
void login(); 			//To login
void billing();			//Billing Function
void borders2(int)		//To select different types of borders in a single function

void borders()
 {
  	//Borders
	for(int j=0;j<81;j++)
	{
	 gotoxy(j,0);
	 cout<<'*';
	}
	for(int k=1;k<24;k++)
	{
	 gotoxy(0,k);
	 cout<<'*';
	}
	for(int m=0;m<81;m++)
	{
	 gotoxy(m,24);
	 cout<<'*';
	}
	for(int n=1;n<24;n++)
	{
	 gotoxy(81,n);
	 cout<<'*';
	}
	//Border End
 }
 void login() //Our first function
 {
 	borders();
	int i = 0;
	char pass[200],uname[200];

	gotoxy(30,10);
	cout<<"Enter username: ";
	gets(uname);
	gotoxy(30,12);
	cout<<"Enter password: ";
	while(1)  //stars out password
	{
		pass[i] = getch();
		if(pass[i]==13)
		{
		  pass[i]='\0';
		  break;
		}
		cout<<'*';
		i++;
	}
	pass[i]='\0';
   //Remove Output
	cout<<"\nThe Username:"<<uname;
   cout<<"\nThe Password:"<<pass;
 }
 void main()
 {
  borders();
  login();
  getche();
 }