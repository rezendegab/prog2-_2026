#include <iostream>
#include<climits>
using namespace std;

//struct data
struct data{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

//struct informaçao do departamento
struct informacao{
    int chamado;
    string nomesolicitante;
    string departamento;
    string descricao;
    int complexidade;
    data d;
};

//struct do no
struct No{
    informacao *info;
    No* prox;
};
//struct da pilha
struct pilha{
    No* topo;
};

//protipaçao das funçoes
pilha* criarPilhaVazia();
informacao* criarInfo();
void empilhar(pilha*,informacao*);
void atender(pilha*);
void buscarChamado(pilha*,int);
void exibirPendentes(pilha*);

int main(){
    pilha*p= criarPilhaVazia();
    informacao*info;
    info= criarInfo();
    empilhar(p,info);
    info= criarInfo();
    empilhar(p,info);
    info= criarInfo();
    empilhar(p,info);
    buscarChamado(p,202);
    atender(p);
    exibirPendentes(p);

    return 0;
}
//implementaçao das funcoes
pilha* criarPilhaVazia(){
    pilha *p = new pilha;
    p->topo = nullptr;
    return p;
}
informacao* criarInfo(){
    informacao * info = new informacao;
    cin>>info->chamado;
    getline(cin>>ws,info->nomesolicitante);
    getline(cin>>ws,info->departamento);
    getline(cin>>ws,info->descricao);
    cin>>info->complexidade;
    cin>>info->d.dia;
    cin>>info->d.mes;
    cin>>info->d.ano;
    cin>>info->d.hora;
    cin>>info->d.minuto;
    return info;
}
void empilhar(pilha *p,informacao *info){
    for(No*ptr = p->topo;ptr;ptr = ptr->prox){
        if(ptr->info->chamado == info->chamado){
            cout<<"chamado ja existe"<<endl;
            return;
        }
    }
    No*novo = new No;
    novo->info = info;
    novo->prox = p->topo;
    p->topo = novo;
}
void atender(pilha *p){
    if(p->topo == nullptr){
        cout<<"não a chamadas pedentes"<<endl;
    }else{
        cout<<"=========Relatorio========== "<<endl;
        cout<<"chamado: "<<p->topo->info->chamado<<endl;
        cout<<"solicitante: "<<p->topo->info->nomesolicitante<<endl;
        cout<<"departamento: "<<p->topo->info->departamento<<endl;
        cout<<"descricao: "<<p->topo->info->descricao<<endl;
        cout<<"complexidade: "<<p->topo->info->complexidade<<endl;
        cout<<"data: "<<endl;
        cout<<p->topo->info->d.dia<<"/"<<p->topo->info->d.mes<<"/"<<p->topo->info->d.ano<<endl;
        cout<<"hora: "<<endl;
        cout<<p->topo->info->d.hora<<":"<<p->topo->info->d.minuto<<endl;
        No*aux = p->topo;
        p->topo = p->topo->prox;
        delete aux->info;
        delete aux;
    }
}
void buscarChamado(pilha *p,int x){
    No* aux = p->topo;
    while(aux){
        if(aux->info->chamado == x){
            cout<<"chamado: "<<aux->info->chamado<<endl;
            cout<<"solicitante: "<<aux->info->nomesolicitante<<endl;
            cout<<"departamento: "<<aux->info->departamento<<endl;
            cout<<"descricao: "<<aux->info->descricao<<endl;
            cout<<"complexidade: "<<aux->info->complexidade<<endl;
            cout<<"data: "<<endl;
            cout<<aux->info->d.dia<<"/"<<aux->info->d.mes<<"/"<<aux->info->d.ano<<endl;
            cout<<"hora: "<<endl;
            cout<<aux->info->d.hora<<":"<<aux->info->d.minuto<<endl;
            return;
        }
        aux = aux->prox;
    }
    cout << "Chamado nao encontrado" << endl;
}
void exibirPendentes(pilha *p){
    for(No*ptr = p->topo;ptr;ptr=ptr->prox){
        cout<<"codigo: "<<ptr->info->chamado<<endl;
        cout<<"solicitante: "<<ptr->info->nomesolicitante<<endl;
        cout<<"complexidade: "<<ptr->info->complexidade<<endl;
    }
    cout<<"--------------------------------------"<<endl;
}