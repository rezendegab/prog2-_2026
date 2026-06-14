#include <iostream>
using namespace std;

//struct do no
struct No{
    int chave;
    No* prox;
};
// struct da lista encadeada
struct LSC{
    No* inicio;
};
//prototipaçao das funçoes
LSC*cria_nova_LSC();
void inserir_lista_LSC(LSC*,int);
bool mesmo_conteudo(LSC*,LSC*);
void imprimir_LSC(LSC*);

int main(){
    LSC*l1= cria_nova_LSC();
    LSC*l2 = cria_nova_LSC();
    inserir_lista_LSC(l1,10);
    inserir_lista_LSC(l2,10);
    inserir_lista_LSC(l1,20);
    inserir_lista_LSC(l2,20);
    inserir_lista_LSC(l1,30);
    inserir_lista_LSC(l2,0);
    cout<<"as listas possuem o mesmo conteudo? "<<(mesmo_conteudo(l1,l2))<<endl;
    imprimir_LSC(l1);
    imprimir_LSC(l2);
    return 0;
}
//implmentaçao das funçoes
LSC* cria_nova_LSC(){
    LSC* lista = new LSC;
    lista->inicio = nullptr;
    return lista;
}
void inserir_lista_LSC(LSC* lista,int x){
    No* novo = new No;
    novo->chave = x;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    
}
bool mesmo_conteudo(LSC* l1,LSC*l2){
    No*p1 = l1->inicio;
    No*p2 = l2->inicio;
    while(p1!= nullptr && p2!= nullptr){
        if(p1->chave!= p2->chave)
            return false;
        p1= p1->prox;
        p2 = p2->prox;
    }
    return true;
}
void imprimir_LSC(LSC* lista){
    for(No* p =lista->inicio;p!=nullptr;p=p->prox)
        cout<<p->chave<<" ";
    cout<<endl;
}
