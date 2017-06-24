#include <iostream.h>
#include <stdio.h>
#include <conio.h>
void login() //Our first function
{
	int i = 0;
	char pass[200],uname[200];
	cout<<"Enter username: ";
	gets(uname);
	cout<<"Enter password: ";
	while(1)  //stars out password
	{
		pass[i] = getch();
		if(pass[i]==13)
		{
		  pass[i]='\0';
		  break;
		}
		cout<<'*';
		i++;
	}
	pass[i]='\0';
	cout<<'\n'<<pass;
	cout<<'\n'<<uname;
}
 void main()
{
 login();
}

