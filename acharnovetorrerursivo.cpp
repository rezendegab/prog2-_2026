#include <iostream>
using namespace std;
#define MAX 20

// protipaçao da funçao
bool busca(int v[], int inicio,int fim,int x);

int main(){
    int v[MAX],n,x;
    cin>> n;
    for(int i = 0; i<n;i++){
        cin>> v[i];
        if(v[i]>v[i+1]){
            v[i+1] = v[i];
        }
    }
    cin>>x;
    busca(v,0,n-1,x);
    return 0;
}
//desevolvimento da funçao de busca recursiva
bool busca(int v[],int inicio,int fim,int x){
    if(inicio>fim){
        return false;
    }
    int meio = (inicio+fim)/2;
    if(v[meio] ==x){
        return true;
    }
    if(v[meio]>x){
        return busca(v,inicio,meio -1,x);
    }
    else{
        return busca(v,meio+1,fim,x);
    }
}