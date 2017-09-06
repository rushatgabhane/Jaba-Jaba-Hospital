#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
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

void main()
{
class user
{
  char uname[200];
  char pass[200];
public:
  void input()
  {
	center("Create New Account",8);
	align("Enter Username: ",30,10);
	gets(uname);
	align("Enter Password: ",30,12);
	strcpy(pass,getpass());
	strcpy(pass,encrypt(pass));
	clrscr();
	center("Account Created!",10);
	center("Please head over to the main fuction.",12);
  }
  int access(char ename[],char epass[])
  {
  	if(strcmp(epass,pass)==0 && strcmp(ename,uname)==0)
  		return 1;
  	else
  		return 0;
  }
};
	fstream file1,file2,file3;
	file1.open("patients.dat",ios::out|ios::binary);
	file1.close();
	file2.open("users.dat",ios::out|ios::binary);
	user U;
	U.input();
	file2.write((char*)&U,sizeof(U));
	file2.close();
	file3.open("doctors.dat",ios::out|ios::binary);
	file3.close();
}
