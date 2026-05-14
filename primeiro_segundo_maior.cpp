#include <iostream>
using namespace std;
#define MAX 100

//prottipaçao de funçao
void dois_maiores(int,int[],int*,int*);
void troca(int*,int*);
int main(){
    int n,v[MAX],pri,seg;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>> v[i];
    }
    dois_maiores(n,v,&pri,&seg);
    return 0;
}

//implemntaçao de funçao
void dois_maiores(int n,int v[MAX],int* pri,int*seg){
    *pri = v[0];
    *seg = v[1];
    if(*pri<*seg)
        troca(pri,seg);
    for(int i=2;i<n;i++){
        if(v[i]>*pri){
            *seg = *pri;
            *pri = v[i];
        }else if(v[i]>*seg)
            *seg = v[i];
        
    }
    cout<<"primeiro maior elemento "<<*pri<<" "<<"segundo maior elemento: "<<*seg<<endl;

}
void troca(int* a,int* b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;

}