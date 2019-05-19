#include "complex.h"

/*! \file tut5.h
    \brief This contains the implementation of the minimal surfaces family.


    This contains the implementation of the minimal surfaces family from
    http://wordpress.discretization.de/ddg2019 tutorial 5.
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

/*! \fn float rr(int p)
    \brief The map \f$r\f$ from tutorial 5

    The map \f$r\f$ from tutorial 5 of http://wordpress.discretization.de/ddg2019.

    \param p the natural parameter

    \return the result of the map \f$r\f$
*/
float rr(int p) {
    return 2 * sqrt(2*p - 1) / (p-1);
}


/*! \fn vector2 phi1(vector2 z; int p)
    \brief Compute the first component of the map \f$\varphi\f$ from tutorial5

    Compute the first component of the map \f$\varphi\f$ from tutorial 5 on
    http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the first component of the map \f$\varphi\f$
*/
vector2 phi1(vector2 z; int p) {
    return cmul({0, 1}, cpow(z, 2*p -1) - z);
}


/*! \fn vector2 phi2(vector2 z; int p)
    \brief Compute the second component of the map \f$\varphi\f$ from tutorial5

    Compute the second component of the map \f$\varphi\f$ from tutorial 5 on
    http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the second component of the map \f$\varphi\f$
*/
vector2 phi2(vector2 z; int p) {
    return cpow(z, 2*p - 1) + z;
}


/*! \fn vector2 phi3(vector2 z; int p)
    \brief Compute the third component of the map \f$\varphi\f$ from tutorial5

    Compute the third component of the map \f$\varphi\f$ from tutorial 5 on
    http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the third component of the map \f$\varphi\f$
*/
vector2 phi3(vector2 z; int p) {
    return cmul({0, 1}, rho(p) * cpow(z, 2*p) + {1, 0});
}


/*! \fn vector2 phi4(vector2 z; int p)
    \brief Compute the fourth component of the map \f$\varphi\f$ from tutorial5

    Compute the fourth component of the map \f$\varphi\f$ from tutorial 5 on
    http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the fourth component of the map \f$\varphi\f$
*/
vector2 phi4(vector2 z; int p) {
    return rho(p) * (rr(p) * cpow(z, p) + (cpow(z, 2*p) - {1, 0}));
}


/*! \fn vector2 phi5(vector2 z; int p)
    \brief Compute the fifth component of the map \f$\varphi\f$ from tutorial5

    Compute the fifth component of the map \f$\varphi\f$ from tutorial 5 on
    http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the fifth component of the map \f$\varphi\f$
*/
vector2 phi5(vector2 z; int p) {
    return rho(p) * (rr(p) * cpow(z, p) - (cpow(z, 2*p) - {1, 0}));
}


/*! \fn vector2 phitilde4(vector2 z; int p)
    \brief Compute the fourth component of the map \f$\tilde \varphi\f$ from tutorial 5

    Compute the fourth component of the map \f$\tilde \varphi\f$ from tutorial 5
    on http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the fourth component of the map \f$\tilde \varphi\f$
*/
vector2 phitilde4(vector2 z; int p) {
    return rho(p) * (cpow(z, 2*p) - {1, 0});
}


/*! \fn vector2 phitilde5(vector2 z; int p)
    \brief Compute the fifth component of the map \f$\tilde \varphi\f$ from tutorial 5

    Compute the fifth component of the map \f$\tilde \varphi\f$ from tutorial 5
    on http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the fifth component of the map \f$\tilde \varphi\f$
*/
vector2 phitilde5(vector2 z; int p) {
    return rho(p) * rr(p) * cpow(z, p);
}


/*! \fn vector2 phitilde1(vector2 z; int p)
    \brief Compute the first component of the map \f$\tilde \varphi\f$ from tutorial 5

    Compute the first component of the map \f$\tilde \varphi\f$ from tutorial 5
    on http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the first component of the map \f$\tilde \varphi\f$
*/
vector2 phitilde1(vector2 z; int p) {
    return cdiv(phi1(z, p), phitilde5(z, p) - phitilde4(z, p));
}


/*! \fn vector2 phitilde2(vector2 z; int p)
    \brief Compute the second component of the map \f$\tilde \varphi\f$ from tutorial 5

    Compute the second component of the map \f$\tilde \varphi\f$ from tutorial 5
    on http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the second component of the map \f$\tilde \varphi\f$
*/
vector2 phitilde2(vector2 z; int p) {
    return cdiv(phi2(z, p), phitilde5(z, p) - phitilde4(z, p));
}


/*! \fn vector2 phitilde3(vector2 z; int p)
    \brief Compute the third component of the map \f$\tilde \varphi\f$ from tutorial 5

    Compute the third component of the map \f$\tilde \varphi\f$ from tutorial 5
    on http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the third component of the map \f$\tilde \varphi\f$
*/
vector2 phitilde3(vector2 z; int p) {
    return cdiv(phi3(z, p), phitilde5(z, p) - phitilde4(z, p));
}


/*! \fn vector phitilde(vector2 z; int p)
    \brief Compute the map \f$\tilde \varphi\f$ from tutorial 5

    Compute the map \f$\tilde \varphi\f$ from tutorial 5 on
    http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the result vector of the map \f$\tilde \varphi\f$
*/
vector phitilde(vector2 z; int p) {
    return set(real(phitilde1(z, p)), real(phitilde2(z, p)),
        real(phitilde3(z, p)));
}


/*! \fn vector phitilde_family(vector2 c; vector2 z; int p)
    \brief Compute the associated family of the surface

    Compute the associated family of the surface constructed via the map
    \f$\tilde \varphi\f$ from tutorial5 on
    http://wordpress.discretization.de/ddg2019.

    \param c the point on the 1-sphere to multiply with \f$\tilde \varphi\f$
    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the result vector
*/
vector phitilde_family(vector2 c; vector2 z; int p) {
    float real_c_phitilde1 = real(cmul(c, phitilde1(z, p)));
    float real_c_phitilde2 = real(cmul(c, phitilde2(z, p)));
    float real_c_phitilde3 = real(cmul(c, phitilde3(z, p)));
    return set(real_c_phitilde1, real_c_phitilde2, real_c_phitilde3);
}
