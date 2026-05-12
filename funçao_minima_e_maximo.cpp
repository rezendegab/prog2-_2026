#include <iostream>
using namespace std;
#define MAX 100

void min_max(int,int[],int*,int*);

int main(){
    int n,v[MAX],a,b;
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>v[i];
    min_max(n,v,&a,&b);
    return 0;
}


void min_max(int n,int v[MAX],int*max,int*min){
    *max = v[0];
    *min =v[0];
    for(int i = 0;i<n;i++){
        if(v[i]>*max)
            *max = v[i];
        if(v[i]<*min)
            *min=v[i];
    }
    cout<<"o valor minimo: "<<*min<<" "<<"valor maximo: "<<*max<<endl;

}
