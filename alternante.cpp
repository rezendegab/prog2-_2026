#include <iostream>
using namespace std;
# define MAX 100

//protipaçao das funçoes
void bubbleSort(int [],int);
bool alternante(int[],int);
void troca(int *,int*);
void imprime(int [],int);

int main(){
    int n,v[MAX];
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    bubbleSort(v,n);
    if(alternante(v,n))
        cout<<"ALTERNANTE"<<endl;
    else
        cout<<"NAO ALTERNANTE"<<endl;
    imprime(v,n);
    return 0;
}
void bubbleSort(int v[],int n){
    for(int i = n-1;i>0;i--){
        for(int j = 0;j<i;j++){
            if(v[j]>v[j+1])
                troca(&v[j],&v[j+1]);
        }
    }
}
bool alternante(int v[],int n){
    int dif= v[1]-v[0];
    for(int i = 2;i<n;i++){
        if(v[i]-v[i-1]!=dif)
            return false;
    }
    return true;
}
void troca(int *a,int*b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
void imprime(int v[],int n){
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}