
#include "exp.h"
#include <math.h>

double Exp::rad2dgr (double r) const
{
    switch (trigformat)
    {
        case dgr_deg:               // circle = 360 units
            return (360 / (2 * M_PI) * r);
        case dgr_rad:               // circle = 2 * pi
            return (r);
        case dgr_grad:              // circle = 400 units
            return (400 / (2 * M_PI) * r);
        default:
            internal_error ();
    }

    return (MAXVAL);                // to avoid compile warning
}