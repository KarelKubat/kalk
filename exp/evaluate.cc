#include "exp.h"
#include <math.h>
#include <stdio.h>
#include <string.h> 

double Exp::evaluate () const
{
    double
	ret;

    switch (type)
    {
	case type_unaryop:
	    switch (info->un.op) {
		case unop_min:
		    ret = - info->un.next->eval();
		    return ret;
		    
                case unop_toggle:
                    ret = ( (double)
			    ~( (int)
			       info->un.next->eval()
			     )	
			);
		    return ret;
		    
		case fun_sqrt:
		    ret = info->un.next->eval();
		    if (ret < ZERO) {
			printf ("Domain error: can't sqrt(%g). "
				"Assuming %g.\n", ret, MAXVAL);
			return (MAXVAL);
		    }
		    return (sqrt (ret));
		    
		case fun_sin:
		    ret = sin (dgr2rad (info->un.next->eval()));
		    return ret;
		    
		case fun_cos:
		    ret = cos (dgr2rad (info->un.next->eval()));
		    return ret;
		    
		case fun_tan:
		    ret = tan (dgr2rad (info->un.next->eval()));
		    return ret;
		    
		case fun_asin:
		case fun_acos:
		    ret = info->un.next->eval();
		    if (ret < -1.0 || ret > 1.0) {
			printf ("Domain error: can't acos/asin(%g). "
				"Assuming %g.\n", ret, MAXVAL);
			return (MAXVAL);
		    }
		    if (info->un.op == fun_asin)
			return (rad2dgr (asin (ret)));
		    return (rad2dgr (acos (ret)));
		    
		case fun_atan:
		    ret = atan(info->un.next->eval());
		    return (rad2dgr(ret));
		    
		case fun_floor:
		    ret = info->un.next->eval();
		    return floor(ret);

		case fun_ceil:
		    ret = info->un.next->eval();
		    return ceil(ret);

		case fun_exp:
		    ret = info->un.next->eval();
		    return exp(ret);

		case fun_log10:
		    ret = info->un.next->eval();
		    if (ret < ZERO) {
			printf ("Domain error: can't log10(%g). "
				"Assuming %g.\n", ret, MAXVAL);
			return (MAXVAL);
		    }
		    return (log10 (ret));
		    
		case fun_log:
		    ret = info->un.next->eval();
		    if (ret < ZERO) {
			printf ("Domain error: can't log(%g). "
				"Assuming %g.\n", ret, MAXVAL);
			return (MAXVAL);
		    }
		    return (log (ret));
		    
		case fun_rint:
		    ret = info->un.next->eval();
		    return rint(ret);

  	        case fun_fact:
		    ret = info->un.next->eval();
		    return fact(ret);

 		default:
		    internal_error ();
	    }
	
	case type_binaryop:
	    switch (info->bin.op)
	    {
                case binop_lshift:
                    ret = (int) info->bin.left->eval() <<
			(int) info->bin.right->eval();
		    return ret;
	    
                case binop_rshift:
                    ret = (int) info->bin.left->eval() >>
			(int) info->bin.right->eval();
		    return ret;
		    
                case binop_and:
                    ret = (int) info->bin.left->eval() &
			(int) info->bin.right->eval();
		    return ret;
		    
                case binop_or:
		    ret = (int) info->bin.left->eval() |
			(int) info->bin.right->eval();
		    return ret;
		    
                case binop_xor:
		    ret = (int) info->bin.left->eval() ^
			(int) info->bin.right->eval();
		    return ret;
		    
		case binop_min:
		    ret = info->bin.left->eval() -
			info->bin.right->eval();
		    return ret;
		    
		case binop_plus:
		    ret = info->bin.left->eval() +
			info->bin.right->eval();
		    return ret;
		    
		case binop_mul:
		    ret = info->bin.left->eval() *
			info->bin.right->eval();
		    return ret;
		    
		case binop_div:
		    ret = info->bin.right->eval();
		    if (fabs(ret) < ZERO) {
			printf ("Division by zero. Assuming %g.\n", MAXVAL);
			return (MAXVAL);
		    }
		    ret = info->bin.left->eval() / ret;
		    return ret;

		case binop_assign:
		    ret = info->bin.right->eval();
		    return ret;

		case fun_pow:
		    ret = info->bin.left->eval();
		    ret = pow(ret, info->bin.right->eval());
		    return ret;

		case fun_fmod:
		    ret = info->bin.left->eval();
		    ret = fmod(ret, info->bin.right->eval());
		    return ret;
		    
		default:
		    internal_error ();
	    }
	
	case type_number:
	    return (info->num.val);

	case type_variable:
	    for (register int i = 0; i < varlistsize; i++)
		if (! strcmp (varlist [i]->info->bin.left->info->var.name,
			      info->var.name))
		    return (varlist [i]->info->bin.right->eval());
	    printf ("No such variable defined: %s. Assuming %g.\n",
		    info->var.name, MAXVAL);
	    return (MAXVAL);

	default:
	    internal_error ();
    }

    return (MAXVAL);				// this suppresses a
						// `gcc -Wall' warning
}
