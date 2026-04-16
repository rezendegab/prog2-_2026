#include <iostream>
using namespace std;
#define MAX 100

void bubble_sort(int ,int[]);
void troca(int &,int&);

int main(){
    int n,v[MAX];
    cin>> n;
    for(int i=0;i<n;i++){
        cin>>v[i];
        bubble_sort(n,v);
        if((v[i]-v[i+1]) == v[i+2])
            cout<<"alternante "<<endl;
        else
            cout<<"Não alternante "<<endl;

    }
    return 0;
}

void bubble_sort(int n,int v[MAX]){
    for(int i = n-1;i>n;i--)
        for(int j = 0;j<i;j++)
            if(v[j]>v[j+1])
                troca(v[j],v[j+1]);
}
void troca(int &a,int&b){
    int aux;
    aux = a;
    a= b;
    b = aux;
}