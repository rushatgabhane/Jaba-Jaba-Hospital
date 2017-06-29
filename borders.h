//Simple border function
void border(char ch,int x,int y,int l,int b) 
//(x,y) is the top left corner point and l and b are the length and breadth of the rectangle
{	
	int p,q,r,s;
	for(p=x;p<x+l;p++)
	{
		gotoxy(p,y);
		cout<<ch;
		}
	for(q=y,--p;q<y+b;q++)
	{
		gotoxy(p,q);
		cout<<ch;
		}
	for(r=x+l-1,--q;r>=x;r--)
	{
		gotoxy(r,q);
		cout<<ch;
		}
	for(s=y+b-1;s>=y;s--)
	{
		gotoxy(x,s);
		cout<<ch;
		}
    }
