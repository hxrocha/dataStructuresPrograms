#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista
struct no{
	int info;
	struct no *next;
};

// Insere um elemento em uma lista encadeada
void insereLista(struct no **plist,int x){
	struct no *p;
    p = (struct no *) malloc(sizeof(struct no));
    p->info = x;
    p->next = *plist;
    *plist = p;
}

// Remove um elemento do início da lista encadeada
int removeInicio(struct no **plist){
	struct no *p;
	p = *plist;
	*plist = p->next;
	int x = p->info;
	free(p);
	return(x);
}

// Remove um elemento do final da lista encadeada
int removeFinal(struct no **plist){
    if((*plist)->next == NULL){
    	struct no *p;
	    p = *plist;
	    *plist = p->next;
	    int x = p->info;
	    free(p);
	    return(x);
	}
	else{
		return (removeFinal(&((*plist)->next)));
	}
     
}
// Remove um elemento qualquer
int removeX(struct no **plist,int x){
	if((*plist) == NULL)
	   return (-1);
	 if((*plist)->info == x){
    	struct no *p;
	    p = *plist;
	    *plist = p->next;
	    int x = p->info;
	    free(p);
	    return(x);
	}
	else{
		return (removeX(&((*plist)->next),x));
	}
	
}

// Imprime a lista do início para o fim
void imprimelistaInicioFim(struct no *plist){

	if(plist != NULL){
		printf(" %d ",plist->info);
		imprimelistaInicioFim(plist->next);
	}
}

// Imprime a lista do fim para o início
void imprimelistaFimInicio(struct no *plist){

	if(plist != NULL){
		imprimelistaFimInicio(plist->next);
		printf(" %d ",plist->info);
	
	}
}


// Programa principal básico que tem o objetivo de testar 
// o funcionamento das funções acima listadas.
int main(){
	 struct no *lista = NULL;
	for(int i=0;i<10;i++)
	   insereLista(&lista,i*10);
	printf("\n Lista impressa do inicio ao fim \n");   
	imprimelistaInicioFim(lista);
	printf("\n Lista impressa do fim para o fim \n");   
	imprimelistaFimInicio(lista);
	printf("\nO valor removido e %d ",removeX(&lista,50));
	printf("\n Lista impressa do inicio ao fim \n");   
	imprimelistaInicioFim(lista);
	printf("\n Lista impressa do fim para o fim \n");   
	imprimelistaFimInicio(lista);
	printf("\nO elemento removido do inicio da lista %d ",removeInicio(&lista));
	printf("\n Lista impressa do inicio ao fim \n");   
	imprimelistaInicioFim(lista);
	printf("\n Lista impressa do fim para o fim \n");   
	imprimelistaFimInicio(lista);
	printf("\n O elemento removido do fim da lista %d ",removeFinal(&lista));
	printf("\n Lista impressa do inicio ao fim \n");   
	imprimelistaInicioFim(lista);
	printf("\n Lista impressa do fim para o fim \n");   
	imprimelistaFimInicio(lista);
	return(0);
}
