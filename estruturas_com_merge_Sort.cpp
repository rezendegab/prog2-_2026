#include<iostream>
using namespace std;
#define MAX 100

//struct de pessoas
struct pessoa{
    string nome;
    int idade;
};

//prototipçao das funçoes
void mergeSort(int,int,pessoa p[MAX]);
void merge(int,int,int,pessoa p[MAX]);
void imprime(int n,pessoa p[MAX]);

int main(){
    pessoa ps[MAX];
    int n;
    cout<<"Digite a quantidade de pessoas: "<<endl;
    cin>>n;
    for(int i =0;i<n;i++){
        getline(cin>>ws,ps[i].nome);
        cin>>ps[i].idade;
    }
    mergeSort(0,n,ps);
    imprime(n,ps);
    return 0;
}

void mergeSort(int p,int r,pessoa ps[MAX]){
    if(p<r-1){
        int q=(p+r)/2;
        mergeSort(p,q,ps);
        mergeSort(q,r,ps);
        merge(p,q,r,ps);
    }

}
void merge(int p,int q,int r,pessoa ps[MAX]){
    int i,j,k;
    pessoa w[MAX];
    i=p;
    j=q;
    k = 0;
    while(i<q &&j<r){
        if(ps[i].idade<=ps[j].idade){
            w[k]=ps[i];
            i++;
        }else{
            w[k]=ps[j];
            j++;
        }
        k++;

    }
    while(i<q){
        w[k]=ps[i];
        i++;
        k++;

    }
    while(j<r){
        w[k]=ps[j];
        j++;
        k++;
    }
    for(i=p;i<r;i++){
        ps[i]= w[i-p];
    }
}
void imprime(int n,pessoa ps[MAX]){
    for(int i = 0;i<n;i++)
        cout<<ps[i].nome<<" "<<ps[i].idade<<endl;
    cout<<"\n\n"<<endl;
}