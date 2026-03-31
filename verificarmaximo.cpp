#include<iostream>
using namespace std;
#define MAX 20

int maximo(int,int[]);

int main(){
    int n,v[MAX];
    cin>> n;
    for (int i = 0; i < n; i++){
        cin>> v[i];
    }
    int max = maximo(n,v);
    cout<< "o elemento do valor maximo é "<<max<<endl;
    
    return 0;
}

int maximo(int n,int v[MAX]){
    int i,x;
    x = 0;
    for (i = 1; i < n; i++)
        if(x<v[i])
            x = v[i];
    return x;
}
