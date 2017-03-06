#include <stdio.h>
//using namespace std;  

int divint(int, int);  
int main() 
{ 
   int x = 5, y = 2; 
   printf("%d\n",divint(x, y)); 
   
   x =3; y = 0; 
   printf("%d\n",divint(x, y)); 
   
   return 0; 
}  

int divint(int a, int b) 
{ 
   return a / b; 
}  