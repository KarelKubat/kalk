#include "exp.h"
#include <stdio.h>

void Exp::list () const
{
    for (register int i = 0; i < varlistsize; i++)
    {
	printf ("%s=", varlist [i]->info->bin.left->info->var.name);
	varlist [i]->info->bin.right->print ();
	putchar ('\n');
    }
}
