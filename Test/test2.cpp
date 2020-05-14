#include<iostream> 
#include<iomanip>
using namespace std; 

void swap(char * &str1, char * &str2) 
{ 
char *temp = str1; 
str1 = str2; 
str2 = temp; 
} 

int main() 
{ 
string *ps1 = new string("GEEKS"); 
string *ps2 = new string("FOR GEEKS");
//string *ps1 = new string (str1);
//string *ps2 = new string (str2);
swap(ps1,ps2); 
cout<<"str1 is "<< setw(12) << std::left << *ps1 << " " << ps1 << endl; 
cout<<"str2 is "<< setw(12) << std::left << *ps2 << " " << ps2 << endl; 

delete ps1;
delete ps2;

return 0; 
} 
