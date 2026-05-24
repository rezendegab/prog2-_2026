#include <iostream>
using namespace std;
#define MAX 100

// struct para armazenar dados do aluno
struct aluno{
    int numero_matricula;
    float media_final;
};
//prototipaçao das funçoes
void quickSort(int,int,aluno[]);
int partition(int,int,aluno[]);
void troca(aluno*,aluno*);
void imprime(int,aluno[]);

int main(){
    aluno al[MAX];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>al[i].numero_matricula>>al[i].media_final;
    }
    quickSort(0,n-1,al);
    imprime(n,al);

    return 0;
}

//implementaçao  de funçoes
void quickSort(int p,int r,aluno al[]){
    if(p<r){
        int q = partition(p,r,al);
        quickSort(p,q-1,al);
        quickSort(q+1,r,al);
    }
}
int partition(int p,int r,aluno al[]){
    aluno x = al[r];
    int i;
    for(int j=p;j<r;j++){
        if(al[j].media_final>x.media_final){
            i++;
            troca(&al[i],&al[j]);
        }
        if(al[j].media_final==x.media_final){
            if(al[j].numero_matricula<x.numero_matricula){
                i++;
                troca(&al[i],&al[j]);
            }
        }
    } 
    troca(&al[i+1],&al[r]);
    return i+1;

}
void troca(aluno *a,aluno *b){
    aluno aux;
    aux = *a;
    *a=*b;
    *b=aux;
}