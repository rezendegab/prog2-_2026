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
void contar_chaves(LSC*);
void imprimir_LSC(LSC*);

int main(){
    LSC* l = cria_nova_LSC();
    inserir_lista_LSC(l,10);
    imprimir_LSC(l);
    inserir_lista_LSC(l,0);
    imprimir_LSC(l);
    inserir_lista_LSC(l,12);
    imprimir_LSC(l);
    inserir_lista_LSC(l,1);
    imprimir_LSC(l);
    inserir_lista_LSC(l,20);
    imprimir_LSC(l);
    cout<<"a quantidade de chaves na lista é: ";
    contar_chaves(l);
    imprimir_LSC(l);
    return 0;
}
//implementaçao das funçoes
LSC*cria_nova_LSC(){
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
void contar_chaves(LSC* lista){
    int contador = 0;
    for(No* p = lista->inicio;p!=nullptr;p=p->prox)
        contador++;
    cout<<contador<<endl;
}
void imprimir_LSC(LSC* lista){
    for(No*p = lista->inicio;p !=nullptr;p=p->prox)
        cout<<p->chave<<" ";
    cout<<endl;
}