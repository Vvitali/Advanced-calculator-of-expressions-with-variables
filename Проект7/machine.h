#include <iostream>
#include <limits.h>
/*Машина может оперировать только 4 переменными: А, B, C, D*/

#ifndef MACHINE_H
#define MACHINE_H

//Структура стековой машины

//Стек стековой машины
struct machST
{
	char data;
	machST *next;
};

//Cтруктуры памяти переменных
struct varval
{ 
	int current;
	
};

//Функция получает исходную строку и возвращает имя вычисляемой переменной
char getVarName(char *);

//Функция вычисляющая выражение и возвращающая его знач2ение
float machine(char *, float*);

float geti(char, machST*, float*);

//Добавление в стек элемента
machST *push1(machST *, char);
//Взятие элемента из стека
char pop(machST **);

#endif /*MACHINE_H*/