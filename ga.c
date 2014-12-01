#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct individuo{
int genotipo[6];
struct individuo *prox;
int custo;
int avaliacao;
}individuo;

typedef struct populacao{
struct individuo *inicio;
int quantidade;
}populacao;

int rusticidade = 1;
int producao_leite = 1;
int ganho_peso = 1;
int resistencia_frio = 0;
int precocidade = 0;
int alta_imunologia = 1;

individuo *cria_individuo();
populacao *cria_populacao(int n);
populacao *selecao(populacao *p);
void imprime_p(populacao *p);
int populacao_vazia(populacao *p);

int
main(){
int i = 0;
populacao *p = cria_populacao(8);
avalia_populacao(p);
imprime_p(p);
printf("\n\n");
populacao *selecionados = selecao(p);
imprime_p(selecionados);

}

void avalia_populacao(populacao *p){
individuo *i = p->inicio;
    while(i->prox != NULL){

        int valoracao = 0;
        if(i->genotipo[0] == rusticidade){
            valoracao++;
        }
        if(i->genotipo[1] == producao_leite){
            valoracao++;
        }
        if(i->genotipo[2] == ganho_peso){
            valoracao++;
        }
        if(i->genotipo[3] == resistencia_frio){
            valoracao++;
        }
        if(i->genotipo[4] == precocidade){
            valoracao++;
        }
        if(i->genotipo[5] == alta_imunologia){
            valoracao++;
        }
        i->avaliacao = valoracao;
        i=i->prox;
    }
}

populacao *selecao(populacao *p){
    int valor_total = 0;
    int avaliacao_total = 0;
    float custo_medio = 0;
    float custo = 0;
    individuo *i = p->inicio;
    populacao *selecionados = (populacao*)malloc(sizeof(populacao));
    selecionados->inicio = (individuo*)malloc(sizeof(individuo));
    while(i->prox != NULL){
        valor_total += i->custo;
        avaliacao_total += i->avaliacao;
        i = i->prox;
    }
    custo_medio = valor_total / avaliacao_total; // calculamos a média do custo por ponto da população para selecionar os individuos que tiverem o custo beneficio acima da média

    i = p->inicio;

    individuo *aux = (individuo*)malloc(sizeof(individuo)); // guarda o elemento inserido
    individuo *aux2 = (individuo*)malloc(sizeof(individuo)); // guarda o ultimo elemento

    while(i->prox != NULL){
    custo = i->custo / i->avaliacao;
        if(custo < custo_medio){
            if(aux == NULL){
                aux = i;
                aux->prox = NULL;
                selecionados->inicio = aux;
                aux2 = aux;
            }else{
                aux = i;
                aux->prox = NULL;
                aux2->prox = aux;
            }
        }
    i = i->prox;
    }

    return selecionados;
}

individuo *cria_individuo(){ // Função cria o individuo gerando os genes aleatórios
int i=0;
individuo *n = (individuo*)malloc(sizeof(individuo));
while(i<6){
n->genotipo[i] = rand()%2;
i++;
}
n->prox = NULL;
n->custo = 600 + (rand()%600);
n->avaliacao = NULL;
return n;
}

int populacao_vazia(populacao *p){
    if(p->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

populacao *cria_populacao(int n){ // tem como parametro a quantidade de individuos da população
int i=0;
srand( (unsigned)time(NULL) );
individuo *aux;
populacao *p = (populacao*)malloc(sizeof(populacao));
aux = cria_individuo();
p->inicio = aux;
while(i<n){
aux->prox = cria_individuo();
aux = aux->prox;
p->quantidade++;
i++;
}
return p;
}

void imprime_p(populacao *p){ // função que imprime população
individuo *i = p->inicio;
while(i->prox != NULL){
printf("Genetica do animal: ");
int f=0;
while(f<6){
printf("%d ",i->genotipo[f]);
f++;
}
printf("\n");
printf("Custo do animal: R$%d,00",i->custo);
printf("\n");
printf("Avaliacao do animal: %d pontos",i->avaliacao);
printf("\n");
printf("\n");
i=i->prox;
}
}
