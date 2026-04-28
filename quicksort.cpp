#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 100

// prototipaçao das funçoes
void quickSort(int,int,int []);
void imprime(int,int []);
void troca(int &,int &);
int partition(int,int,int []);

int main(){
    int n,v[MAX];
    cout<<"digite o tamnho do vetor "<<endl;
    cin>> n;
    srand(time(0));
    for(int i = 0;i<n;i++){
        v[i] = rand()%101;
    }
    cout<<"vetor antes da ordenaçao "<<endl;
    imprime(n,v);
    quickSort(0,n,v);
    cout<<"vetor apos a ordenaçao "<<endl;
    imprime(n,v);
    return 0;
}
void quickSort(int p,int r,int v[MAX]){
    int q;
    if(p<r){//verifica se tem pelo menos 2 elementos no vetor
        q = partition(p,r,v);//chama o partition parar obter indico do pivo
        quickSort(p,q-1,v);//chama para primeira metade do vetor 
        quickSort(q+1,r,v);//chama para segunda metade do vetor
    }
}
void imprime(int n,int v[MAX]){
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";
}

void troca(int &a,int &b){
    int aux;
    aux = a;
    a = b;
    b = aux; 
}
//funçao para particionar o vetor e colocar o pivo na posiçao correta
//o pivo escolhido como ultimo indice e coloca no indice correto e sera retornado
//elementos maiores ou iguais
int partition(int p,int r,int v[MAX]){
    int x,i,j;
    x = v[r];//escolhe o ultimo pivo
    i = p-1;
    for(j=p;j<r;j++){
        if(v[j]<= x){
            i = i +1;
            troca(v[i],v[j]);
        }
    }
    troca(v[i+1],v[r]);// coloca o pivo corretamente na posiçao
    return i +1;
}