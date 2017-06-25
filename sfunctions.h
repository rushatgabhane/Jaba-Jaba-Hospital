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
	 cout<<'*';
	 i++;
  }
  pass[i]='\0';
  return pass;
}