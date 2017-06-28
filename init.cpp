#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include "sfun.h"
#include "borders.h"
void main()
{
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
  int access(char upass[])
  {
	if(strcmp(upass,pass)==0)
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