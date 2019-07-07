/*! \file complex.h
    \brief This contains all basic arithmetic operations for complex numbers.


    This contains all basic arithmetic operations for complex numbers needed to
    to solve the challenges in http://wordpress.discretization.de/ddg2019.
*/

/*! \fn vector2 cmul(vector2 z; vector2 w)
    \brief Multiply two complex numbers

    Multiply two arbitrary complex numbers.

    \param z first factor
    \param w second factor
    \return \f$z \cdot w\f$
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


/*! \fn vector2 cdiv(vector2 w; vector2 z)
    \brief Divide one complex number by another complex number

    Divide one arbitrary complex number by another non-zero complex number.

    \param w divident
    \param z divison

    \return \f$\frac{w}{z}\f$
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


/*! \fn vector2 cpow(vector2 z; int n)
    \brief Compute the \f$n\f$-th power of a complex number

    Compute the \f$n\f$-th power of a complex number, for \f$n \in N\f$.

    \param z the complex number
    \param n the exponent

    \return \f$z^n\f$
*/
vector2 cpow(vector2 z; int n) {
    float x = z.x;
    float y = z.y;
    float r = length(z);
    float phi = atan2(y, x);
    return pow(r, n) * set(cos(n*phi), sin(n*phi));
}

/*! \fn float real(vector2 z)
    \brief Give the real part of a complex number

    Give the real part of a complex number represented by the first component
    of a two element vector.

    \param z the complex number

    \return the real part \f$a\f$ of \f$z = a + ib\f$
*/
float real(vector2 z) {
    return z.x;
}

/*! \fn float img(vector2 z)
    \brief Give the imaginary part of a complex number

    Give the imaginary part of a complex number represented by the second
    component of a two element vector.

    \param z the complex number

    \return the imaginary part \f$b\f$ of \f$z = a + ib\f$
*/
float img(vector2 z) {
    return z.y;
}

/*! \fn vector2 e_to_the_is(float s)
    \brief Give a point on the one-sphere.

    Give a point on the one-sphere parameterized by \f$s\f$ in the parametric
    form.

    \param s the real parameter

    \return the point \f$(\cos s, \sin s) \subset C\f$
*/
vector2 e_to_the_is(float s) {
    return set(cos(s), sin(s));
}
