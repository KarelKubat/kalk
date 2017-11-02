#include "exp.h"

double Exp::fact(double v) const {
    double ret = 2;

    v = floor(v);
    for (double s = 3; s <= v; s = floor(s + 1)) 
	ret *= s;

    return ret;
}
