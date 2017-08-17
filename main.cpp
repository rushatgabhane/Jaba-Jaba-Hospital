#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <windows.h>
#include "display.h"
#include "sfun.h"
//*****************
//Global Variables
//*****************
char* Departments[] = {"1.General Medicine","2.ENT","3.Pediatrics","4.Neurology","5.Gynacology","6.Opthamology","7.Dental"};
char* Mainmenu[] = {"1.New Admission","2.Search","3.Facilities","4.Billing","5.Reports","6.Patient Checkout","7.Exit"};
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
void facilities(int fac[]);      //Function To Display Facilities Offered
void ShowReport();      //Function To Display Patient Report
void exitprogram();     //Function asking to exit or play a game
void game();            //Function to Play a game
void facilities(int);      //Function To Display Facilities Offered
void ShowReport();        //Function To Display Patient Report
int searchPatient();

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
	int roomNo;
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
		facilities(fac);
	}
	/*void display()
	{
		createMenu("Patient Details");

	}*/
	int check(long cpr)
	{
		if(cpr==cprno)
		 return 1;
		else
		 return 0;
	}
	int check(char* name)
	{
		if(strcmpi(name,pname)==0)
			return 1;
		else
			return 0;
	}
};
//Search Patient Functions
int searchPatient()
{
	first_screen:

	char* pSearchMenu[]={"1.Search by Name","2.Search by CPR"};
	createMenu("Patient Search",pSearchMenu,sizeof(pSearchMenu)/4,4);
	
	center("Enter your option: ",15);
	int choice;
	cin>>choice;
	char* name;
	long cpr;
	switch(choice)
	{
		case 1:
			center("Enter name: ",21);
			gets(name);
			break;
		case 2:
			center("Enter CPR Number: ",21);
			cin>>cpr;
			break;
		default:
			errormsg("Invalid Option....");
			goto first_screen;
	}
  patient P;
  ifstream file;
  file.open("patients.dat",ios::in||ios::binary);
  while(!file.eof())
  {
	 file.read((char*)&P,sizeof(P));
    if(P.check(cpr) && choice==1)
	 {
		int point = file.tellg();
		file.close();
      return point;
	 }
    else if (P.check(name) && choice==2)
	 {
		int point = file.tellg();
		file.close();
    	return point;
	 }
  }
  file.close();
  return 0;
}
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
				errormsg("Incorrect username or password");
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
	createMenu("Main Menu",Mainmenu,sizeof(Mainmenu)/4,2);
	center("Enter Your Option:",21);

	int option;
	cin>>option;
	switch(option)
	{
	  case 1:
			addPatient();
			break;
	  case 2:
			/*
			int point = searchPatient();
			ifstream file;
			file.open("patients.dat",ios::in||ios::binary);
			*/

	  case 3:
			break;
	  case 4:
			billing();
			break;
	  case 5:
			ShowReport();
			break;
	  case 6:
			removePatient();
			break;
	  case 7:
			exitprogram();
			break;
	default:
			errormsg("Invalid Option...");
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
	file.open("patients.dat",ios::app||ios::binary);
	file.write((char*)&P,sizeof(P));
	file.close();

}
void facilities(int fac[])
{
first_screen:

  char* facilityMenu[]={"1.Departments","2.Lab","3.Rooms","4.Main Menu"};
  char* labMenu[]={"X-Ray","ECG","Ultrasound","MRI"};
  char* roomMenu[]={"Single AC Room","Single Non-AC Room","Double AC Room","Double Non-AC Room","Family Suite"};

  createMenu("FACILITIES",facilityMenu,sizeof(facilityMenu)/4);
  center("Enter Your Option:",17);

  int op;
  cin>>op;
  switch(op)
  {
	  case 1:	 createMenu("DEPARTMENTS",Departments,sizeof(Departments)/4,2);
			 center("Enter Your Option",19);
			 cin>>fac[1];
			 goto first_screen;

	  case 2:	 createMenu("LAB",labMenu,sizeof(labMenu)/4,2);
			 center("Enter Your Option",17);
			 cin>>fac[2];
			 goto first_screen;

	  case 3:	 createMenu("ROOMS",roomMenu,sizeof(roomMenu)/4,2);
			 center("Enter Your Option",17);
			 cin>>fac[3];
			 goto first_screen;

	  case 4:    main_menu();
			 break;

	  default:	 errormsg("Invalid Option");
			 goto first_screen;
  }
}
void billing()
{
	clrscr();
	borders();
	patient P;
	long cpr;
	gotoxy(22,7);
	cout<<"Enter CPR number to view the Bill ";
	cin>>cpr;
	ifstream file;
	file.open("users.dat",ios::in|ios::binary);
	while(!file.eof())
	{
		  file.read((char*)&P,sizeof(P));
		  if(P.check(cpr))
		  {
			 gotoxy(25,4);
			 cout<<"it worked";
		  }
		  else
		  {
			 errormsg("The entered CPR no. doesn't exist");
			 main_menu();
		  }
	}
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
void exitprogram()
{
	clrscr();
	borders();
	int op;
	gotoxy(25,8);
	cout<<"THANK YOU FOR USING THE PROGRAM";
	gotoxy(25,10);
	cout<<"Press 1 to confirm EXIT";
	gotoxy(25,11);
	cout<<"Press 2 to play a game!";
	gotoxy(25,13);
	cout<<"Enter your choice: ";
	cin>>op;
	switch(op)
	{
	  case 1:
		  exit(0);
	  case 2:
		  clrscr();
		  game();
	}
}

const int ml=80; //for game program
const int mt=5;  //for game program
const int mr=7;  //for game program

int letterFill (char, char[], char[]);
void Unknown (char[], char[]);

void game()
{
	char letter,unknown[ml],word[ml];
	int WrongGuess=0;
	char words[][ml] =
	{
		"india","bahrain","sweden","australia","germany",
		"russia","france","mexico","denmark","vietnam"
	};
	randomize();
	int n=random(10);
	strcpy(word,words[n]);
	Unknown(word, unknown);
	gotoxy(1,2);
	cout<<"Welcome to hangman";
	gotoxy(1,3);
	cout<<"Guess the country name";
	gotoxy(1,4);
	cout<<"You have 5 tries"<<endl;
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~";
	while (WrongGuess <mt)
	{
		gotoxy(1,6);
		cout<<endl<<endl<<unknown;
		gotoxy(1,7);
		cout<<"\n\nGuess a letter: ";
		cin>>letter;
		if (letterFill(letter, word, unknown)==0)
		{
			WrongGuess++;
			clrscr();
		}
		else
		{
			clrscr();
		}
		gotoxy(1,4);
		cout << "You have "<< (mt) - (WrongGuess)<<" guesses left"<<endl;
		if (strcmp(word,unknown)==0)
		{
			gotoxy(1,8);
			cout<<word<<endl;
			gotoxy(1,9);
			cout<<"You guessed it right!";
			exit(0);
			break;
		}
	 }
	  if(WrongGuess == mt)
	  {
			gotoxy(1,7);
			cout<<endl<<"You lose... you've been hanged." << endl;
			gotoxy(1,9);
			cout<<"The word was: "<<word<<endl;
			exit(0);
	 }
	 getch();
	 }
int letterFill (char guess, char secretword[], char guessword[])
{
	int matches=0;
	for (int i = 0; secretword[i]!='\0'; i++)
	{
		if (guess == guessword[i])
			return 0;
			if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
void Unknown (char word[], char unknown[])
{
	for (int i = 0; i<strlen(word) ; i++)
	  unknown[i]='*';
	  unknown[i]='\0';
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
