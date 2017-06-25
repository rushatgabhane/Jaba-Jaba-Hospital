#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
  class Hospital
  {
	int idno;
	char name[20],uname[20],pass[20];
	public:
	 void login() //Our first function
	{
	 int i=0;
	 gotoxy(30,10);
	 cout<<"Enter username: ";
	 gets(uname);
	 gotoxy(30,12);
	 cout<<"Enter password: ";
	 while(1)
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
  }
	void borders()
  {
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
  }
};
 void main()
{
 Hospital H;
 H.borders();
 ofstream fout;
 fout.open("Patients.dat",ios::out|ios::binary);
  H.login();
 fout.write((char*)&(H),sizeof(H));
 fout.close();
}
