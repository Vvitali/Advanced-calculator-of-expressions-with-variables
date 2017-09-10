#include "machine.h"
#include "source.h"
#include "io.h"


char* transfer(char *a, st *OPERS)
{
	int i, point;
	//point - счётчик выходной строки
	i = point = 0;
	char outstring[80];

	do
	{
		while (a[i] != '\0' && a[i] != ';')
		{
			if (a[i] == ')')
				{
				
				while ((OPERS->c) != '(')
					
					outstring[point++] = POP(&OPERS);
				POP(&OPERS);
			}
			if (a[i] >= 'a' && a[i] <= 'z')

				outstring[point++] = a[i];

			if (isdigit(a[i]))

				outstring[point++] = a[i];

			if (a[i] == '(')

				OPERS = push(OPERS, '(');
			if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*')

			{

				if (OPERS == NULL)

					OPERS = push(OPERS, a[i]);

				else
				
					if (PRIOR(OPERS->c)<PRIOR(a[i]))
						
						OPERS = push(OPERS, a[i]);
				
					else
					{
						while ((OPERS != NULL) && (PRIOR(OPERS->c) >= PRIOR(a[i])))							
							outstring[point++] = POP(&OPERS);
						OPERS = push(OPERS, a[i]);
					}
			}
			i++;
		}
		while (OPERS != NULL)
		outstring[point++] = POP(&OPERS);
		outstring[point] = '\0';
		} while (0);
		return outstring;
}

st *push(struct st *HEAD, char a)
{
	struct st *PTR;
	// Выделеняем памяти
	if ((PTR = (st *)malloc(sizeof(st))) == NULL)
	{
		printf("Нет памяти.");
		exit(-1);
	}
	 
	
	PTR->c = a;
	// и подключение её к стеку
	PTR->next = HEAD;
	// PTR -новая веpшина стека
	return PTR;
}

char POP(struct st **HEAD)
{
	struct st *PTR;
	char a;
	//If stack is not empty - it will return \0
	/* Если стек пуст,  возвpащается '\0' */
	if (*HEAD == NULL) return '\0';
	/* в PTR - адpес веpшины стека */
	// PTR is the top of the stack
	PTR = *HEAD;
	a = PTR->c;
	//change adres of the top of the stack
	/* Изменяем адpес веpшины стека */
	*HEAD = PTR->next;
	/* Освобождение памяти */
	//empty memory
	free(PTR);
	/* Возвpат символа с веpшины стека */
	//return sign from the top of the stack
	return a;
}

int PRIOR(char a)
{
	switch (a)
	{
	case '*':
		return 3;
	case '/':
		return 3;

	case '-':
		return 2;
	case '+':
		return 2;

	case '(':
		return 1;
	default:
		return 0;
	}
}

void delSpace(char *string)
{
	int b = 0;
	for (int i = 0; string[i]; ++i)
	{
		if (string[i] != ' ')
		{
			if (string[i] == '\n')

			{
				string[b] = '\0';
				break;
			}

			string[b] = string[i];
			++b;
		}
	}
	string[b] = '\0';
}

void own(FILE *f, FILE *t, int trace)
{
	// Stack is empty
	st *OPERS = NULL;

	char a[80];

	//Array for support
	char b[80];

	//Array with variables.
	float val[4];
	{
		val[0] = 0;
		val[1] = 0;
		val[2] = 0;
		val[3] = 0;
	}

	char varName;
	int var;
	int end;

	
	wprintf(L"%c", L'\xda');// L'\xc1' - code of 2byte sign
	for (int i = 0; i < 70; i++)
	{
		wprintf(L"%c", L'\xc4');
	}
	wprintf(L"%c", L'\xbf');
	wprintf(L"\n");
	wprintf(L"%cVar%c  Original  %c     New     %c  Res  %c   a   %c   b   %c   c   %c   d   %c\n", L'\xb3', L'\xb3', L'\xb3', L'\xb3', L'\xb3', L'\xb3', L'\xb3', L'\xb3', L'\xb3');
	wprintf(L"%c", L'\xc3');// L'\xc1' - code of 2byte sign
	for (int i = 0; i < 70; i++)
	{
		wprintf(L"%c", L'\xc4');
	}
	wprintf(L"%c\n", L'\xb4');

	for (end = inputs(f, a); !end; end = inputs(f, a))
	{
		if (end)
		{
			printf("Ошибка открытия файла!");
			continue;
		}

		delSpace(a);
		varName = getVarName(a);
	
		switch (varName)
		{
		case 'a': var = 0;
			break;
		case 'b': var = 1;
			break;
		case 'c': var = 2;
			break;
		case 'd': var = 3;
			break;

		default:
			break;
		}

		char *string;
		string = transfer(a, OPERS);

		for (int i = 0; string[i - 1] != '\0'; ++i)
		{
			b[i] = string[i];
		}

		val[var] = machine(b, val);


		if (trace)
		{
			wprintf(L"%c", L'\xc3');
			wprintf(L" %c %c%-12.12S%c%-13.13S%c %-5.2lf %c %-5.2lf %c %-5.2lf %c %-5.2lf %c %-5.2lf %c\n", varName, L'\xb3', a, L'\xb3', b, L'\xb3', val[var], L'\xb3', val[0], L'\xb3', val[1], L'\xb3', val[2], L'\xb3', val[3], L'\xb3');
			//printf("%c = %s = %s = %lf :a=%0.3lf, b=%0.3lf, c=%0.3lf, d=%0.3lf\n", varName, a, b, val[var], val[0], val[1], val[2], val[3]);
			fwprintf(t, L" %c %c%-12.12S%c%-13.13S%c %-5.2lf %c %-5.2lf %c %-5.2lf %c %-5.2lf %c %-5.2lf %c\n", varName, L'\xb3', a, L'\xb3', b, L'\xb3', val[var], L'\xb3', val[0], L'\xb3', val[1], L'\xb3', val[2], L'\xb3', val[3], L'\xb3');
		}
	}

	wprintf(L"%c", L'\xc0');//   L'\xc1' - code of 2byte sign
	for (int i = 0; i < 70; i++)
	{
		wprintf(L"%c", L'\xc4');
	}
	wprintf(L"%c", L'\xd9');
	wprintf(L"\n");
	wprintf(L"Result: %f\n", val[var]);
	fprintf(t, "Result: %f\n", val[var]);
	fclose(t);
	printf("\n");
}
