#include <iostream>
using namespace std;
// prototipaçao da funçao
int fibonaci(int num);

int main(){
    int n;
    cout<< "Digite o numero que deseja calcular ";
    cin>>n;

    cout<<"Termo "<<n<<" de Fibonacci é "<<fibonaci(n)<<endl;
    return 0;
}
// funçao recurisva do n-ésimo termo de fibonacci
int fibonaci(int num){
    if(num == 0|| num == 1)
        return num;
    else
        return fibonaci(num -2) + fibonaci(num - 1);

}
