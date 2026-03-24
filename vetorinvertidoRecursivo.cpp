#include <iostream>
using namespace std;

#define MAX 20

void inverte(int v[], int n, int i);

int main(){
    int n,i;
    int v[MAX];
    cin >> n;
    for(i =0;i<n;i++){
        cin>>v[i];
    }
    cout<<"vetor original ";
    for(i =0;i<n;i++){
        cout<<v[i]<<" ";
    }
    inverte(v,n,0);
    cout<<"Vetor invertido"<<endl;
    for(i =0;i<n;i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}

void inverte(int v[],int n, int i){
    if(i>=n/2)
        return;    
    int temp;
    temp = v[i];
    v[i] = v[n-1-i];
    v[n-1-i] = temp;
    inverte(v,n,i+1);
}