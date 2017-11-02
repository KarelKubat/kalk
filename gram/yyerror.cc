#include "../kalk.h"
#include <stdio.h>
#include <stdlib.h> 

int yyerror (char const *msg)
{
    if (*yytext)
	printf ("Parse error at `%s'.",
		*yytext == '\n' ? "newline" : yytext);
    putchar ('\n');
    return (0);
}
