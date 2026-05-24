#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
using namespace std;
#define MAX 100000

//prototipçao das funçoes
void bubbleSort(int ,int[]);
void selectionSort(int, int[]);
void insertionSort(int, int[]);
void mergeSort(int,int,int[]);
void merge(int,int,int,int[]);
void quickSort(int,int,int[]);
void quickSort2(int,int,int[]);
int partition2(int,int,int[]);
int partition(int,int,int[]);
void troca(int &,int &);
//void imprime(int,int[]);

int main(){
    int n;
    int vetB[MAX];
    int vetS[MAX];
    int vetI[MAX];
    int vetM[MAX];
    int vetQ[MAX];
    int vetQ2[MAX];
    timeval inicio,fim,total;
    long tempo_bubble, tempo_selection, tempo_insertion, tempo_merge, tempo_quick, tempo_quick2;
    cin>>n;
    srand(time(0));
    for(int i = 0;i<n;i++)
        //vetB[i] = vetS[i] = vetI[i] = vetM[i] = vetQ[i] =vetQ2[i]= rand()%1000;
        vetB[i] = vetS[i] = vetI[i] = vetM[i] = vetQ[i] =vetQ2[i]=n-i;
        //vetB[i] = vetS[i] = vetI[i] = vetM[i] = vetQ[i] =vetQ2[i]=i;
    gettimeofday(&inicio,0);
    bubbleSort(n,vetB);
    gettimeofday(&fim,0);
    timersub(&fim,&inicio,&total);
    tempo_bubble = total.tv_sec *1000000 +total.tv_usec;

    gettimeofday(&inicio,0);
    selectionSort(n,vetS);
    gettimeofday(&fim,0);
    timersub(&fim,&inicio,&total);
    tempo_selection = total.tv_sec *1000000 +total.tv_usec;

    gettimeofday(&inicio,0);
    insertionSort(n,vetI);
    gettimeofday(&fim,0);
    timersub(&fim,&inicio,&total);
    tempo_insertion = total.tv_sec *1000000 +total.tv_usec;

    gettimeofday(&inicio,0);
    mergeSort(0,n,vetM);
    gettimeofday(&fim,0);
    timersub(&fim,&inicio,&total);
    tempo_merge = total.tv_sec *1000000 +total.tv_usec;

    gettimeofday(&inicio,0);
    quickSort(0,n-1,vetQ);
    gettimeofday(&fim,0);
    timersub(&fim,&inicio,&total);
    tempo_quick = total.tv_sec *1000000 +total.tv_usec;

    gettimeofday(&inicio,0);
    quickSort2(0,n-1,vetQ2);
    gettimeofday(&fim,0);
    timersub(&fim,&inicio,&total);
    tempo_quick2 = total.tv_sec *1000000+total.tv_usec;

    cout<<"Tempo Bubble Sort: "<<tempo_bubble<<" ms"<<endl;
    cout<<"Tempo Selection Sort: "<<tempo_selection<<" ms"<<endl;
    cout<<"Tempo Insertion Sort: "<<tempo_insertion<<" ms"<<endl;
    cout<<"Tempo Merge Sort: "<<tempo_merge<<" ms"<<endl;
    cout<<"Tempo Quick Sort: "<<tempo_quick<<" ms"<<endl;
    cout<<"Tempo do Quick com pivo aleatorio: "<<tempo_quick2<<" ms"<<endl;
    return 0;
}

// implementaçao das funçoes

void bubbleSort(int n,int v[MAX]){
    for(int i = n-1;i>0;i--)
        for(int j = 0;j<i;j++)
            if(v[j]<v[j+1])
                troca(v[j],v[j+1]);
    
}

void selectionSort(int n,int v[MAX]){
    for(int i = 0;i<n-1;i++){
        int min = i;
        for(int j = i+1;j<n;j++)
            if(v[j]>v[min])
                min = j;
        troca(v[i],v[min]);
    }
}

void insertionSort(int n,int v[MAX]){
    for(int i = 1;i<n;i++){
        int x = v[i];
        int j;
        for(j = i-1;j>=0 && v[j]<x;j--)
            v[j+1] = v[j];
        v[j+1] = x;
    }
}

void mergeSort(int p, int r,int v[MAX]){
    if(p<r-1){
        int q=(p+r)/2;
        mergeSort(p,q,v);
        mergeSort(q,r,v);
        merge(p,q,r,v);
    }
}

void merge(int p,int q,int r,int v[MAX]){
    int i,j,k;
    int w[MAX];
    i = p;
    j = q;
    k = 0;
    while(i<q && j<r){
        if(v[i]>v[j]){

            w[k] = v[i];
            i++;
        }else{
            w[k] = v[j];
            j++;
        }
    }
    while(i <q)
        w[k++] = v[i++];
    
    while(j<r)
        w[k++] = v[j++];
    for(i = p;i<r;i++)
        v[i] = w[i-p];
}

void quickSort(int p,int r,int v[MAX]){
    int q;
    if(p<r){
        q = partition(p,r,v);
        quickSort(p,q-1,v);
        quickSort(q+1,r,v);
    }
}

int partition(int p,int r,int v[MAX]){
    int i,j,x;
    i = p-1;
    x = v[r];
    for(j= p;j<r;j++){
        if(v[j]>=x){
            i++;
            troca(v[i],v[j]);
        }
    }
    troca(v[i+1],v[r]);
    return i +1;
}
void troca(int &a,int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}
void quickSort2(int p,int r,int v[MAX]){
    int q;
    if(p<r){
        q = partition2(p,r,v);
        quickSort2(p,q-1,v);
        quickSort2(q+1,r,v);
    }
}

int partition2(int p,int r,int v[MAX]){
    int i,j,x;
    i = p-1;
    x= v[p+rand()%(r-p+1)];
    for(j = p;j<r;j++){
        if(v[j]>=x){
            i++;
            troca(v[i],v[j]);
        }
    }
    troca(v[i+1],v[r]);
    return i +1;

}