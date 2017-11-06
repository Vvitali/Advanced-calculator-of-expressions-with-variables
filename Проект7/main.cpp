#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "source.h"
#include "machine.h"

#include <wchar.h> //"Широкие" многобайтовые символы и их ввод-вывод
#include <wctype.h> //"Классификация" широких символов
#include <locale>
#include <Windows.h>

void main(void)
{
	setlocale(LC_ALL, "C");
	//SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	//SetConsoleOutputCP(1251);
	int n = 0;
	FILE *f = NULL;
	FILE *t = NULL;
	char fname[20] = "HELLO";

	wchar_t B[5][5] = { { L'\xda', L'\xc4', L'\xc2', L'\xc4', L'\xbf' }, \
	{L'\xb3', L' ', L'\xb3', L' ', L'\xb3'}, \
	{L'\xc3', L'\xc4', L'\xc5', L'\xc4', L'\xb4'}, \
	{L'\xb3', L' ', L'\xb3', L' ', L'\xb3'}, \
	{L'\xc0', L'\xc4', L'\xc1', L'\xc4', L'\xd9'} };

	printf("Hello [username].\nWelcome to \"Advanced calculator of expressions with variables\".\n");
	printf("\nSelect input file: ");	

	//Because "FGETS" will put "\n" at the end of the file-name string - we have to remove it - otherwise we will not able to read file
	fgets(fname, 20, stdin);
	for (int i = 0; i < 20; i++)
	{
		if (fname[i] == '\n')
		{
			fname[i] = '\0';
			break;
		}
	}
	f = open(fname);

	printf("Select output file: ");
	gets_s(fname, 20);

	//Because "FGETS" will put "\n" at the end of the file-name string - we have to remove it - otherwise we will not able to read file
	for (int i = 0; i < 20; i++)
	{
		if (fname[i] == '\n')
		{
			fname[i] = '\0';
			break;
		}
	}
	t = open(fname);
	
	printf("\nSelect mode:\n1. Full execution of user programm\n2. Step-by-step execution (Tracing)\n$:");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
			own(f,t, 0);
			break;
		case 2:
			own(f, t, 1);
			break;
		default:
			printf("\nYou can find my repository at: https://github.com/Vvitali\n");
		
			break;
	}
	
	system("pause");
}
