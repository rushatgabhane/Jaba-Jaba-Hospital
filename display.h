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
	 center(array[i],start+(i*step));
  }
}

void createMenu(char* word,char* array[],int arraySize,int step=3)
{
  clrscr();
  borders();
  hr(4,'*');
  center(word,2);
  dispArray(array,arraySize,step,6);
}

void errormsg(char* error)
{
  clrscr();
  borders();
  center(error);
  center("Press any key to continue...",17);
  getche();
}
