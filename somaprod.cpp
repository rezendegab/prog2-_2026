#include <iostream>
using namespace std;
#define MAX 100

void soma_prod(int,int ,int *,int *);

int main(){
	int n,v[MAX];
	cin>>n;
	for (int i = 0; i < n; i++){
		cin>>v[i];
	}
	int somaAcc,prodAcc,lixo;
	soma_prod(v[0],v[1],&somaAcc,&prodAcc);
	for (int i = 2; i < n; i++){
		soma_prod(somaAcc,v[i],&somaAcc,&lixo);
		soma_prod(prodAcc,v[i],&lixo,&prodAcc);	
	}
	cout<<"maiores da soma = "<<somaAcc<<" "<<"maiores do produto = "<<prodAcc<<endl;
	return 0;
}


void soma_prod(int a,int b,int *soma,int *prod){
	*soma = a+b;
	*prod = a*b;
}