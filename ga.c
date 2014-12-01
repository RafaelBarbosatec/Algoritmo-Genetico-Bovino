#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct individuo{
int genotipo[5];
struct individuo *prox;
}individuo;

typedef struct populacao{
struct individuo *inicio;
}populacao;

individuo *cria_individuo();
populacao *cria_populacao(int n);
void imprime_p(populacao *p);

int
main(){
    int i = 0;
    populacao *p = cria_populacao(20);
    imprime_p(p);
}



individuo *cria_individuo(){ // Função cria o individuo gerando os genes aleatórios
    int i=0;
    individuo *n = (individuo*)malloc(sizeof(individuo));
    
    while(i<5){
        n->genotipo[i] = rand()%2;
        i++;
    }
    
    n->prox=NULL;
    return n;
}

populacao *cria_populacao(int n){  // tem como parametro a quantidade de individuos da população
    int i=1;
    srand( (unsigned)time(NULL) );
    individuo *aux;
    populacao *p = (populacao*)malloc(sizeof(populacao));
    aux = cria_individuo();
    p->inicio = aux;
    
    while(i<n){
       	aux->prox = cria_individuo();
       	aux = aux->prox;
       	i++;
    }
    
    return p;
}

void imprime_p(populacao *p){ // função que imprime população
    individuo *i = p->inicio;
    int t=0;
    
    while(i->prox != NULL){
        int f=0;
        while(f<5){
            printf("%d ",i->genotipo[f]);
            f++;
        }
        printf("\n");
        i=i->prox;
    }
    
}
