#include <iostream>
using namespace std;
#define MAX 100

//prototipaçao da funçao
void imprime(int n,int v[MAX]);
int remove(int,int [],int);
int removeR(int,int[],int);

int main(){
    int n,n2,k,i,com,sem;
    int v[MAX],v1[MAX];
    cout<< "digite o tamanho do vetor: "<<endl;
    cin>> n;
    n2 = n;
    for(i= 0;i<n;i++){
        cin>>v[i];
    }
    for(i= 0;i<n;i++){
        v1[i] = v[i];
    }
    cout<<"digite a posicao que vai ser removida: "<<endl;
    cin>>k;
    cout<<"vetor original :"<<endl;
    imprime(n,v);
    sem = remove(n,v,k);
    cout<<"versao sem recursao "<<endl;
    imprime(sem,v);
    
    com = removeR(n2,v1,k);
    cout<<"versao com recursao "<<endl;
    imprime(com,v1);

    return 0;
}
void imprime(int n,int v[MAX]){
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";
}
int remove(int n,int v[MAX],int k){
    int i;
    if(k<0 || k>=n)
        return n;
    for(i=k;i<n-1;i++)
        v[i]= v[i+1];
    return n -1;
}
int removeR(int n,int v[MAX],int k){
    if(k == n-1)
        return n -1;
    v[k] = v[k+1];
    return removeR(n,v,k+1);
}