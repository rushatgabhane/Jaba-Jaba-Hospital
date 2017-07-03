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
void menu();            //To output the main menu
void login(); 			//To login
void billing();			//Billing Function
void borders(int);		//To select different types of borders in a single function
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

//**********************
//Function to add users
//**********************
void addUser()
{
	user U;
	U.input();
	ofstream file;
	file.open("users.dat",ios::app|ios::binary);
	file.write((char*)&U,sizeof(U));
	file.close();
}
//********************
//Border selector
//********************
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
//****************
//Login Screen
//****************
void login()
{
	char uname[200],pass[200];
	borders(2);
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
			cout<<"access granted";
			break;
		}
		else
			continue;
	}
}

void main()
{
  borders(1);
  login();
  getche();
}