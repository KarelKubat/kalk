#include "exp.h"
#include <stdio.h> 
#include <stdlib.h> 

void Exp::internal_error () const
{
    puts ("Internal error. Chip fried.");
    exit (1);
}
