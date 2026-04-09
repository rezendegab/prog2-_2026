#include <iostream>
using namespace std;
#define MAX 100

//prototipaçao de funçao
void insertionSort(int,int []);
void imprime(int,int []);

int main(){
    int n,v[MAX];
    cout<<"Digte o tamanho do vetor "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    cout<<"vetor antes de ordenar "<<endl;
    imprime(n,v);
    insertionSort(n,v);
    cout<<"vetor a pos ordenar"<<endl;
    imprime(n,v);

    return 0;
}
//implementaçao de funçao
void imprime(int n,int v[MAX]){
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout <<"\n\n";
    
}

void insertionSort(int n, int v[MAX]){
    for (int i = 1; i < n; i++){
        int x = v[i];
        int j;
        for (j = i-1; j >=0&&v[j]>x; j--){
            v[j+1] = v[j];
        }
        v[j+1] = x;
        
    }
    
}