#include <iostream>

#ifndef IO_H
#define IO_H

/* Пpототипы функций */

FILE* open(const char *);
//функция принимает имя файла и записывает данные из файла в строку
int inputs(FILE *, char *);


#endif /*IO_H*/