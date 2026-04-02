#include <iostream>
#include <stdlib.h>// para usar srand e rand
using namespace std;
#define MAX 100
// prototipçao da funçao
void imprime(int,int[]);
void bubble_sort(int,int []);
// protipaço com ponteiros
//void troca(int *,int *);
//prototipaçao como referencia
void troca(int &,int &);
int main(){
    int v[MAX],n;

    cout<<"digite um numero para o tamanho do vetor ";
    cin >> n;
    // deixando a semente ser diferente toda vez
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        // valores aleatorios para o vetor
        v[i] = rand() % 100;
    }
    cout << "vetor como estava: ";
    imprime(n,v);
    bubble_sort(n,v);
    cout<<" vetor pos ordenação: ";
    imprime(n,v);
    
    return 0;
}
//implmentaçao das funçoes
void imprime(int n,int v[MAX]){
    for (int i = 0; i < n; i++){
        cout<<v[i]<<" ";

    }
    cout<<"\n\n";
}

/*void troca(int *n,int *m ){
    int aux;
    aux = *n;
    *n = *m;
    *m = aux;

}*/
void troca(int &n,int &m){
    int aux;
    aux = n;
    n = m;
    m = aux;
}
void bubble_sort(int n,int v[MAX]){
    int i,j;
    for(i = n-1;i>0;i--)
        for(j = 0;j<i;j++)
            if(v[j]>v[j+1])
                //troca(&v[j],&v[j+1]);
                troca(v[j],v[j+1]);
}
