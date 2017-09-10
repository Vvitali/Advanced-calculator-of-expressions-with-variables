#include <iostream>
#include <limits.h>
/*������ ����� ����������� ������ 4 �����������: �, B, C, D*/

#ifndef MACHINE_H
#define MACHINE_H

//��������� �������� ������

//���� �������� ������
struct machST
{
	char data;
	machST *next;
};

//C�������� ������ ����������
struct varval
{ 
	int current;
	
};

//������� �������� �������� ������ � ���������� ��� ����������� ����������
char getVarName(char *);

//������� ����������� ��������� � ������������ ��� ����2����
float machine(char *, float*);

float geti(char, machST*, float*);

//���������� � ���� ��������
machST *push1(machST *, char);
//������ �������� �� �����
char pop(machST **);

#endif /*MACHINE_H*/