#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <windows.h>
#include "borders.h"
#include "sfun.h"

//*******************
//Function prototypes
//*******************
void getdoctor();       //To assign a doctor to a patient
void addPatient();      //To add a patient
void removePatient();   //To archive patient records
void main_menu();       //To output the main menu
void login(); 		    	//To login
void billing();			//Billing Function
void addUser();			//Function to add users
void facilities();      //Function To Display Facilities Offered
void ShowReport();        //Function To Display Patient Report;

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
///////////////////
//Patient Class
///////////////////
class patient
{
	char pname[200];
	long cprno,bill;
	int fac[];
public:
	void input()
	{
		center("Patient Name: ",15);
		gets(pname);
		center("CPR No: ",17);
		cin>>cprno;
		clrscr();
		borders();
		center("NEW ADMISSION",2);
		hr(4,'*');
		facilities();
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
		gotoxy(36,7);
		cout<<"LOGIN";
		gotoxy(30,10);
		cout<<"Enter username: ";
		gets(uname);
		gotoxy(30,12);
		cout<<"Enter password: ";
		strcpy(pass,getpass());
		strcpy(pass,encrypt(pass));
		ifstream file;
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
			{
				clrscr();
				borders();
				center("Username & Password combination does not match");
				center("Press any key to continue.....",17);
				getche();
				clrscr();
				goto login;
			}
		}
}
//***********
//Main Menu
//***********
void main_menu()
{
	menu:
	clrscr();
	borders();
	hr(5,'*');
	center("Main Menu",3);
	char option;
	center("1.New Admission",7);
	center("2.Search",9);
	center("3.Facilities",11);
	center("4.Billing",13);
	center("5.Reports",15);
	center("6.Patient Checkout",17);
	center("7.Exit",19);
	center("Enter Your Option:",21);
	option=getche();
	switch(option)
	{
	  case '1':
			addPatient();
			break;
	  case '2':

	  case '3':
			facilities();
			break;
	  case '4':
			billing();
			break;
	  case '5':
			ShowReport();
			break;
	  case '6':
			removePatient();
			break;
	  case '7':
			exit(0);
	  default:
			clrscr();
			borders();
			center("Invalid Option");
			center("Press any key to continue.....",17);
			getche();
			goto menu;

	}
}
//*******************
//Main Menu Functions
//*******************
void addPatient()
{
	clrscr();
	borders();
	center("NEW ADMISSION",2);
	hr(4,'*');
	patient P;
	P.input();
	ofstream file;
	file.open("patients.dat",ios::out||ios::binary);
	file.write((char*)&P,sizeof(P));
	file.close();

}
void facilities()
{
  clrscr();
  borders();
  first_screen:
  center("FACILITIES",2);
  hr(4,'*');
  center("1.Departments",7);
  center("2.Lab",10);
  center("3.Rooms",13);
  center("Enter Your Option:",17);
  char fac;
  fac=getche();
  switch(fac)
  {
	case '1':clrscr();
			 borders();
			 center("DEPARTMENTS",2);
			 hr(4,'*');
			 center("General Medicine",6);
			 center("ENT",18);
			 center("Pediatrics",8);
			 center("Neurology",10);
			 center("Gynacology",12);
			 center("Opthamology",14);
			 center("Dental",16);
			 center("Enter Your Option",17);
			 getche();
			 break;
	case '2':clrscr();
			 borders();
			 center("LAB",2);
			 hr(4,'*');
			 center("X-Ray",6);
			 center("ECG",8);
			 center("Ultrasound",10);
			 center("MRI",12);
			 getche();
			 break;
	case '3':clrscr();
			 borders();
			 center("ROOMS",2);
			 hr(4,'*');
			 center("Single AC Room",6);
			 center("Single Non-AC Room",8);
			 center("Double AC Room",10);
			 center("Double Non-AC Room",12);
			 center("Family Suite",14);
			 getche();
			 break;
	default:center("Invalid Option",18);
  }
}
void billing()
{
	clrscr();
	cout<<4;
}
void ShowReport()
{
	clrscr();
	cout<<5;
}
void removePatient()
{
	clrscr();
	cout<<6;
}
 //***********
//Main Function
//***********
void main()
{
  borders();
  login();
  getche();
}