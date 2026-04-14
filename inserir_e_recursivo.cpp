#include <iostream>
using namespace std;
#define MAX 100

// prototipação das funções
void imprime(int n,int v[MAX]);
int insere(int n,int v[MAX],int k,int y);
int insere_R(int n,int v[MAX],int k,int x);

int main(){
    int n,n1,v[MAX],v1[MAX],k,y,x;
    cout<<"Digite o tamanho do vetor "<<endl;
    cin>>n;
    n1 = n;
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    for(int i = 0; i < n; i++){
        v1[i] = v[i];
    }
    cout<<"Digite a posicao que o valor vai ser inserido "<<endl;
    cin>>k;
    cout<<"Digite o valor que vai ser inserido sem recursao "<<endl;
    cin>>y;
    cout<<"Digite o valor que vai ser inserido com recursao "<<endl;
    cin>>x;
    cout<<"sem recursao "<<endl;
    n = insere(n,v,k,y);
    imprime(n,v);
    cout<<"com recursao "<<endl;
    n1 = insere_R(n1,v1,k,x);
    imprime(n1,v1);
    return 0;
}

void imprime(int n,int v[MAX]){
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";
}

int insere(int n,int v[MAX],int k,int y){
    if(k < 0 || k > n || n == MAX){
        return n;
    }
    for(int i = n; i > k; i--){
        v[i] = v[i-1];
    }
    v[k] = y;
    return n + 1;
}

int insere_R(int n,int v[MAX],int k,int x){
    if(k < 0 || k > n || n == MAX){
        return n;
    }
    if(n == k){
        v[k] = x;
        return n + 1;
    }
    v[n] = v[n-1];
    return insere_R(n-1,v,k,x);
}
