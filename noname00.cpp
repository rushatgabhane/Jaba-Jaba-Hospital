#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "borders.h"
//Function prototypes
void getdoctor();       //To assign a doctor to a patient
void addPatient();      //To add a patient
void removePatient();   //To archive patient records
void menu();            //To output the main menu
void encrypt(char);      //To encrypt passwords
void login(); 				//To login
void billing();			//Billing Function
void borders(int);		//To select different types of borders in a single function

char* encrypt(char pass[])
{
  int i=0;
  for(i=0;pass[i]!='\0';i++)
	 pass[i]+=strlen(pass);
  return pass;
}
void borders(int i)
{
	switch(i)
	{
	  case 1 : simple('*');
				  break;
	  case 2 : simple('#');
				  break;
	}
}	  //Border End
 void login() //Our first function
 {
	borders(1);
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
	clrscr();
	borders(2);
	gotoxy(30,10);
	cout<<"The Username:"<<uname;
	gotoxy(30,12);
	cout<<"The Password:"<<pass;
	gotoxy(30,14);
	strcpy(pass,encrypt(pass));
	cout<<"The Encrypted Pass: "<<pass;
 }
 void main()
 {
  borders(1);
  login();
  getche();
 }