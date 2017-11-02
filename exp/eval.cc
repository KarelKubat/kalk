#include "exp.h"
#include <stdio.h>

double Exp::eval () const {

    // printf("eval: depth=%d\n", depth);
    if (depth++ >= MAXDEPTH) {
	printf("Evaluation depth of %d exceeded. Circular definition? "
	       "Assuming %g.\n", MAXDEPTH, MAXVAL);
	return MAXVAL;
    }

    depth++;
    double ret = evaluate();
    return ret;
}
