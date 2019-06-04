#include "complex.h"

/*! \file tut6.h
    \brief This contains the implementation of tutorial 6.


    This contains the implementation from
    http://wordpress.discretization.de/ddg2019 tutorial 6.
*/

/*! \fn float rho(int p)
    \brief The map \f$\rho\f$ from tutorial 5

    The map \f$\rho\f$ from tutorial 5 of http://wordpress.discretization.de/ddg2019.

    \param p the natural parameter

    \return the result of the map \f$\rho\f$
*/
float rho(int p) {
    return (p-1)/float(p);
}
