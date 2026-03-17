#include <iostream>
#include <string>
using namespace std;
// struct data 
struct Data{
    int dia;
    int mes;
    int ano;
};

// struct de dados
struct Dados{
    string nome;
    string telefone;
    Data datanasc;
};
#define MAX 100
int main(){
    Dados dado[MAX];
    int n;
    int dia, mes;
    // variavel para ler o caractere '/' da data
    char c;
    cin >>n;
    // loop para ler os dados e armazenar no vetor de struct
    for (int i = 0; i < n; i++){
        getline(cin >> ws, dado[i].nome);
        cin >> dado[i].telefone;
        cin >>dado[i].datanasc.dia >>c>> dado[i].datanasc.mes >>c>> dado[i].datanasc.ano;
    }
    cin >> dia >> c >> mes;
    for (int i = 0; i < n; i++){
        if(dado[i].datanasc.dia == dia && dado[i].datanasc.mes == mes){
            cout<< "lista de aniversariantes dessa data: "<<" "<<dado[i].telefone<<" "<<dado[i].nome<<endl ;
        }
    
    }
    
    return 0;
}
