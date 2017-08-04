#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "borders.h"
#include "sfun.h"
//*******************
//Function prototypes
//*******************
void getdoctor();       //To assign a doctor to a patient
void addPatient();      //To add a patient
void removePatient();   //To archive patient records
void main_menu();       //To output the main menu
void login(); 			//To login
void billing();			//Billing Function
void addUser();			//Function to add users
//***********
//User Class
//***********
class user
{
  char uname[200];
  char pass[200];
public:
  void input()
  {
	gotoxy(30,10);
	cout<<"Enter username: ";
	gets(uname);
	gotoxy(30,12);
	cout<<"Enter password: ";
	strcpy(pass,getpass());
	strcpy(pass,encrypt(pass));
  }
  int access(char ename[],char epass[])
  {
  	if(strcmp(epass,pass)==0 && strcmp(ename,uname)==0)
  		return 1;
  	else
  		return 0;
  }
};

//*************************
//Function to add users
//*************************
void addUser()
{
	user U;
	U.input();
	ofstream file;
	file.open("users.dat",ios::app|ios::binary);
	file.write((char*)&U,sizeof(U));
	file.close();
}
//****************
//Login Screen
//****************
void login()
{
	char uname[200],pass[200];
	login:
		borders();
		gotoxy(30,10);
		cout<<"Enter username: ";
		gets(uname);
		gotoxy(30,12);
		cout<<"Enter password: ";
		strcpy(pass,getpass());
		strcpy(pass,encrypt(pass));
		fstream file;
		file.open("users.dat",ios::in|ios::binary);
		user U;
		while(!file.eof())
		{
			file.read((char*)&U,sizeof(U));
			if(U.access(uname,pass))
			{
				main_menu();
			}
			else
				continue;
		}
	clrscr();
	borders();
	gotoxy(30,11);
	cout<<"Username & Password combination does not match";
	getche();
	clrscr();
	goto login;
}
//***********
//Main Menu
//***********
void main_menu()
{
	clrscr();
	borders();
	hr(5,'*');
	center("Main Menu",3);
	getche();
}
void main()
{
  borders();
  login();
  getche();
}