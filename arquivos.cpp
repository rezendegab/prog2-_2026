#include <iostream>
using namespace std;
#define MAX 100

// prototipaçao das funçoes quicksort,partition,troca e imprime
void quickSort(int,int,string[]);
int partition(int,int,string[]);
void troca(string*,string*);
void imprime(int,string[]);

int main(){
    string nomes[MAX];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>nomes[i];
    }
    quickSort(0,n-1,nomes);
    imprime(n,nomes);
    
    return 0;
}
//implmentaçao das funçoes quicksort,partition, imprime
void quickSort(int p,int r,string nomes[MAX]){
    if(p<r){
        int q = partition(p,r,nomes);
        quickSort(p,q-1,nomes);
        quickSort(q+1,r,nomes);
    }
}
int partition(int p,int r,string nomes[MAX]){
    string x = nomes[r];
    int i,j;
    i = p-1;
    for(j=p;j<r;j++){
        if(nomes[j]<x){
            i++;
            troca(&nomes[i],&nomes[j]);
        }
    }
    troca(&nomes[i+1],&nomes[r]);
    return i+1;
}
void troca(string *a,string *b){
    string aux ;
    aux = *a;
    *a = *b;
    *b = aux;
}
void imprime(int n,string nomes[MAX]){
    for(int i =0;i<n;i++){
        cout<<nomes[i]<<endl;
    }
    cout<<endl;
}
