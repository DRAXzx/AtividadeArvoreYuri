#include <iostream>
using namespace std;

struct NoArvore
{
    int data;
    NoArvore *left;
    NoArvore *rigth;
};

NoArvore* newArvore(int num){
    NoArvore *raiz = new NoArvore;
    raiz->data = num;
    raiz->left = NULL;
    raiz->rigth = NULL;
    return raiz;
}

void inserir(NoArvore* &raiz, int valor){
    if(raiz == NULL){
        raiz = newArvore(valor);
    } else {
        if(valor < raiz->data){
            inserir(raiz->left, valor);
        } else {
            inserir(raiz->rigth, valor);
        }
    }
}

int contagem(NoArvore *raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1+ contagem(raiz->left) + contagem(raiz->rigth);
    }
}


int main(){
    NoArvore *arvore = NULL;

    inserir(arvore, 1);
    inserir(arvore, 2);
    inserir(arvore, 3);
    inserir(arvore, 4);
    inserir(arvore, 5);

    cout << "Numero de nos na arvore: " << contagem(arvore) << endl;
    // contagem(arvore);
    

    return 0;
}