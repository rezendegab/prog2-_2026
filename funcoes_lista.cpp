#include <iostream>
using namespace std;

//struct No
struct No{
    int chave;
    No* prox;
};
//struct da lista
struct LSC{
    No*inicio;
};

//protipaçao das funçoes
LSC* criar_lista();
void inserir(LSC*,int);
void rodar(LSC*);
void inverter(LSC*);
LSC* soma(LSC*);
void imprimir(LSC*);

int main(){
    LSC* l = criar_lista();
    inserir(l,1);
    imprimir(l);
    inserir(l,2);
    imprimir(l);
    inserir(l,3);
    imprimir(l);
    inserir(l,4);
    imprimir(l);
    inserir(l,5);
    imprimir(l);
    cout<<"------------------"<<endl;
    cout<<"rodar: "<<endl;
    rodar(l);
    imprimir(l);
    cout<<"inveter: "<<endl;
    inverter(l);
    imprimir(l);
    cout<<"soma: "<<endl;
    LSC* R = soma(l);
    imprimir(R);
    return 0;
}
//implementaçao das funçoes
LSC* criar_lista(){
    LSC* lista = new LSC;
    lista->inicio = nullptr;
    return lista;
}
void inserir(LSC* lista, int x){
    No* novo;
    No* ant;
    No*atual;
    novo = new No;
    novo->chave = x;
    ant = nullptr;
    atual = lista->inicio;
    while(atual&&atual->chave <x){
        ant = atual;
        atual = atual->prox;
    }
    novo->prox = atual;
    if(ant)
        ant->prox = novo;
    else
        lista->inicio = novo;
}
void rodar(LSC* lista){
    // p = primeiro e l = ultimo
    No*p = lista->inicio;
    lista->inicio = p->prox;
    No* l = lista->inicio;
    while(l->prox)
        l = l->prox;
    l->prox = p;
    p->prox = nullptr;
}
void inverter(LSC* lista){
    No* ant = nullptr;
    No* atual = lista->inicio;
    No* prox;
    while(atual){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    lista->inicio = ant;
}

LSC* soma(LSC* lista){
    int soma = 0;
    for(No* p = lista->inicio;p!=nullptr;p=p->prox)
        soma += p->chave;
    LSC* R = criar_lista();
    No* novo = new No;
    novo->chave = soma;
    novo->prox = nullptr;
    R->inicio = novo;

    return R;
}
void imprimir(LSC* lista){
    for(No* p = lista->inicio;p!=nullptr;p=p->prox)
        cout<<p->chave<<" ";
    cout<<endl;

}