#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "borders.h"
//Function prototypes
void getdoctor();       //To assign a doctor to a patient
void addPatient();      //To add a patient
void removePatient();   //To archive patient records
void menu();            //To output the main menu
void encrypt(char);     //To encrypt passwords
void login(); 			//To login
void billing();			//Billing Function
void borders(int);		//To select different types of borders in a single function
void addUser();			//Function to add users
//Function to add users
void addUser()
{
	char user[200],pass[200]
	borders(1);
	gotoxy(30,10);
	cout<<"Username: "
	gets()
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
	char pass[200],uname[200];
	gotoxy(30,10);
	cout<<"Enter username: ";
	gets(uname);
	gotoxy(30,12);
	cout<<"Enter password: ";
	pass = getpass();				
	strcpy(pass,encrypt(pass));		//Encrypts password
	ifstream file;
	file.open("uses.dat",ios::in|ios::bin);
	while(!
 }
 void main()
 {
  borders(1);
  login();
  getche();
 }