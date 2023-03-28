/*

O que é uma Fila dinâmica como é conhecida sua sigla em inglês? ​
Uma fila dinâmica é uma "fila" que perde os dados quando removidos, já na fila circular dinÂmica não existe esse problema pois não ocorre a derda de dados.
Sigla em inglês: Queue

Qual a sua vantagem em relação a uma Fila estática?​
Ocupa só o espaço que é estritamente necessário.

*/

#include <stdio.h>
#include <stdlib.h>

//Essa estrutura armazena o valor e o próximo da fila
struct no{
    int valor;
    struct no *prox;
};

//Definimos um TIPO e chamamos de Elemento
typedef struct no Elemento;

//A estrutura fila irá manter dois ponteiros, um para o inicio e outro para o fim
struct fila{
    Elemento *inicio;
    Elemento *fim;
};

//A partir da estrutura fila criamos o TIPO Fila
typedef struct fila Fila;

//Criar fila
Fila q;

//Função que inicia aloca memória e aponta para NULL
void criaFila(Fila *q){
    q = (Fila*)malloc(sizeof(Fila));
    q->inicio = NULL;
    q->fim = NULL;
}

//Função que insere elementos na fila
int inserirElemento(Fila *q, int valor){
    //Alocando espaço para um novo elemento
    Elemento *p = (Elemento*)malloc(sizeof(Elemento));

    if(p == NULL){
        return 0;
    }

    //Atribui valor ao elemento
    p->valor = valor;

    //Verifica se a fila está vazia
    if(q->inicio == NULL){
        q->inicio = p;
    }
    else{
        //Anterior sempre aponta para o elemento que chega
        q->fim->prox = p;
    }

    //Fim passa a ser o que chega
    q->fim = p;

    printf("inserindo %d \n\n", q->fim->valor);
    return 1;
}

//Função que remove elementos da fila
int removeElemento(Fila *q){
    int valor;

    //Fila Vazia
    if(q->inicio == NULL){
        printf("Fila Vazia \n");
        return 0;
    }

    valor = q->inicio->valor;

    Elemento *aux = q->inicio;
    //Muda o inicio para o próximo
    q->inicio = q->inicio->prox;

    free(aux);

    printf("Removendo %d \n\n", valor);
    return valor;
}


//Imprime a fila
void imprimeFila(Fila *q){
    Elemento *prox = q->inicio;
  if( q->inicio == NULL ) {
      printf("FILA VAZIA!\n");
    }
    int pos = 1;
  while (prox != NULL) {
      printf("Posição %d da fila: %d \n\n", pos, prox->valor);
      prox=prox->prox;
      pos = pos + 1;
    }

    printf("A fila tem %d posições.\n\n", pos-1);
}

int main(void) {
    
    criaFila(&q);
    
    inserirElemento(&q, 10);
    inserirElemento(&q, 20);
    inserirElemento(&q, 30);
    inserirElemento(&q, 40);
    inserirElemento(&q, 50);
    inserirElemento(&q, 60);

    imprimeFila(&q);

    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    
    return 0;
}