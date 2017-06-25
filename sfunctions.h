//Encrypt function
char* encrypt(char pass[])
{
  int i=0;
  for(i=0;pass[i]!='\0';i++)
   pass[i]+=strlen(pass);
  return pass;
}
