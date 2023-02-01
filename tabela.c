#include <stdio.h>
#define TAM 19

int tabela[TAM];

int hash_function(int value) 
{
	return value % TAM;
}

void init_table() 
{
	int i;
	for (i = 0; i < TAM; i++)
		tabela[i] = 0;
}

void insert(int value) 
{
	int pos = hash_function(value);
	while (tabela[pos] != 0)
		pos = hash_function(pos + 1);
	tabela[pos] = value;
}

void remove_table(int value) 
{
	int pos = search_table(value);
	if (pos != -1) tabela[pos] = 0;
}

int search_table(int value) 
{
	int pos = hash_function(value);
	while (tabela[pos] != 0) 
	{
		if (tabela[pos] == value) return pos;
		pos = hash_function(pos + 1);
	}
	return -1;
}

void print_table() 
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

/*
int main()
{
	init_table();
	printf("\nCALCULADORA\n");
	
	int num;
	while (1) 
	{
		printf("Digite um numero:\n");
		scanf("%d", &num);
		if (num == 0) break;
		insert(num);
	}
	
	printf("Digite uma operacao:\n");
	char op;
	scanf(" %c", &op);
	
	int result = calcula(op);
	printf("%d\n", result);
	
	return (0);
}
*/

int main(void) 
{
	init_table();

	insert(50);
	insert(120);
	insert(31);

	print_table();

	printf("position: %d\n", search_table(32));

	return (0);
}