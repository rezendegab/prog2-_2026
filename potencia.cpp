#include <iostream>
using namespace std;
// prototipaçao de funçao
int pot(int x,int n);
int potR(int x,int n);

int main(){
    int x,n;
    cin >>x>>n;
    cout<<"a potencia de "<<x<<"elevada a "<<n<< "é "<<potR(x,n)<<endl;
    return 0;
}
//funçao recursiva de potenciaçao
int potR(int x,int n){
    if(n == 0){
        return 1;
    }
    return x*potR(x,n-1);

}
// funçao interativa de potenciaçao
int pot(int x, int n){
    int resultado = 1;
    for(int i = 0;i<n;i++){
        resultado *=x;
    }
    return resultado;
}