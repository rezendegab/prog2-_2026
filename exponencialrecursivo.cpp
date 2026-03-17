#include<iostream>
using namespace std;
//prototipaçao de funçao
int exp(int,int);

int main(){
    int k,n;
    cout<< "Digite os numeros para exponenciaçao ";
    cin>>k>>n;
    cout<<"o exponencial de "<<k<<" e "<<n<<" é:"<<exp(k,n)<<endl;
    return 0;
}
//implementaçao da funçao exponencial
int exp(int k, int n){
    if(n == 0)
        return 1;
    return k *exp(k,n-1);
}
