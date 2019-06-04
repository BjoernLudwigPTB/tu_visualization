#include "complex.h"

/*
This contains the implementation of the Kusner formula from
http://wordpress.discretization.de/ddg2019 tutorial 4
*/

/* The map r from http://wordpress.discretization.de/ddg2019 tutorial 5

Parameters:
int p: the natural parameter

Return:
float: the result of the map r
*/
float r(int p) {
    return 2 * sqrt(2*p - 1) / (p-1);
}


/* Compute the real part of Kusner's formula

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
vector: the real part of the result
*/
vector kusners_formula(vector2 z; int p) {
    // Calculate recurring real and complex numbers.
    float r = 2 * sqrt(2*p - 1) / (p-1);
    vector2 z_to_the_2p_minus_1 = cpow(z, 2*p - 1);
    vector2 z_to_the_2p = cmul(z, z_to_the_2p_minus_1);
    vector2 factor = cdiv({0, 1}, z_to_the_2p
        + r * cpow(z, p) - {1, 0});
    // Calculate the three complex components of Kusners formulas complex
    // result vector.
    vector2 first_comp = cmul(factor, z_to_the_2p_minus_1 - z);
    vector2 second_comp = cmul(factor, cmul({0, -1},
        z_to_the_2p_minus_1 + z));
    vector2 third_comp = cmul(factor, ((p-1)*(z_to_the_2p + {1, 0}))/p);
    return set(real(first_comp), real(second_comp), real(third_comp));
}
