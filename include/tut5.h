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
    return phi1(z, p);
}


/*! \fn vector2 gamma1(vector2 z; int p)
    \brief Compute the first component of the map \f$\gamma\f$ from tutorial 5

    Compute the first component of the map \f$\gamma\f$ from tutorial 5
    on http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the first component of the map \f$\gamma\f$
*/
vector2 gamma1(vector2 z; int p) {
    return cdiv(phitilde1(z, p), phitilde5(z, p) - phitilde4(z, p));
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
    return phi2(z, p);
}


/*! \fn vector2 gamma2(vector2 z; int p)
    \brief Compute the second component of the map \f$\gamma\f$ from tutorial 5

    Compute the second component of the map \f$\gamma\f$ from tutorial 5
    on http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the second component of the map \f$\gamma\f$
*/
vector2 gamma2(vector2 z; int p) {
    return cdiv(phitilde2(z, p), phitilde5(z, p) - phitilde4(z, p));
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
    return phi3(z, p);
}


/*! \fn vector2 gamma3(vector2 z; int p)
    \brief Compute the third component of the map \f$\gamma\f$ from tutorial 5

    Compute the third component of the map \f$\gamma\f$ from tutorial 5
    on http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the third component of the map \f$\gamma\f$
*/
vector2 gamma3(vector2 z; int p) {
    return cdiv(phitilde3(z, p), phitilde5(z, p) - phitilde4(z, p));
}


/*! \fn vector gamma(vector2 z; int p)
    \brief Compute the map \f$\gamma\f$ from tutorial 5

    Compute the map \f$\gamma\f$ from tutorial 5 on
    http://wordpress.discretization.de/ddg2019.

    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the result vector of the map \f$\gamma\f$
*/
vector gamma(vector2 z; int p) {
    return set(real(gamma1(z, p)), real(gamma2(z, p)),
        real(gamma3(z, p)));
}


/*! \fn vector phitilde_s_family(vector2 c; vector2 z; int p)
    \brief Compute the associated family of the surface for \f$s\f$

    Compute the associated family of the surface constructed via the map
    \f$c \tilde \varphi\f$ from tutorial5 on
    http://wordpress.discretization.de/ddg2019 with \f$c = s e^i\f$.

    \param c the point on the 1-sphere to multiply with \f$\tilde \varphi\f$
    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the result vector
*/
vector gamma_s_family(vector2 c; vector2 z; int p) {
    float real_c_gamma1 = real(cmul(c, gamma1(z, p)));
    float real_c_gamma2 = real(cmul(c, gamma2(z, p)));
    float real_c_gamma3 = real(cmul(c, gamma3(z, p)));
    return set(real_c_gamma1, real_c_gamma2, real_c_gamma3);
}


/*! \fn vector gamma_t_family(float t; c vector2 z; int p)
    \brief Compute the associated family of the surface for \f$t\f$

    Compute the associated family of the surface constructed via the map
    \f$\gamma\f$ with parameter \f$t\f$ from tutorial5 on
    http://wordpress.discretization.de/ddg2019.

    \param t the real parameter
    \param z the complex stereographic projection
    \param p the natural parameter in the formula

    \return the result vector
*/
vector gamma_t_family(float t; vector2 z; int p) {
    float cos_t = cos(t);
    float sin_t = sin(t);
    vector2 t_phitilde1 = phitilde1(z, p);
    vector2 t_phitilde2 = cmul(set(cos_t, 0), phitilde2(z, p))
        - cmul(phitilde4(z, p), set(sin_t, 0));
    vector2 t_phitilde3 = phitilde3(z, p);
    vector2 t_phitilde4 = cmul(phitilde2(z, p), set(sin_t, 0))
        - cmul(phitilde4(z, p), set(cos_t, 0));
    vector2 t_phitilde5 = phitilde5(z, p);
    vector2 divisor = t_phitilde5 - t_phitilde4;
    float real_t_gamma1 = real(cdiv(t_phitilde1, divisor));
    float real_t_gamma2 = real(cdiv(t_phitilde2, divisor));
    float real_t_gamma3 = real(cdiv(t_phitilde3, divisor));
    return set(real_t_gamma1, real_t_gamma2, real_t_gamma3);
}
