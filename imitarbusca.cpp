#include <iostream>
using namespace std;
#define MAX 20

int busca(int,int [],int);

int main(){
    int v[MAX];
    int n,x;
    cout<< "digite o tamanho do vetor ";
    cin >> n;
    cout<<"digite os elementos do vetor ";
    for (int i = 0; i < n; i++){
        
        cin>> v[i];
    }
    cout<<"digite o valor que quer encotrar ";
    cin >> x;
    
    int chama = busca(n,v,x);
    if(v[chama] == x){
        cout<< "valor encontrado  o : "<<x<<" na posição "<<chama<<endl;
    }else{
        cout<< "valor não encontrado"<<endl;
    }
    
    return 0;
}

int busca(int n,int v[MAX],int x){
    v[n] = x;
    int i;
    for(i = 0;v[i]!=x;i++);
    if(i<n){
        return i;
    }else{
        return -1;
    }

}