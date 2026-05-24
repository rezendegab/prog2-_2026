#include <iostream>
using namespace std;
#define MAX 100

bool verifica(int *v1,int*v2,int n1,int n2,int *soma);
int main(){
    int v1[MAX],v2[MAX],soma[MAX],n1,n2;
    cin>>n1;
    cin>>n2;
    for(int *p=v1;p<v1+n1;p++){
        cin>>*p;
    }
    for(int *q=v2;q<v2+n2;q++){
        cin>>*q;
    }
    if(verifica(v1,v2,n1,n2,soma)){
        cout<<"soma dos vetores: "<<endl;
        for(int *p=soma;p<soma+n1;p++){
            cout<<*p<<endl;
        }
    }
    else{
        cout<<"vetores de tamanhos diferentes"<<endl;
    }    
    return 0;
}
bool verifica(int *v1,int *v2,int n1,int n2,int *soma){
    if(n1!=n2)
        return false;
    int *p=v1,*q=v2,*s=soma;
    while(p<v1+n1){
        *s=*p+*q;
        p++;
        q++;
        s++;
    }
    return true;
}
