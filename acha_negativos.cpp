#include <iostream>
using namespace std;
#define MAX 100
//prototipaçao da funçao negativos
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
//implementaçao da funçao negativos
int negativos(float *vet,int N){
    int acha = 0;//variavel para achar negativos
    for(int i = 0;i<N;i++){
        if(vet[i]<0){
            acha++;
        }
    }
    cout<<"numeros negativos achados: "<<acha<<endl;
    return acha;
}
