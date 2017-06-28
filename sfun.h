//****************
//Encrypt function
//****************
char* encrypt(char pass[])
{
  int i=0;
  for(i=0;pass[i]!='\0';i++)
   pass[i]+=strlen(pass);
  return pass;
}
//************************
//Function to get password
//************************
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