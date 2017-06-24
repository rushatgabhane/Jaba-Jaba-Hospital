void simple(char ch)
{
  for(int j=0;j<81;j++)
  {
	gotoxy(j,0);
	cout<<ch;
  }
  for(int k=1;k<24;k++)
  {
	gotoxy(0,k);
	cout<<ch;
  }
  for(int m=0;m<81;m++)
  {
	gotoxy(m,24);
	cout<<ch;
  }
  for(int n=1;n<24;n++)
  {
	gotoxy(81,n);
	cout<<ch;
  }
}