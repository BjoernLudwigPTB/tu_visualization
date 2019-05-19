#include "complex.h"

/*
This contains the implementation of the minimal surfaces family from
http://wordpress.discretization.de/ddg2019 tutorial 5
*/

/* The map rho from http://wordpress.discretization.de/ddg2019 tutorial 5

Parameters:
int p: the natural parameter

Return:
float: the result of the map rho
*/
float rho(int p) {
    return (p-1)/float(p);
}


/* The map r from http://wordpress.discretization.de/ddg2019 tutorial 5

Parameters:
int p: the natural parameter

Return:
float: the result of the map r
*/
float r(int p) {
    return 2 * sqrt(2*p - 1) / (p-1);
}


/* Compute the first component of the map phi from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the first component of the map phi
*/
vector2 phi1(vector2 z; int p) {
    return cmul({0, 1}, cpow(z, 2*p -1) - z);
}

/* Compute the second component of the map phi from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the second component of the map phi
*/
vector2 phi2(vector2 z; int p) {
    return cpow(z, 2*p - 1) + z;
}

/* Compute the third component of the map phi from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the third component of the map phi
*/
vector2 phi3(vector2 z; int p) {
    return cmul({0, 1}, rho(p) * cpow(z, 2*p) + {1, 0});
}

/* Compute the fourth component of the map phi from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the fourth component of the map phi
*/
vector2 phi4(vector2 z; int p) {
    return rho(p) * (r(p) * cpow(z, p) + (cpow(z, 2*p) - {1, 0}));
}

/* Compute the fifth component of the map phi from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the fifth component of the map phi
*/
vector2 phi5(vector2 z; int p) {
    return rho(p) * (r(p) * cpow(z, p) - (cpow(z, 2*p) - {1, 0}));
}


/* Compute the fourth component of the map phitilde from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the fourth component of the map phitilde
*/
vector2 phitilde4(vector2 z; int p) {
    return rho(p) * (cpow(z, 2*p) - {1, 0});
}

/* Compute the fifth component of the map phitilde from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the fifth component of the map phitilde
*/
vector2 phitilde5(vector2 z; int p) {
    return rho(p) * r(p) * cpow(z, p);
}


/* Compute the first component of the map phitilde from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the first component of the map phitilde
*/
vector2 phitilde1(vector2 z; int p) {
    return cdiv(phi1(z, p), phitilde5(z, p) - phitilde4(z, p));
}


/* Compute the second component of the map phitilde from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the second component of the map phitilde
*/
vector2 phitilde2(vector2 z; int p) {
    return cdiv(phi2(z, p), phitilde5(z, p) - phitilde4(z, p));
}


/* Compute the third component of the map phitilde from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the thir  component of the map phitilde
*/
vector2 phitilde3(vector2 z; int p) {
    return cdiv(phi3(z, p), phitilde5(z, p) - phitilde4(z, p));
}


/* Compute the map phitilde from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the result vector of the map phitilde
*/
vector phitilde(vector2 z; int p) {
    return set(real(phitilde1(z, p)), real(phitilde2(z, p)),
        real(phitilde3(z, p)));
}


/* Compute the associated family of the surface constructed via the map phitilde
from tutorial5 on http://wordpress.discretization.de/ddg2019.

Parameters:
vector2 c: the point on the 1-sphere
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the result vector
*/
vector phitilde_family(vector2 c; vector2 z; int p) {
    float real_c_phitilde1 = real(cmul(c, phitilde1(z, p)));
    float real_c_phitilde2 = real(cmul(c, phitilde2(z, p)));
    float real_c_phitilde3 = real(cmul(c, phitilde3(z, p)));
    return set(real_c_phitilde1, real_c_phitilde2, real_c_phitilde3);
}
