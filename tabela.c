#include <stdio.h>
#define TAM 19

int tabela[TAM];

int funcao_hash(int valor) 
{
	return valor % TAM;
}

void inicializar_tabela() 
{
	int i;
	for (i = 0; i < TAM; i++)
		tabela[i] = 0;
}

void inserir(int valor) 
{
	int pos = funcao_hash(valor);
	while (tabela[pos] != 0)
		pos = funcao_hash(pos + 1);
	tabela[pos] = valor;
}

void print() 
{
	int i;
	for (i = 0; i < TAM; i++) 
	{
		printf("tabela[%d] = %d\n", i, tabela[i]);
	}
}

int is_empty() 
{
	int i;
	for (i = 0; i < TAM; i++)
		if (tabela[i] != 0) return 0;
	return 1;
}

int sum() 
{
	int result = 0;
	int i;
	for (i = 0; i < TAM; i++)
		result += tabela[i];
	return result;
}

int sub() 
{
	int result = 0;
	int i;
	for (i = 0; i < TAM; i++)
		result -= tabela[i];
	return result;
}

int mult() 
{
	if (is_empty()) return (0);
	int i;
	int result = 1;
	for (i = 0; i < TAM; i++) 
		if (tabela[i] != 0) result *= tabela[i];
	return result;
}

int calcula(char op) 
{
	int result;
	 
	if (op == '+') 
	{
		result = sum();
		return result;
	}
	
	else if (op == '-') 
	{
		result = sub();
		return result;
	}
	
	else if (op == '*') 
	{
		result = mult();
		return result;
	}
}

int main()
{
	inicializar_tabela();
	printf("\nCALCULADORA\n");
	
	int num;
	while (1) 
	{
		printf("Digite um numero:\n");
		scanf("%d", &num);
		if (num == 0) break;
		inserir(num);
	}
	
	printf("Digite uma operacao:\n");
	char op;
	scanf(" %c", &op);
	
	int result = calcula(op);
	printf("%d", result);
	
	return (0);
}
