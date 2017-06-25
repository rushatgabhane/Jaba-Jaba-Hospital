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
void encrypt(char);     //To encrypt passwords
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
  void output()
  {
	gotoxy(30,10);
	cout<<"username: "<<uname;
	gotoxy(30,12);
	cout<<"password: "<<pass;
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
	borders(1);
	char pass[200],uname[200];
	gotoxy(30,10);
	cout<<"Enter username: ";
	gets(uname);
	gotoxy(30,12);
	cout<<"Enter password: ";
	strcpy(pass,getpass());
	strcpy(pass,encrypt(pass));		//Encrypts password
	ifstream file;
	file.open("uses.dat",ios::in|ios::binary);
	user U;
	int i=0;
	while(i<1)
	{
		file.read((char*)&U,sizeof(U));
		clrscr();
		simple('@');
		U.output();
		i++;
	}
 }
void main()
{
  borders(1);
  login();
  getche();
}