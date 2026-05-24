#include <iostream>
using namespace std;
#define MAX 100

struct Elemento{
	int valor;
	int id_original;
};

//prototipçao das funçoes
void bubbleSort(int,Elemento[]);
void insertionSort(int,Elemento[]);
void mergeSort(int,int,Elemento[]);
void merge(int, int,int,Elemento[]);
void quickSort(int,int,Elemento[]);
int partition(int,int,Elemento[]);
void troca(Elemento &,Elemento&);
void imprime(int,Elemento[]);
bool verificaEstabilidade(int,Elemento[]);

int main(){
	Elemento org[MAX];
	int n;
	cout<<"Digite o tamanho do vetor: "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Digite o valor "<<i<<": ";
		cin>>org[i].valor;
		org[i].id_original = i;
	}
	Elemento bubble[MAX];
	Elemento insertion[MAX];
	Elemento mergeV[MAX];
	Elemento quick[MAX];
	for(int i = 0;i<n;i++){
		bubble[i] = org[i];
		insertion[i] = org[i];
		mergeV[i] = org[i];
		quick[i] = org[i];
	}
	// estabilidade do bubble
	bubbleSort(n,bubble);
	cout<<"bubbleSort: "<<endl;
	imprime(n,bubble);
	if(verificaEstabilidade(n,bubble))
		cout<<"Estavel"<<endl;
	else
		cout<<"Instavel"<<endl;
	// estabilidade do insertion
	insertionSort(n,insertion);
	cout<<"insertionSort: "<<endl;
	imprime(n,insertion);
	if(verificaEstabilidade(n,insertion))
		cout<<"Estavel"<<endl;
	else
		cout<<"Instavel"<<endl;
	// estabilidade do merge
	mergeSort(0,n,mergeV);
	cout<<"mergeSort: "<<endl;
	imprime(n,mergeV);
	if(verificaEstabilidade(n,mergeV))
		cout<<"Estavel"<<endl;
	else
		cout<<"Instavel"<<endl;
	// estabilidade do quick
	quickSort(0,n-1,quick);
	cout<<"quickSort: "<<endl;
	imprime(n,quick);
	if(verificaEstabilidade(n,quick))
		cout<<"Estavel"<<endl;
	else
		cout<<"Instavel"<<endl;

	return 0;
}

//implementaçao das funçoes bubblesort,insertionsort,mergesort,merge,quicksort,partition,troca,imprime e verfica estabilidade
void bubbleSort(int n,Elemento v[MAX]){
	for(int i=n-1;i>0;i--)
		for(int j=0;j<i;j++)
			if(v[j].valor>v[j+1].valor)
				troca(v[j],v[j+1]);
}
void insertionSort(int n,Elemento v[MAX]){
	for(int i = 1;i<n;i++){
		Elemento x = v[i];
		int j;
		for(j=i-1;j>=0 && v[j].valor>x.valor;j--)
			v[j+1]=v[j];
		v[j+1] = x;
	}
}
void mergeSort(int p,int r,Elemento v[MAX]){
	if(p<r-1){
		int q=(p+r)/2;
		mergeSort(p,q,v);
		mergeSort(q,r,v);
		merge(p,q,r,v);
	}
}
void merge(int p,int q,int r,Elemento v[MAX]){
	Elemento w[MAX];
	int i,j,k;
	i =p;
	j=q;
	k=0;
	while(i<q && j<r){
		if(v[i].valor <= v[j].valor){
			w[k]=v[i];
			i++;
		}else{
			w[k]=v[j];
			j++;
		}
		k++;
	}
	while(i<q){
		w[k] = v[i];
		i++;
		k++;
	}
	while(j<r){
		w[k] = v[j];
		j++;
		k++;
	}
	for(i =p;i<r;i++)
		v[i]=w[i-p];
}
void quickSort(int p,int r, Elemento v[MAX]){
	if(p<r){
		int q = partition(p,r,v);
		quickSort(p,q-1,v);
		quickSort(q+1,r,v);
	}
}
int partition(int p,int r,Elemento v[MAX]){
	Elemento x = v[r];
	int i = p-1;
	for(int j = p;j<r;j++){
		if(v[j].valor<= x.valor){
			i++;
			troca(v[i],v[j]);
		}
	}
	troca(v[i+1],v[r]);
	return i+1;
}
void troca(Elemento &a,Elemento &b){
	Elemento aux;
	aux = a;
	a =b;
	b = aux;
}

void imprime(int n,Elemento v[MAX]){
	for(int i = 0;i<n;i++){
		cout<<"("<<v[i].valor<<","<<v[i].id_original<<") ";
	}
	cout<<"\n\n";
}
bool verificaEstabilidade(int n,Elemento ord[MAX]){
	for(int i = 0;i<n-1;i++){
		if(ord[i].valor==ord[i+1].valor){
			if(ord[i].id_original>ord[i+1].id_original)
				return false;
		}

	}
	return true;
}