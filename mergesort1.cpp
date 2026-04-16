#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 100
//prototipaçao de funçao
void imprime(int ,int[]);
void mergeSort(int,int,int[]);
void merge(int, int, int,int []);

int main(){
    int n,vet[MAX];
    cin>> n;

    srand(time(0));
    for(int i = 0;i<n;i++)
        vet[i] = rand()%101;
    cout<<"Vetor antes da ordenação "<<endl;
    imprime(n,vet);
    mergeSort(0,n,vet);
    cout<<"vetor a pós ordenação "<<endl;
    imprime(n,vet);
    return 0;
}

void imprime(int n,int v[MAX]){
    for(int i = 0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<"\n\n";
}
void mergeSort(int p,int r,int v[MAX]){
    if(p<r-1){// se tiver pelo menos dois elementos
        int q = (p+r)/2;//calcula  para quebrar ao meio
        mergeSort(p,q,v);//chama o mergesort para a primeira metade
        mergeSort(q,r,v);//a memsa coisa do anterior só que para segunda metada
        merge(p,q,r,v);//funçao apara intercalar o vetor e cada indice
    }
}

void merge(int p,int q,int r,int v[MAX]){
    int i,j,k;
    int w[MAX];
    i = p;
    j = q;
    k = 0;
    while(i<q&&j<r){// se tiver elementos na subsequencia
        if(v[i]<v[j]){
            w[k] = v[i];
            i++;
        }else{
            w[k] = v[j];
            j++;

        }
        k++;

    }// caso falte elementos em i ou em j
    while(i<q)
        w[k++] = v[i++];
    while(j<r)
        w[k++] = v[j++];
    // juntar ao vetor original
    for(i = p;i<r;i++)
        v[i] = w[i-p];

}