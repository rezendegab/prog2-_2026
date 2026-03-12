#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Dados {
    string numero;
    string nome;
    string setor;
    string data;
    int horas;
    float Salariohora;

};
struct Salario{
    string numero;
    string nome;
    float salarioSem;
};
#define MAX 100
int main(){
    Dados dados[MAX];
    Salario salario[MAX];
    int n;
    cin >> n;
    // leitura de dados
    for (int i = 0; i < n; i++){
        cin >> dados[i].numero;
        getline(cin >> ws, dados[i].nome);
        cin >> dados[i].setor;
        cin >> dados[i].data;
        cin >> dados[i].horas;
        cin >> dados[i].Salariohora;
        
    }
    // computaçao do salario do funcionario
    float computaSalario = 0;
    float horasExtras = 0 ;
    for (int i = 0; i < n; i++){
        salario[i].numero = dados[i].numero;
        salario[i].nome = dados[i].nome;
        salario[i].salarioSem = dados[i].horas * dados[i].Salariohora;
        computaSalario = salario[i].salarioSem;
        if(dados[i].horas > 40){
            horasExtras = 0.5* (dados[i].horas - 40)*(dados[i].Salariohora);
            computaSalario = salario[i].salarioSem + horasExtras;

        }
    }
    for (int i = 0; i < n; i++){
        cout<< salario[i].numero << " " << salario[i].nome<<" "<<setprecision(2)<<computaSalario<<endl;
    }
    
    
    
    return 0;
}
