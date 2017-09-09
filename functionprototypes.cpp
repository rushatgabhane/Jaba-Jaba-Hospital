//Creates horizontal rule
void hr(int i,char ch);
//Creates vertical rule
void vr(int i,char ch);
//Creates borders
void borders();
//Center Functions
void center(char* word,int y=12.5);
//Displays the elements of a passed array by calling the center function
void dispArray(char* array[],int step=3,int start=6);
//Menu functions
//Creates a menu with the given heading and the elements passed through the array
void createMenu(char* word,char* array[],int step=3);
//Creates output screen with border and heading
void createMenu(char* word);
//Can be called to create a simple error screen
void errormsg(char* error="null");
//Simplified gotoxy to align text 
void align(char* text,int x,int y);
//Displays dixit, give x and y for its position
void dixit(int x=10,int y=1);
//*****************
//Special Functions
//*****************
//Encrypt function
//Encrypts the entered word by adding the length of the string to each character
char* encrypt(char pass[]);
//Function to get password
char* getpass();