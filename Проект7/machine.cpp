#include "machine.h"

char getVarName(char *string)
{
	if (string[2] == '=' && string[1] == ':')
		//изменить код последнего символа с \n на \0
	{
		char ret;
		ret = string[0];

		for (int i = 0; 1; ++i)
		{
			if (string[i + 3] == '\0')
			{
				string[i] = '\0';
				break;
			}
			string[i] = string[i + 3];
		}
		return ret;
	}
	return NULL;
}

float geti(char token, machST **HEAD, float *val)
{
	float ol = 0;
	float o2 = 0;
	if (isdigit(token)) return atoi(&token);

	if (isalpha(token))
	{
		switch (token)
		{
		case 'a': return val[0];
			break;
		case 'b':	return val[1];
			break;
		case 'c':	return val[2];
			break;
		case 'd': return val[3];
			break;
		default:
			return INT_MAX;
		}
	}

	switch (token)
	{
	case '*':
		ol = geti(pop(HEAD), HEAD, val);
		o2 = geti(pop(HEAD), HEAD, val);
		return ol*o2;
		break;
	case '/':
		ol = geti(pop(HEAD), HEAD, val);
		o2 = geti(pop(HEAD), HEAD, val);

		return o2/ol;
		break;
	case '-':
		ol = geti(pop(HEAD), HEAD, val);
		o2 = geti(pop(HEAD), HEAD, val);
		return o2 - ol;
		break;
	case '+':
		ol = geti(pop(HEAD), HEAD, val) + geti(pop(HEAD), HEAD, val);
		return ol;
		break;
	default:
		break;
	}
	return 0;
}

float machine(char * string, float *val)
{
	machST *stack = NULL;
	float value = 0;

	for (int i = 0; string[i]; ++i)
	{
		stack = push1(stack, string[i]);
	}

	value = geti(pop(&stack), &stack, val);
	
	return value;
}

machST *push1(machST *HEAD, char a)
{
	machST *zz;
	/*Выделяем память*/
	if ((zz = (machST *)malloc(sizeof(machST))) == NULL)
	{
		/*Выход если нет памяти.*/
		printf("Нет памяти.");
		exit(-1);
	}
	(*zz).data = a;
	(*zz).next = HEAD;
	return zz;
}

char pop(machST **HEAD)
{
	machST *zz;
	char a;

	//проверка стека на пустоту
	if ((*HEAD) == NULL && (**HEAD).data=='o') return '\0';
    zz = *HEAD;
	a = (*zz).data;
	*HEAD = (*zz).next;
	free(zz);
	zz = NULL;
	return a;
}