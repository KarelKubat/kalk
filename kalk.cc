#include "kalk.h"
#include <stdio.h> 

int main ()
{
    printf ("\n"
	    "KAreL's KalCulator (yeah.. good names are hard to find) V%s\n"
	    "Copyright (c) ICCE/Karel Kubat 1994 ff.. All rights reserved.\n"
	    "Another MegaHard [tm] production!\n"
	    "\n"
	    "Type `help' to see what you can do.\n"
	    "\n"
	    , VER);
    
    register int
	ret = yyparse ();

    putchar ('\n');
    return (ret);
}
