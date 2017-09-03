#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include "sfun.h"
#include "display.h"
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
