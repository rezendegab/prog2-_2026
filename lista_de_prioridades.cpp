#include <iostream>
using namespace std;
#define MAX 100

struct tarefas{
    int id;
    string nome;
    int prioridade;
};
//prototipçao das funçoes
void quickSort(int,int,tarefas[]);
int partition(int,int,tarefas[]);
void imprime(int,tarefas[]);
void troca(tarefas &,tarefas &);

int main(){
    tarefas t[MAX];
    int n;
    cin>>n;
    for(int i =0; i<n;i++){
        cin>>t[i].id>>t[i].nome>>t[i].prioridade;
    }
    quickSort(0,n-1,t);
    imprime(n,t);
    return 0;
}
//implementaçao das funçoes
void quickSort(int p,int r,tarefas t[MAX]){
    if(p<r){
        int q=partition(p,r,t);
        quickSort(p,q-1,t);
        quickSort(q+1,r,t);
    }
}
int partition(int p,int r, tarefas t[MAX]){
    int x = t[r].prioridade;
    int i=p-1;
    for(int j=p;j<r;j++){
        if(t[j].prioridade>x){
            i++;
            troca(t[i],t[j]);
        }
    }
    troca(t[i+1],t[r]);
    return i+1;
}
void imprime(int n,tarefas t[MAX]){
    for(int i = 0;i<n;i++){
        cout<<t[i].id<<" "<<t[i].nome<<" "<<t[i].prioridade<<endl;
    }
    cout<<"\n\n";
}
void troca(tarefas &a,tarefas &b){
    tarefas aux;
    aux = a;
    a=b;
    b = aux;
}
