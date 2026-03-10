#include <iostream>
using namespace std;

struct Produto{
	string numero;
	string nome;
	int estoque;
	int estMin;
	float custo;
	float venda;
};
struct Lucro{
	string numero;
	string nome;
	float lucroEst;
	
};
# define MAX 100
int main(){
	Produto produto [MAX];
	Lucro lucro[MAX];
	// leitura do numero produtos
	int n;
	cin >> n;
	//leitura dos dados do produtos
	for (int i = 0; i < n; i++){
		cin >> produto[i].numero;
		cin >> produto[i].nome;
		cin >> produto[i].estMin;
		cin >> produto[i].estoque;
		cin >> produto[i].custo;
		cin >> produto[i].venda;    
	}
	//calculo dos possiveis lucros
	for (int i = 0; i < n; i++){
		lucro[i] = produto[i].estoque *(produto[i].venda - produto[i].custo);
	}
	return 0;
}