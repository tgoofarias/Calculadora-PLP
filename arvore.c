#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int num;
  struct no* esq;
  struct no* dir;
} No;

void inserir(No **raiz, int num)
{
	if (*raiz == NULL)
	{
		*raiz = (No*)malloc(sizeof(No));
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL; 
		(*raiz)->num = num; 
	} 
	else 
	{
		if (num < (*raiz)->num) 
		{
			inserir(&(*raiz)->esq, num);
		}
		if(num > (*raiz)->num)
		{
			inserir(&(*raiz)->dir, num);
		}
	}
}

int sum(No **raiz)
{
    if (*raiz == NULL)
        return (0);
    return ((*raiz)->num + sum(&(*raiz)->esq) + sum(&(*raiz)->dir));
}

int sub(No **raiz)
{
	if (*raiz == NULL)
        return (0);
    return (- (*raiz)->num - sum(&(*raiz)->esq) - sum(&(*raiz)->dir));
}

int mult(No **raiz)
{
	if (*raiz == NULL)
        return (1);
    return ((*raiz)->num * sum(&(*raiz)->esq) * sum(&(*raiz)->dir));
}

int calcula(No **raiz, char op) 
{
	int result;
	 
	if (op == '+') 
	{
		result = sum(raiz);
		return result;
	}
	
	else if (op == '-') 
	{
		result = sub(raiz);
		return result;
	}
	
	else if (op == '*') 
	{
		result = mult(raiz);
		return result;
	}
}

int main()
{
	int num;
	No *raiz = NULL; 
	
	printf("\nCALCULADORA\n");
	
	while (1) 
	{
		printf("Digite um numero:\n");
		scanf("%d", &num);
		if (num == 0) break;
		inserir(&raiz, num);
	}
	
	printf("Digite uma operacao:\n");
	char op;
	scanf(" %c", &op);
	
	int result = calcula(&raiz, op);
	printf("%d", result);
  
	return 0;
}
