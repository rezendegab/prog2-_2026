#include <iostream>
using namespace std;

void dec2Bin(int n);

int main(){
    int n;
    cin >> n;
    cout << "o valor binario de "<<n<<" é " <<endl;
    dec2Bin(n);
    cout << endl;
    return 0;
}

void dec2Bin(int n){
    if(n == 0){
        cout<< "0";
    }
    else{
         dec2Bin(n/2);
         cout<< n % 2;
    }
    
}