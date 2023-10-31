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

void par(NoArvore *raiz){
    if(raiz != NULL){
        par(raiz->left);
        if(raiz->data % 2 == 0){
            cout << raiz->data << " ";
        }
        par(raiz->rigth);
    }
}

void impar(NoArvore *raiz){
    if(raiz != NULL){
        impar(raiz->left);
        if(raiz->data % 2 != 0){
            cout << raiz->data << " ";
        }
        impar(raiz->rigth);
    }
}

int main(){
    NoArvore *arvore = NULL;

    inserir(arvore,2);
    inserir(arvore,7);
    inserir(arvore,2);
    inserir(arvore,6);
    inserir(arvore,5);
    inserir(arvore,11);
    inserir(arvore,5);
    inserir(arvore,9);
    inserir(arvore,4);

    cout << "\nElementos pares: \n";
    par(arvore);
    cout << endl;

    cout << "\nElementos Impares:\n";
    impar(arvore);
    
    
    return 0;

}