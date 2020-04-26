#include "functions.h"
;
char * Mstrcpy(char * string1, char * string2)
{
	int i = 0;
	while (string2[i] != '\0')
	{
		string1[i] = string2[i];
		++i;
	}
	string1[i] = string2[i];
	return &string1[0];
}