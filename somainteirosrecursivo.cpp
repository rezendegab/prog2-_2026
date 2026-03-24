#include <iostream>
using namespace std;

int soma(int);

int main(){
    int n;
    cin>> n;
    cout<< "a  soma dos n primeiros numeros de "<<n<<" "<<"é: "<<soma(n)<<endl;
    return 0;
}

int soma(int n){
    if(n == 0)
        return 0;
    return n + soma(n-1);
}