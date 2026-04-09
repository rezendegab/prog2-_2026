#include<iostream>
using namespace std;
#define MAX 100

void insertion_sort(string v[MAX],int n);
void imprime(string v[MAX],int n);
int main(){
    string v[MAX];
    int n;
    cin>> n;
    cin.ignore();
    for(int i = 0;i<n;i++){
        getline(cin,v[i]);
    }
    cout<<"lista de nomes sem ordenação "<<endl;
    imprime(v,n);
    insertion_sort(v,n);
    cout<<"lista de nomes com ordenação "<<endl;
    imprime(v,n);
    return 0;
}

void insertion_sort(string v[MAX],int n){
    for(int i = 1;i<n;i++){
        string x = v[i];
        int j = i-1;
        while(j>=0&&v[j]>x){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] =x;
    }

}
void imprime(string v[MAX],int n){
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";
}