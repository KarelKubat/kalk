
#include "exp.h"
#include <math.h>

double Exp::dgr2rad (double r) const
{
    switch (trigformat)
    {
        case dgr_deg:               // circle = 360 units
            return (2 * M_PI / 360 * r);
        case dgr_rad:               // circle = 2 * pi
            return (r);
        case dgr_grad:              // circle = 400 units
            return (2 * M_PI / 400 * r);
        default:
            internal_error ();
    }

    return (MAXVAL);                // to avoid compile warning
}