void hr(int i,char ch)
{
  for(int j=0;j<81;j++)
  {
    gotoxy(j,i);
    cout<<ch;
  }
}
void vr(int i,char ch)
{
  for(int j=0;j<25;j++)
  {
    gotoxy(i,j);
    cout<<ch;
  }
}
void borders()
{
  char ch = '*';
  hr(0,ch);
  hr(25,ch);
  vr(0,ch);
  vr(81,ch);
}
void center(char* word)
{
  int length = strlen(word);
  gotoxy(40.5 - length/2,12.5);
  cout<<word;
}
void center(char* word,int y)
{
  int length = strlen(word);
  gotoxy(40.5 - length/2,y);
  cout<<word;
}