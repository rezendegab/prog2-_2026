#include <iostream>
using namespace std;

//struct do no
struct No{
    int chave;
    No* prox;
};

// struct da lista
struct LSC{
    No* inicio;
};
//protipaçao das funçoes
LSC* cria_lista_vazia();
void inserir_ordenado(LSC*,int);
void remover_ordenado(LSC*,int);
void imprimir_lista(LSC*);

int main(){
    LSC* l = cria_lista_vazia();
    inserir_ordenado(l,5);
    imprimir_lista(l);
    inserir_ordenado(l,3);
    imprimir_lista(l);
    inserir_ordenado(l,6);
    imprimir_lista(l);
    inserir_ordenado(l,1);
    imprimir_lista(l);
    inserir_ordenado(l,2);
    imprimir_lista(l);
    inserir_ordenado(l,4);
    imprimir_lista(l);
    remover_ordenado(l,3);
    imprimir_lista(l);
    remover_ordenado(l,1);
    imprimir_lista(l);
    remover_ordenado(l,4);
    imprimir_lista(l);
    remover_ordenado(l,6);
    imprimir_lista(l);
    remover_ordenado(l,2);
    imprimir_lista(l);
    remover_ordenado(l,5);
    imprimir_lista(l);
    return 0;
}
LSC* cria_lista_vazia(){
    LSC* lista = new LSC;
    lista->inicio = nullptr;
    return lista;
}
void inserir_ordenado(LSC* lista, int x){
    No* novo = new No;
    novo->chave = x;
    novo->prox = nullptr;
    if(lista->inicio == nullptr|| lista->inicio->chave>=x){
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }else{
        No* atual = lista->inicio;
        while(atual->prox !=nullptr && atual->prox->chave <x){
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}
void remover_ordenado(LSC* lista,int x){
    if(lista->inicio == nullptr){
        return;
    }
    if(lista->inicio->chave == x){
        No* atual = lista->inicio;
        lista->inicio = lista->inicio->prox;
        delete atual;
    }
    No* atual = lista->inicio;
    while(atual->prox != nullptr && atual->prox->chave!=x){
        atual = atual->prox;
    }
    if(atual->prox != nullptr){
        No* aux = atual->prox;
        atual->prox = atual->prox->prox;
        delete aux;
    }
}
void imprimir_lista(LSC* lista){
    for(No* p = lista->inicio;p!=nullptr;p=p->prox)
        cout<<p->chave<<" ";
    cout<<endl;

}
