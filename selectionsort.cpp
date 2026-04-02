#include <iostream>
#include <stdlib.h>//srand e rand
using namespace std;
#define MAX 100

//prototipaçao das funçoes
void imprime(int ,int []);
void troca(int &,int&);
void selection_sort(int, int[]);

int main(){
    int v[MAX],n;

    cout<<"Digite o valor para o tamanho do vetor: ";
    cin>>n;    
    //set da semente não se repetir
    srand(time(NULL));
    for(int i = 0;i<n;i++){
        v[i] = rand() % 100;
    }
    cout<< "vetor antes: ";
    imprime(n,v);
    selection_sort(n,v);
    cout<< "vetor após a ordenação: ";
    imprime(n,v);
    return 0;
}
//implmentaçao das funçoes
void imprime(int n,int v[MAX]){
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    
    }
    cout<<"\n\n";
    
}
void troca(int &n,int &m){
    int aux;
    aux = n;
    n = m;
    m= aux;
}
void selection_sort(int n,int v[MAX]){
    for(int i = 0;i<n-1;i++){
        int mim = i;
        for(int j = i+1;j<n;j++)
            if(v[j]<v[mim])
                mim= j;
        troca(v[i],v[mim]);
    }
}
