#include <iostream>
using namespace std;
#define MAX 100

int*maximo(int ,int []);

int main(){
    int n,v[MAX];
    int *max;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    max = maximo(n,v);
    cout<<"Maior elemento é: "<<*max<<endl;
    return 0;
}


int*maximo(int n,int v[MAX]){
    int *p;
    p= &v[0];
    for(int i = 1;i<n;i++)
        if(v[i]>*p)
            p = &v[i];
    return p;
}