#include <iostream>
using namespace std;
#define MAX 100

//prototipaçao de funçao
void mergeSort(int,int,string[]);
void merge(int,int,int,string[]);
void imprime(int,string[]);

int main(){
    int n;
    cin>>n;
    string v[MAX];
    for(int i = 0;i<n;i++){
        cin>> v[i];
    }
    imprime(n,v);
    mergeSort(0,n,v);
    imprime(n,v);
    return 0;
}

void mergeSort(int p,int r,string v[MAX]){
    if(p<r-1){
        int q=(p+r)/2;
        mergeSort(p,q,v);
        mergeSort(q,r,v);
        merge(p,q,r,v);
    }
}
void merge(int p,int q,int r,string v[MAX]){
    int i,j,k;
    string w[MAX];
    i = p;
    j = q;
    k = 0;
    while(i<q && j<r){
        if(v[i]<v[j]){
            w[k] = v[i];
            i++;
        }else{
            w[k] = v[j];
            j++;
        }
        k++;
    }
    while(i<q){
        w[k] = v[i];
        i++;
        k++;
    }
    while(j<r){
        w[k] = v[j];
        j++;
        k++;
    }
    for(i= p;i<r;i++){
        v[i] = w[i-p];
    }

}
void imprime(int n,string v[MAX]){
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";
}