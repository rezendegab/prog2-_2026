#include <iostream>
using namespace std;
#define MAX 100

//struct de de estoque
struct armazem{
    long int codigo_barras;
    int quantidade_estoque;
    string nome_produto;

};

//implemntaçao das funçoes
void mergeSort(int,int,armazem[]);
void merge(int,int,int,armazem[]);
void imprime(int,armazem[]);

int main(){
    armazem estoque[MAX];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>estoque[i].codigo_barras;
        cin>>estoque[i].quantidade_estoque;
        cin>>estoque[i].nome_produto;
    }
    mergeSort(0,n-1,estoque);
    imprime(n,estoque);
    return 0;
}

//implementaçao das funçoes
void mergeSort(int p,int r,armazem estoque[MAX]){
    if(p<r-1){
        int q=(p+r)/2;
        mergeSort(p,q,estoque);
        mergeSort(q,r,estoque);
        merge(p,q,r,estoque);
    }
}
void merge(int p,int q,int r,armazem estoque[MAX]){
    int i,j,k;
    armazem w[MAX];
    i = p;
    j= q;
    k = 0;
    while(i<q && j<r){
        if(estoque[i].codigo_barras<estoque[j].codigo_barras){
            w[k] = estoque[i];
            i++;
        }else{
            w[k] = estoque[j];
            j++;
        }
        k++;
    }
    while(i<q){
        w[k] = estoque[i];
        i++;
        k++;
    }
    while(j<r){
        w[k] = estoque[j];
        j++;
        k++;
    }
    for(i=p;i<r;i++){
        estoque[i] = w[i-p];
    }
}
void imprime(int n,armazem estoque[MAX]){
    for(int i=0;i<n;i++){
        cout<<estoque[i].nome_produto<<" "<<estoque[i].quantidade_estoque<<" "<<estoque[i].codigo_barras<<endl;

    }
    cout<<"\n\n";
}