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

void destruirArvore(NoArvore* &raiz){
    if(raiz != NULL){
        destruirArvore(raiz->left);
        destruirArvore(raiz->rigth);
        delete raiz;
        raiz = NULL;
    }
}

void printArvore(NoArvore *raiz){
    if(raiz != NULL){
        printArvore(raiz->left);
        cout << raiz->data << " ";
        printArvore(raiz->rigth);
    }
}

int main(){
    NoArvore *arvore = NULL;

    inserir(arvore, 1);
    inserir(arvore, 2);
    inserir(arvore, 3);
    inserir(arvore, 4);
    inserir(arvore, 5);

    cout << "Arvore:" << endl;
    printArvore(arvore);
    cout << endl;
    cout << "Dps de destruir" << endl;
    destruirArvore(arvore);

    if(arvore == NULL){
        cout << "Arvore delatada" << endl;
    } else {
        cout << "ERRO" << endl;
    }

    return 0;
}