#include<iostream>
using namespace std;
#define MAX 100

//prototipaçao das funçoes
int quickSelect(int,int,int,int[]);
int partition(int,int,int[]);
void troca(int &,int &);


int main(){
    int n,k;
    int v[MAX];
    cout<<"Digite a o tamanho do vetor: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"digte o valor a ser encotrado: "<<endl;
    cin>>k;
    if(k<1||k>n)
        cout<<"invalido"<<endl;
    cout<<"o menor elemento do vetor é: "<<k<<endl;
    int res = quickSelect(0,n-1,k-1,v);
    cout<<k<<" menor elemento = "<<res<<endl;
    return 0;
}

int quickSelect(int p,int r,int k,int v[MAX]){
    int q=partition(p,r,v);
    if(q==k)
        return v[q];
    if(k<q)
        return quickSelect(p,q-1,k,v);
    return(quickSelect(q+1,r,k,v));
}

int partition(int p,int r,int v[MAX]){
    int x = v[r];
    int i = p-1;
    for(int j=p;j<r;j++){
        if(v[j]<=x){
            i++;
            troca(v[i],v[j]);
        }
    }
    troca(v[i+1],v[r]);
    return i+1;
}
void troca(int &a,int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}