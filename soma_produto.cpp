#include <iostream>
using namespace std;

//prototipaçao de funçao
void soma_prod(int,int,int*,int*);

int main(){
    int a,b,soma,prod;
    cin>>a;
    cin>>b;
    soma_prod(a,b,&soma,&prod);
    return 0;
}
//implemntaçao da funçao
void soma_prod(int a,int b,int * soma,int *prod){
    *soma = a+b;
    *prod = a*b;
    cout<<"a soma de dois numeros: "<<*soma<<" "<<"o produto de dois numeros: "<<*prod<<endl;
}