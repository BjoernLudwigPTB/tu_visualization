/* Project c in C to the 1-sphere with radius r

Parameters:
vector2 c: the direction in C to project to the 1-sphere

Return:
vector2 - the point on the 1-sphere in direction c
*/
vector2 one_sphere(vector2 z; float r) {
    return z / length(z) * r;
}

/* Project z in R to the 2-sphere with radius r

Parameters:
vector z: the direction in R to project to the 2-sphere

Return:
vector - the point on the 2-sphere in direction z
*/
vector two_sphere(vector z; float r) {
    return z / length(z) * r;
}

/* Stereographic projection from S2 into C

Parameters:
vector c: the vector in S2 to project to C, must not be {0, 0, 1}

Return:
vector2 - the stereographic projection to C
*/
vector2 stereo2(vector c) {
    float x = c.x;
    float y = c.y;
    float z = c.z;
    return set(x / (1-z), y / (1-z));
}

/* Stereographic projection from S3 into C

Parameters:
vector c: the vector in S2 to project to C, must not be {0, 0, 1}

Return:
vector2 - the stereographic projection to C
*/
vector stereo3(vector4 c) {
    float w = c.w;
    float x = c.x;
    float y = c.y;
    float z = c.z;
    return set(w / (1-z), x / (1-z), y / (1-z));
}
/* Multiply two comple numbers

Parameters:
vector2 z: first complex number
vector2 w: second complex number

Return:
vector2: product of z and w
*/
vector2 cmul(vector2 z; vector2 w) {
    float x = z.x;
    float y = z.y;
    float u = w.u;
    float v = w.v;
    float real = x*u - y*v;
    float imaginary = x*v + y*u;
    return set(real, imaginary);
}

/* Divide one complex number by another complex number

Parameters:
vector2 w: divident for the quotient
vector2 z: divisor for the quotient

Return:
vector2: w/z
*/
vector2 cdiv(vector2 w; vector2 z) {
    float x = z.x;
    float y = z.y;
    float u = w.u;
    float v = w.v;
    float divisor = pow(x, 2) + pow(y, 2);
    float real = (u*x + v*y) / divisor;
    float imaginary = (v*x - u*y) / divisor;
    return set(real, imaginary);
}

/* Give the n-th power of a complex vector

Parameters:
vector2 z: the complex vector
int n: the exponent

Return:
vector2 - the n-th power of z
*/
vector2 cpow(vector2 z; int n) {
    float x = z.x;
    float y = z.y;
    float r = length(z);
    float phi = atan2(y, x);
    return pow(r, n) * set(cos(n*phi), sin(n*phi));
}

/* Give the real part of a complex vector

Parameters:
vector2 z: the complex vector of which the real part is needed

Return:
float: the real part of z
*/
float real(vector2 z) {
    return z.x;
}

/* Calculate the real part of Kusner's formula

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

/* Sphere inversion

Parameters:
vector z: the original vvector
vector center: the center of the sphere

Return:
vector: the inverted vector
*/
vector sphere_inversion(vector z; vector center; float scale) {
    // Compute translation, then transform in the origin and retranslate
    vector translation = set(center.x, center.y, center.z);
    vector transformed = z - translation;
    return transformed / length2(transformed) * pow(scale, 2) + translation;
}

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

/* The map alpha from http://wordpress.discretization.de/ddg2019 tutorial 5

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the result of the map phi
*/
vector2 alpha(vector2 z; int p) {
    return -rho(p) * (cpow(z, 2*p) - {1, 0} - r(p) * cpow(z, p));
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


/* Compute the map phitilde from tutorial5
on http://wordpress.discretization.de/ddg2019

Parameters:
vector2 z: the complex stereographic projection
int p: the natural parameter in the formula

Return:
float: the result vector of the map phitilde
*/
vector phitilde(vector2 z; int p) {
    vector2 divisor = phitilde5(z, p) - phitilde4(z, p);
    vector2 phitilde1 = cdiv(phi1(z, p), divisor);
    vector2 phitilde2 = cdiv(phi2(z, p), divisor);
    vector2 phitilde3 = cdiv(phi3(z, p), divisor);
    return set(real(phitilde1), real(phitilde2), real(phitilde3));
}
