
#include "io.h"

FILE* open(const char *fname)
{
	FILE *f = NULL;
	if (!fopen_s(&f, fname, "a+")) return f;
	return NULL;
}

int inputs(FILE * f, char * string)
{
	if (!(fgets(string, 80, f))) return 1;
	return 0; 
}