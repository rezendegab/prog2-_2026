#include <iostream>
using namespace std;
#define MAX 100

//prototipação das funções
void bubbleSort(int [],int);
void selectionSort(int [],int);
void insertionSort(int [],int);
void troca(int &,int &);
void imprime(int [],int);

int main(){
    int n,v[MAX],op;
    cout<<"Digite o tamanho do vetor: "<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
     do{
        cout<<"escolha qual ordenaçao usar:"<<endl;
        cout<<"1-Bubble Sort "<<endl;
        cout<<"2-Selection Sort "<<endl;
        cout<<"3-Insertion Sort "<<endl;
        cout<<"4-Sair "<<endl;
        cin>>op;
        if(op==1){
            cout<<"usando Bubble Sort "<<endl;
            bubbleSort(v,n);
            imprime(v,n);
        }
        else if(op == 2){
            cout<<"usando Selection Sort "<<endl;
            selectionSort(v,n);
            imprime(v,n);
        }
        else if(op ==3){
            cout<<"usando Insertion Sort "<<endl;
            insertionSort(v,n);
            imprime(v,n);
        }
    } while (op!=4);
    
    return 0;
}
// implementaçao das funçoes
void bubbleSort(int v[MAX],int n){
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                troca(v[j],v[j+1]);
            }
        }
    }
}

void selectionSort(int v[MAX],int n){
    int min;
    for(int i = 0;i<n-1;i++){
        min = i;
        for(int j = i+1;j<n;j++){
            if(v[j]<v[min]){
                min = j;
            }
        }
        troca(v[i],v[min]);
    }
}

void insertionSort(int v[MAX],int n){
    int x;
    for(int i = 1;i<n;i++){
        x = v[i];
        int j;
        for(j=i-1;j>=0 && v[j]>x;j--){
            v[j+1] = v[j];
        }
        v[j+1] = x;
    }
}

void troca(int &a,int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void imprime(int v[MAX],int n){
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";
}
