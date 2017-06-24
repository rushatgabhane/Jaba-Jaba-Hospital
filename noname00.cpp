#include <iostream.h>
#include <stdio.h>
#include <conio.h>
 void borders()
 {
  	//Borders
	for(int j=0;j<81;j++)
	{
	 gotoxy(j,0);
	 cout<<'*';
	}
	for(int k=1;k<24;k++)
	{
	 gotoxy(0,k);
	 cout<<'*';
	}
	for(int m=0;m<81;m++)
	{
	 gotoxy(m,24);
	 cout<<'*';
	}
	for(int n=1;n<24;n++)
	{
	 gotoxy(81,n);
	 cout<<'*';
	}
	//Border End
 }
 void login() //Our first function
 {
	int i = 0;
	char pass[200],uname[200];

	gotoxy(30,10);
	cout<<"Enter username: ";
	gets(uname);
	gotoxy(30,12);
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
   //Remove Output
	cout<<"\nThe Username:"<<uname;
   cout<<"\nThe Password:"<<pass;
 }
 void main()
 {
  borders();
  login();
  getche();
 }