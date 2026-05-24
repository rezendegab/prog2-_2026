#include <iostream>
using namespace std;
#define MAX 100
//estrutura do evento
struct evento{
    int horario_inicio;
    int duracao;
};

//prototipaçao das funçoes merge e mergeSort
void mergeSort(int,int,evento[]);
void merge(int,int,int,evento[]);
void imprime(int,evento[]);

int main(){
    evento even[MAX];
    int n;
    cin>> n;
    for(int i =0;i<n;i++){
        cin>> even[i].horario_inicio;
        cin>> even[i].duracao;
    }
    mergeSort(0,n-1,even);
    imprime(n,even);
    return 0;
}
// implmentaçao da funçao mergeSort
void mergeSort(int p,int r,evento even[]){
    if(p<r-1){
        int q =(p+r)/2;
        mergeSort(p,q,even);
        mergeSort(q,r,even);
        merge(p,q,r,even);  
    }
}

void merge(int p,int q,int r,evento even[]){
    int i,j,k;
    i = p;
    j = q;
    k = 0;
    evento w[MAX];
    while(i<q &&j<r){
        if(even[i].horario_inicio<even[j].horario_inicio){
            w[k] = even[i];
            i++;
        }else{
            w[k] = even[j];
            j++;
        }
        k++;
    }
    while(i<q){
        w[k] = even[i];
        i++;
        k++;
    }
    while(j<r){
        w[k] = even[j];
        j++;
        k++;
    }
    if(even[i].horario_inicio == even[j].horario_inicio){
        if(even[i].duracao<even[j].duracao){
            w[k]=even[i];
            i++;
        }else{
            w[k]=even[j];
            j++;
        }
        k++;
    }
    for(i=p;i<r;i++)
        even[i] = w[i-p];
}

void imprime(int n,evento even[]){
    for(int i =0;i<n;i++){
        cout<<even[i].horario_inicio<<" "<<even[i].duracao<<endl;
    }
    cout<<endl;
}