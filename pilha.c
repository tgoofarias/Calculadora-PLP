#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct no 
{
	int valor;
	struct no *prox;
}No;

No * push(No **topo, int valor) 
{
	No *novo = (No *) malloc(sizeof(No));
	novo->valor = valor;
	
	novo->prox = *topo;
	*topo = novo;
	return novo;
}

No * pop(No **topo) 
{
	No *aux;
	
	if (*topo != NULL) 
	{
		aux = *topo;
		*topo = aux->prox;
		free(aux);
		return *topo;
	}
}

int calcula(No **topo, char op) 
{
	int result;
	 
	if (op == '+') 
	{
		while (*topo != NULL) 
		{
			result += (*topo)->valor;
			*topo = pop(topo);
		}
		return result;
	}
	
	else if (op == '-') 
	{
		while (*topo != NULL) 
		{
			result -= (*topo)->valor;
			*topo = pop(topo);
		}
		return result;
	}
	
	else if (op == '*') 
	{
		while (*topo != NULL) 
		{
			result *= (*topo)->valor;
			*topo = pop(topo);
		}
		return result;
	}
}

int main() 
{
	int num, operation;
	
	No *topo = NULL;
	
	printf("\nCALCULADORA\n");
	
	while (1) 
	{
		printf("Digite um numero:\n");
		scanf("%d", &num);
		if (num == 0) break;
		topo = push(&topo, num);
	}
	
	printf("Digite uma operacao:\n");
	char op;
	scanf(" %c", &op);
	
	int result = calcula(&topo, op);
	printf("%d", result);
	
	return (0);
}
