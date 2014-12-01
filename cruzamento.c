individuo *cruzamento(populacao *p)
{
int i;
if(p==NULL && p->quantidade<2)
{
printf("Populacao com menos de 2 individuos");
return NULL;
}
else
{
individuo *auxa, *auxb;
srand((unsigned)time(NULL));
auxa = p->inicio;
auxb = p->inicio;
while(i<rand()%p->quantidade)
{
auxa=auxa->prox;
i++;
}
do
{
while(i<rand()%p->quantidade)
{
auxb=auxb->prox;
i++;
}
}while(auxb==auxa);
individuo *novo = cruzar(auxa,auxb);
return novo;
}
}

individuo *cruzar(individuo *a, individuo *b)
{
int i = 0;
individuo *filho = cria_individuo();
for(i=0;i<2;i++)
filho->genotipo[i] = a->genotipo[i];
for(i=0;i<5;i++)
filho->genotipo[i] = b->genotipo[i];
return filho;
}
