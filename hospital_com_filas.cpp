#include <iostream>
using namespace std;

//sturct do paciente
struct paciente{
    string nome;
    string cpf;
    int idade;
    int prioridade;
};
//struct do no
struct No{
    paciente *p;
    int chave;
    No* prox;
};
//struct da fila
struct Fila{
    No*inicio;
    No*fim;
};
//protipaçao das funçoes
Fila* criarFilaVazia();
paciente* criarPaciente();
void enfileirar(Fila*,paciente*);
void desenfileirar(Fila*);
void exibirFila(Fila*);

int main(){
    Fila *f = criarFilaVazia();
    paciente *p1 = criarPaciente();
    p1= criarPaciente();
    enfileirar(f,p1);
    p1= criarPaciente();
    enfileirar(f,p1);
    p1= criarPaciente();
    enfileirar(f,p1);
    p1= criarPaciente();
    enfileirar(f,p1);
    exibirFila(f);
    desenfileirar(f);
    desenfileirar(f);
    exibirFila(f);

    return 0;
}
//implementaçao das funçoes
Fila* criarFilaVazia(){
    Fila *f = new Fila;
    f->inicio = nullptr;
    f->fim = nullptr;
    return f;
}
paciente*criarPaciente(){
    paciente *p = new paciente;
    getline(cin>> ws,p->nome);
    getline(cin>> ws,p->cpf);
    cin>> p->idade;
    cin>>p->prioridade;
    return p;
    
}
void enfileirar(Fila *f,paciente* p){
    No* novo = new No;
    novo->p = p;
    novo->prox = nullptr;
    if(f->fim !=nullptr){
        f->fim->prox = novo;
        f->fim = novo;
    }else{
        f->inicio = f->fim = novo;
    }
}
void desenfileirar(Fila* f){
    if(f->inicio == nullptr){
        cout<<"Fila vazia"<<endl;
    }else{
        No* aux = f->inicio;
        f->inicio = f->inicio->prox;
        if(f->inicio == nullptr)
            f->fim=nullptr;
        delete aux;
    }
}
void exibirFila(Fila*f){
    for(No* ptr= f->inicio;ptr;ptr=ptr->prox){
        cout<<"Nome: "<<ptr->p->nome<<endl;
        cout<<"CPF: "<<ptr->p->cpf<<endl;
        cout<<"Idade: "<<ptr->p->idade<<endl;
        cout<<"Prioridade: "<<ptr->p->prioridade<<endl;
        cout<<"-----------------------------"<<endl;
    }
    cout<<endl;
}

