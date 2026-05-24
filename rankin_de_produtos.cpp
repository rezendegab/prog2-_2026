#include <iostream>
using namespace std;
#define MAX 100

//struct de produto
struct  produto{
    int id;
    string nome;
    int pontuacao_relevancia;


};
// prototipaçao das funçoes
void mergeSort(int,int,produto[]);
void merge(int,int,int,produto[]);
void imprime(int,produto[]);

int main(){
    produto prod[MAX];
    int n;
    cin>> n;
    for(int i = 0;i<n;i++){
        cin>> prod[i].id;
        cin>>prod[i].nome;
        cin>>prod[i].pontuacao_relevancia;
    }
    mergeSort(0,n,prod);
    imprime(n,prod);
    return 0;
}
//implementaçao das funçoes
void mergeSort(int p,int r,produto prod[MAX]){
    if(p<r-1){
        int q = (p+r)/2;
        mergeSort(p,q,prod);
        mergeSort(q,r,prod);
        merge(p,q,r,prod);
    }
}

void merge(int p,int q,int r,produto prod[MAX]){
    int i,j,k;
    produto w[MAX];
    i = p;
    j=q;
    k= 0;
    while(i<q && j<r){
        if(prod[i].pontuacao_relevancia> prod[j].pontuacao_relevancia){
            w[k] = prod[i];
            i++;
        }else{
            w[k] = prod[j];
            j++;
        }
        k++;
    }
    while(i<q){
        w[k] = prod[i];
        i++;
        k++;
    }
    while(j<r){
        w[k] = prod[j];
        j++;
        k++;
    }
    if(prod[i].pontuacao_relevancia == prod[j].pontuacao_relevancia){
        if(prod[i].nome<prod[j].nome){
            w[k] = prod[i];
            i++;
            k++;
        }else{
            w[k]=prod[j];
            j++;
            k++;
        }
    }
    for(i=p;i<r;i++)
        prod[i] = w[i-p];
}
void imprime(int n,produto prod[MAX]){
    for(int i =0;i<n;i++){
        cout<<prod[i].id<<" "<<prod[i].nome<<" "<<prod[i].pontuacao_relevancia<<endl;
    }
    cout<<"\n\n";
}