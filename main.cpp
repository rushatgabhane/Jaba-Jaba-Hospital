#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
//*****************
//Special Functions
//*****************
//Encrypt function
char* encrypt(char pass[])
{
  int i=0;
  for(i=0;pass[i]!='\0';i++)
   pass[i]+=strlen(pass);
  return pass;
}

//Function to get password
char* getpass()
{
	char pass[200];
	int i=0;
   while(1)
   {
    pass[i] = getch();
    if(pass[i]==13)
    {
  		pass[i]='\0';
  		break;
    }
    else if(i>=1 && pass[i]==8)  //Checks for backspace
    {
  		i--;
  		gotoxy(46+i,12);
  		cout<<" ";
  		gotoxy(46+i,12);
    }
    else
    {
  		cout<<'*';
  		i++;
    }
	}
	return pass;
}
//*****************
//Display Functions
//*****************

//Creates horizontal rule
void hr(int i,char ch)
{
	for(int j=0;j<81;j++)
	{
		gotoxy(j,i);
		cout<<ch;
	}
}
//Creates Vertical Rule
void vr(int i,char ch)
{
	for(int j=0;j<25;j++)
	{
		gotoxy(i,j);
		cout<<ch;
	}
}
//Creates borders
void borders()
{
	char ch = '*';
	hr(0,ch);
	hr(25,ch);
	vr(0,ch);
	vr(81,ch);
}

//Center Functions
void center(char* word,int y=12.5)
{
	int length = strlen(word);
	gotoxy(40.5 - length/2,y);
	cout<<word;
}

//Display Menu
/*void createMenu(char* word)
{
	clrscr();
	borders();
	hr(4,'*');
	center(word,2);
}*/

void dispArray(char* array[],int arraySize,int step=3,int start=6)
{
	for(int i=0; i<arraySize;i++)
	{
		char word[50] = {i+49,'.'};
		for(int j = 2; array[i][j-2]!='\0';j++)
		{
			word[j]=array[i][j-2];
		}
	 center(word,start+(i*step));
	}
}
//Menu functions
//Creates a menu with the given heading and the elements passed through the array
void createMenu(char* word,char* array[],int arraySize,int step=3)
{
	clrscr();
	borders();
	hr(4,'*');
	center(word,2);
	dispArray(array,arraySize,step,6);
}
//Creates output screen with border and heading
void createMenu(char* word)
{
	clrscr();
	borders();
	hr(4,'*');
	center(word,2);
}
void errormsg(char* error="null")
{
	clrscr();
	borders();
  createMenu("ERROR");
	if(strcmp(error,"null"))
		center(error);
	center("Press any key to continue...",17);
	getche();
}
//Simplified gotoxy to align text 
void align(char* text,int x,int y)
{
  gotoxy(x,y);
  cout<<text;
}
//Displays dixit, give x and y for its position
void dixit(int x=10,int y=1)
{
        align("¯\\_('_')_/¯",x,y);
        align("|",x+5,y+1);       
        align("|",x+5,y+2);
        align("|",x+5,y+3);
        align("/ \\",x+4,y+4);
        align("_/   \\_",x+2,y+5);  
}
//*****************
//Global Variables
//*****************
char* Departments[] = {"General Medicine","ENT","Pediatrics","Neurology","Gynacology","Opthamology","Dental"};
char* Mainmenu[] = {"New Admission","Search","Facilities","Billing","Reports","Patient Checkout","Exit"};
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
void facilities(int);   //Function To Display Facilities Offered
void ShowReport();      //Function To Display Patient Report
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
	align("Enter Username: ",30,10);
	gets(uname);
	align("Enter Password: ",30,12);
	strcpy(pass,getpass());
	strcpy(pass,encrypt(pass));
  }
  int access(char ename[],char epass[])
  {
	int x=((strcmp(epass,pass)==0 && strcmp(ename,uname)==0)?1:0);
	return x;
  }
};
///////////////////
//Patient Class
///////////////////
class patient
{
	char pname[20];
	long cprno;
	int fac[];
	int roomNo;
	float pBill;
public:
	void input()
	{
		align("Patient Name: ",25,10);
		gets(pname);
		align("CPR Number: ",25,12);
		cin>>cprno;
		align("Room Number: ",25,14);
		cin>>roomNo;
	}
	void display()
	{
		createMenu("Patient Details");
		align("Patient Name: ",30,10);
		cout<<pname;
		align("CPR No: ",30,12);
		cout<<cprno;
		align("Room No: ",30,14);
		cout<<roomNo;
		center("Press any key to continue",17);
		getch();
		main_menu();
		/*gotoxy(30,5);
		cout<<"Patient Name: "<<pname;
		gotoxy(30,7);
		cout<<"CPR No: "<<cprno;
		gotoxy(30,9);
		cout<<"Room No: "<<roomNo;*/
	}
	int check(long cpr)
	{
	  int x=(cprno==cpr?1:0);
	  return x;
	}
	int check(char* name)
	{
	  int	x=(strcmpi(name,pname)==1?1:0);
	  return x;
	}
	void bill()
	{
	  float x,y,z;   //for lab charge, pharmacy charge etc
	  clrscr();
	  randomize();
	  x=1+random(15);
	  y=1.5+random(5);
	  z=1+random(7);
	  pBill=x+y+z+5+10;

	  createMenu("Billing Information ");
	  align("Admission Fee    : 5 BD",29,8);
	  gotoxy(29,10);
	  cout<<"Laboratory charge: "<<x<<" BD";
	  gotoxy(29,12);
	  cout<<"Pharmacy         : "<<y<<" BD";
	  gotoxy(29,14);
	  cout<<"Physical Therapy : "<<z<<" BD";
	  align("Accomodation     : 10 BD",29,16);
	  align("_________________________",29,17);
	  gotoxy(29,18);
	  cout<<"Total Bill       : "<<pBill<<" BD";
	}
};
//Search Patient Function
int searchPatient()
{
	first_screen:

	char* pSearchMenu[]={"Search by Name","Search by CPR"};
	createMenu("Patient Search",pSearchMenu,sizeof(pSearchMenu)/4,4);

	center("Enter your option: ",15);
	char* name;
	long cpr;
	char choice=getch();
	switch(choice)
	{
		case '1':
			center("Enter name: ",21);
			gets(name);
			break;
		case '2':
			center("Enter CPR Number: ",21);
			cin>>cpr;
			break;
		default:
			errormsg("Invalid Option....");
			goto first_screen;
	}
  patient P;
  ifstream file;
  file.open("patients.dat",ios::in|ios::binary);
  while(!file.eof())
  {
	 file.read((char*)&P,sizeof(P));
	 if(P.check(cpr) && choice==1)
	 {
		cout<<"check1";
		int point = file.tellg();
		file.close();
		return point;
	 }
	 else if (P.check(name) && choice==2)
	 {
		cout<<"check2";
		int point = file.tellg();
		file.close();
		return point;
	 }
  }
  cout<<"check3";
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
	 align("LOGIN",36,7);
	 align("Enter Username: ",30,10);
	 gets(uname);
	 align("Enter Password: ",30,12);
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
		goto
		login;
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
	patient P;
	ifstream file;
	int point;
	char option=getch();
	switch(option)
	{
	  case '1':
			addPatient();
			break;
	  case '2':
			point = searchPatient();
			point -= sizeof(P);
			file.open("patients.dat",ios::in|ios::binary);
			file.seekg(point);
			file.read((char*)&P,sizeof(P));
			P.display();
			break;
	  case '3':
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
	file.open("patients.dat",ios::app|ios::binary);
	file.write((char*)&P,sizeof(P));
	file.close();
}
void facilities(int fac[])
{
first_screen:

  char* facilityMenu[]={"Departments","Lab","Rooms","Main Menu"};
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
	borders();
	align("Enter CPR number to view the Bill: ",17,12);
	cin>>cpr;
	ifstream file;
	file.open("patients.dat",ios::in|ios::binary);
	while(!file.eof())
	{
		file.read((char*)&P,sizeof(P));
		if(P.check(cpr))
	  {
		  P.bill();
		  align("Press any key to go to Main Menu..",25,24);
		  getche();
		  main_menu();
		  break;
	  }
		else
	  {
		errormsg("The entered CPR no. doesn't exist");
		main_menu();
		break;
	  }
	}
  file.close();
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
	align("Welcome to hangman",1,2);
	align("Guess the country name",1,3);
	align("You have 5 guesses left",1,4);
	align("~~~~~~~~~~~~~~~~~~~~~~~~",1,5);
	while (WrongGuess <mt)
	{
		gotoxy(1,6);
		cout<<endl<<endl<<unknown;
		align("\n\nGuess a letter: ",1,7);
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
			align("You guessed it right!",1,9);
			exit(0);
			break;
		}
	 }
	  if(WrongGuess == mt)
	  {
			gotoxy(1,7);
			cout<<endl<<"You lose... you've been hanged."<<endl;
			gotoxy(1,6);
			cout<<"The word was: "<<word<<endl;
			dixit(33,3);
			dixit(47,3);
			dixit(61,3);
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
