#include <iostream>
using namespace std;

// struct do no
struct No{
    int chave;
    No* prox;
};
// struct da lista encadeada
struct LSC{
    No*inicio;
};
//protipaçao de funçoes
LSC* cria_nova_lista();
void insere_lista(LSC*,int);
bool busca_remove_chave_lista(LSC*,int);
void imprime_lista(LSC*);

int main(){
    LSC* l = cria_nova_lista();
    insere_lista(l,47);
    imprime_lista(l);
    insere_lista(l,19);
    imprime_lista(l);
    insere_lista(l,5);
    imprime_lista(l);
    insere_lista(l,4);
    imprime_lista(l);
    insere_lista(l,20);
    imprime_lista(l);
    busca_remove_chave_lista(l,5);
    imprime_lista(l);
    return 0;
}
LSC* cria_nova_lista(){
    LSC* lista= new LSC;
    lista->inicio = nullptr;
    return lista;

}
void insere_lista(LSC* lista,int x){
    No* ptr= new No;
    ptr->chave = x;
    ptr->prox = lista->inicio;

    lista->inicio = ptr;
}
bool busca_remove_chave_lista(LSC* lista,int x){
    No*ant = NULL;
    No*p=lista->inicio;
    /*while (p!=nullptr && p->chave!=x){
        ant = p;
        p=p->prox;
    }*/
   while (p->chave!=x&&p!=nullptr){
        ant = p;
        p=p->prox;
   }
    if(p==nullptr)
        return false;
    if(ant == nullptr){
        lista->inicio= p->prox;
    }else{
        ant->prox= p->prox;
    }
    delete p;
    return true;
    

}
void imprime_lista(LSC* lista){
    for(No*p=lista->inicio;p!=nullptr;p=p->prox)
        cout<<p->chave<<" ";
    cout<<endl;
}