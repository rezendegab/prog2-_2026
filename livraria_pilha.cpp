#include<iostream>
using namespace std;

//struct da devoluçao
struct devolucao{
    string livro;
    string ISBN;
    string nomeAluno;
    int codigo;
};
//struct do No
struct No{
    devolucao* dev;
    No* prox;
};
//struct da pilha
struct Pilha{
    No* topo;
};
//protipaçao das funçoes
Pilha* criarPilhaVazia();
devolucao* criaDevolucao();
void empilhar(Pilha*,devolucao*);
void desempilhar(Pilha*);
void exebirPilha(Pilha*);

int main(){
    int N1,N2;
    cin>>N1;
    Pilha* p = criarPilhaVazia();
    for(int i=0;i<N1;i++){
        devolucao* dev= criaDevolucao();
        empilhar(p,dev);
    }
    cin>>N2;
    for(int i =0;i<N2;i++){
        desempilhar(p);
    }
    exebirPilha(p);
    return 0;
}
Pilha* criarPilhaVazia(){
    Pilha* p = new Pilha;
    p->topo = nullptr;
    return p;
}
devolucao* criaDevolucao(){
    devolucao* dev = new devolucao;
    cin>>dev->livro;
    cin>>dev->ISBN;
    cin>>dev->nomeAluno;
    cin>>dev->codigo;
    return dev;
}
void empilhar(Pilha* p,devolucao*dev){
    No* novo = new No;
    novo->dev = dev;
    novo->prox = p->topo;
    p->topo = novo;
}
void desempilhar(Pilha* p){
    if(p->topo == nullptr){
        return;
    }else{
        cout<<p->topo->dev->livro<<" "<<p->topo->dev->ISBN<<endl;
        No* aux = p->topo;
        p->topo = p->topo->prox;
        delete aux->dev;
        delete aux;
    }
}
void exebirPilha(Pilha* p){
    for(No* pt = p->topo;pt;pt=pt->prox){
        cout<<pt->dev->livro<<" "<<pt->dev->ISBN<<endl;
    }
    cout<<endl;
}