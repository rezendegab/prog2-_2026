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
//protipaçao das funçoes
LSC*cria_nova_LSC();
void vet_para_lst(int vet[],int,LSC*);
int lst_para_vet(LSC*,int vet[],int);
void imprimir_LSC(LSC*);
void imprimir_vet(int vet[],int);

int main(){
    LSC* l = cria_nova_LSC();
    int vet[5]={3,4,2,1,5};
    vet_para_lst(vet,5,l);
    cout<<"lista copiada do vetor: "<<endl;
    imprimir_LSC(l);
    int vet2[5];
    lst_para_vet(l,vet2,5);
    cout<<"vetor copiado da lista: "<<endl;
    imprimir_vet(vet2,5);
    return 0;
}
//implementaçao das funçoes
LSC*cria_nova_LSC(){
    LSC* lista = new LSC;
    lista->inicio = nullptr;
    return lista;
};
void vet_para_lst(int vet[],int n,LSC*lista){
    for(int i = 0;i<n;i++){
        No* novo = new No;
        novo->chave = vet[i];
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
}
int lst_para_vet(LSC* lista, int vet[],int n){
    No* aux = lista->inicio;
    int i;
    for(i = 0;i<n &&aux != nullptr;i++){
        vet[i]= aux->chave;
        aux = aux->prox;
    }
    return i;
}
void imprimir_LSC(LSC* lista){
    for(No* p= lista->inicio;p!=nullptr;p=p->prox)
        cout<<p->chave<<" ";
    cout<<endl;
}
void imprimir_vet(int vet[],int n){
    for(int i = 0;i<n;i++)
        cout<<vet[i]<<" ";
    cout<<endl;
}