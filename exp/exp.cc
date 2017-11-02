#include "exp.h"

Exp **Exp::varlist = 0;
int Exp::nobj = 0;
int Exp::varlistsize = 0;
int Exp::depth;
Exp::Outputformat Exp::format = Exp::output_dec;
Exp::Trigformat Exp::trigformat = Exp::dgr_rad;

Exp::~Exp ()
{
    destroy ();
    if (! --nobj)
    {
	delete varlist;
	varlist = 0;
	varlistsize = 0;
    }
}
