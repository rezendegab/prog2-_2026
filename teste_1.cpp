#include <iostream>
#include <cstring>
using namespace std;
 
int main(){
    /*int x,y,*p;
    y=0;
    p=&y;
    x=*p;
    (*p)++;
    --x;
    (*p)+=x;
    cout<<x<<" "<<y<<" "<<*p<<endl;
    */
   const char *a,*b;
   a = "abacate";
   b = "uva";
   if(strcmp(a,b)<0)
        cout<<a<<" vem antes de "<<b<<endl;
    else
        cout<<a<<" vem depois de "<<b<<endl;
    int v[5] = {55000,1,2,3,4};
    cout <<v[0]<<endl;    
    cout<<*(v+3)<<endl;

    return 0;
 }
 