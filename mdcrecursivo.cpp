#include <iostream>
using namespace std;
// prototipaçao do algoritmo de euclides
int Mdc(int,int);

int main(){
    int n ,m;
    cout<<"Digite os valores para algoritimo de euclides ";
    cin>>n>>m;

    cout<<"O maximo divisor comum dos numeros "<< n<<" e "<< m <<" são: "<<Mdc(n,m)<<endl;
    return 0;
}
// funçao de maximo divisor comum conhecido tambem como algoritimo de euclides
int Mdc(int num1, int num2){
    if(num2 == 0)
        return num1;
    return Mdc(num2, num1 % num2);
}
