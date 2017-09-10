#include <iostream>

#ifndef SOURCE_H
#define SOURCE_H

/* �������� ��p����p�(�������� �����) */
struct st
{
	char c; 
	struct st *next;
};

/* �p������� ������� */

/* ������� push ���������� �� ���� (�� ��p���� ����p��� ��������� HEAD)
������ a . ����p����� ��������� �� ����� ��p���� ����� */
struct st *push(struct st *, char);

/* ������� DEL ������� ������ � ��p���� �����.
����p����� ��������� ������.
�������� ��������� �� ��p���� ����� */
char POP(struct st **);

/* ������� PRIOR ����p����� �p��p���� �p���. ���p���� */
int PRIOR(char);

// ������� ��������� ��������� �� ������ � �������� ������� 
// � ��������� �� ��������� 
char * transfer(char *, st*);

//������� ��������� ������ � ��������� � ����������� �� �������.
void delSpace(char *);

void own(FILE *, FILE *, int);

#endif /*SOURCE_H*/
