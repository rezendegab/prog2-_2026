#include <iostream>
using namespace std;

#define MAX 100
//protipaçao de funçao
void identidade(int, int[MAX][MAX]);
void imprimeMatriz(int, int[MAX][MAX]);

int main(){
    int n, v[MAX][MAX];

    cin >> n;

    identidade(n, v);
    imprimeMatriz(n, v);

    return 0;
}
//implementaçao da funçao
void identidade(int n, int v[MAX][MAX]){
    int *p;
    int pos, lin, col;

    for(p = &v[0][0]; p <= (&v[0][0] + MAX*MAX); p++){

        pos = p - &v[0][0];

        lin = pos / MAX;
        col = pos % MAX;
        if(lin<n&&col<n){
            if(lin ==  col)
                *p = 1;
            else
                *p = 0;
        }
    }
}

void imprimeMatriz(int n, int v[MAX][MAX]){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout << v[i][j] << " ";
        }

        cout << endl;
    }
}
