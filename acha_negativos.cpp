#include <iostream>
using namespace std;
#define MAX 100

int negativos(float*vet,int N);

int main(){
    float vet[MAX];
    int N;
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>vet[i];
    }
    negativos(vet,N);
    return 0;
}

int negativos(float *vet,int N){
    int acha = 0;
    for(int i = 0;i<N;i++){
        if(vet[i]<0){
            acha++;
        }
    }
    cout<<"numeros negativos achados: "<<acha<<endl;
    return acha;
}