#include <fstream.h>
void main()
{
	fstream file1,file2,file3;
	file1.open("patients.dat",ios::out|ios::binary);
	file1.close();
	file2.open("users.dat",ios::out|ios::binary);
	file2.close();
	file3.open("doctors.dat",ios::out|ios::binary);
	file3.close();
}