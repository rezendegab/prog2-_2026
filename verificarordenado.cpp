#include <iostream>
using namespace std;
#define MAX 100

// prototipçao das funçao
bool ordenado(int v[MAX],int n);

int main(){
    int n,v[MAX];
    cout<<"Digite o tamanho do vetor: "<<endl;
    cin>> n;
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    if(ordenado(v,n)){
        cout<<"Ordenado "<<endl;
    }
    else{
        cout<<"Nao Ordenado "<<endl;
    }
    return 0;
}

bool ordenado(int v[MAX],int n){
    for(int i = 0;i<n-1;i++){
        if(v[i]>v[i+1]){
            return false;
        }
    }
    return true;
}
