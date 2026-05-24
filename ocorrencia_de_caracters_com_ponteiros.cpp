#include <iostream>
using namespace std;

bool ocorre(char*,char*);
int main(){
    char str1[100],str2[100];
    cout<<"digite a cadeia 1: "<<endl;
    cin>>str1;
    cout<<"digite a cadeia 2: "<<endl;
    cin>>str2;
    if(ocorre(str1,str2)){
        cout<<"ocorre na ambas as cadeias"<<endl;
    }else{
        cout<<"nao ocorre em ambas as cadeias "<<endl;
    }
    return 0;
}
bool ocorre(char*p,char*q){
    while(*p!='\0'){
        char* a =p;
        char* b = q;
        while(*a==*b &&*b!='\0'&& a!='\0'){
            a++;
            b++;
        }
        if(*b=='\0'&&*a=='\0'){
            return true;
        }
        p++;

    }
    return false;
}

