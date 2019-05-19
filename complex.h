// This contains all basic arithmetic operations for comple numbers.

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


/* Give the real part of a complex number

Parameters:
vector2 z: the complex number of which the real part is needed

Return:
float: the real part of z
*/
float real(vector2 z) {
    return z.x;
}
