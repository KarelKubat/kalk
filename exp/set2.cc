#include "exp.h"
#include <stdio.h> 
#include <string.h>

void Exp::set (Binaryop op, Exp const &e1, Exp const &e2)
{
    destroy ();

    if (op == binop_assign && e1.type != type_variable)
    {
	printf ("You can only assign expressions to a variable. "
		"Assuming %g.\n", MAXVAL);
	set (MAXVAL);
	return;
    }
    
    type = type_binaryop;
    info = (Info *) new Binaryopinfo;
    info->bin.op = op;
    info->bin.left = new Exp (e1);
    info->bin.right = new Exp (e2);

    if (e1.type == type_number && e2.type == type_number)
	set (eval ());
    
    if (op == binop_assign)
    {
	for (register int i = 0; i < varlistsize; i++)
	    if (! strcmp (varlist [i]->info->bin.left->info->var.name,
			  e1.info->var.name))
	    {
		varlist [i]->destroy ();
		varlist [i] = new Exp (*this);
		return;
	    }
	varlist = (Exp **) realloc (varlist,  (varlistsize + 1) *
				    sizeof (Exp *));
	varlist [varlistsize++] = new Exp (*this);
    }
}
