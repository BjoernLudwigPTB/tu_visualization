// This contains some basic projections in one- to four-dimensional real space.

/*! \file projections.h
    \brief Some common projections in discrete differential geometry.


    This contains some common projections in discrete differential geometry from
    http://wordpress.discretization.de/ddg2019.
*/

/*! \fn vector2 one_sphere(vector2 z; float r)
    \brief Project \f$z \in C\f$ to \f$S^1\f$.

    Project \f$z \in C\f$ to \f$S^1\f$ with radius \f$r\f$.

    \param z the direction in \f$C\f$ to project to \f$S^1\f$
    \param r the radius of \f$S^1\f$

    \return the point \f$z \frac{r}{\mid z \mid}\f$
*/
vector2 one_sphere(vector2 z; float r) {
    return z / length(z) * r;
}

/*! \fn vector two_sphere(vector z; float r)
    \brief Project \f$z \in R^3\f$ to \f$S^2\f$.

    Project \f$z \in R^3\f$ to \f$S^2\f$ with radius \f$r\f$.

    \param z the direction in \f$R^3\f$ to project to \f$S^2\f$
    \param r the radius of \f$S^2\f$

    \return the point \f$z \frac{r}{\mid z \mid}\f$
*/
vector two_sphere(vector z; float r) {
    return z / length(z) * r;
}

/*! \fn vector2 stereo2(vector c)
    \brief Stereographic projection from \f$S^2\f$.

    Stereographic projection from  \f$S^2\f$ into \f$C\f$.

    \param c the vector in \f$S^2\f$ to project into \f$C\f$, , must not be
        \f$(0, 0, 1)\top\f$

    \return the stereographic projection to \f$C\f$
*/
vector2 stereo2(vector c) {
    float x = c.x;
    float y = c.y;
    float z = c.z;
    return set(x, y) / (1-z);
}

/*! \fn vector stereo3(vector4 c)
    \brief Stereographic projection from \f$S^3\f$.

    Stereographic projection from  \f$S^3\f$ into \f$R^3\f$.

    \param c the vector in \f$S^3\f$ to project into \f$R^3\f$, must not be \f$(0, 0, 0, 1)\top\f$

    \return the stereographic projection to \f$R^3\f$
*/
vector stereo3(vector4 c) {
    float x = c.x;
    float y = c.y;
    float z = c.z;
    float w = c.w;
    return set(x, y, z) / (1-w);
}

/*! \fn vector4 stereo3_inv(vector c)
    \brief Inverse of the stereographic projection from \f$S^3\f$.

    Inverse from \f$R^3\f$ into \f$S^3\f$ of the stereographic projection.

    \param c the vector in \f$R^3\f$ to reproject into \f$S^3\f$.

    \return the projection into \f$S^3\f$
*/
vector4 stereo3_inv(vector c) {
    float x = c.x;
    float y = c.y;
    float z = c.z;
    return set(2*x, 2*y, 2*z, length2(c)-1) / (length2(c)+1);
}

vector stereo3_e4(vector4 c) {
    return set(c.x, c.y, c.z) / (1.-c.w);
}
vector stereo3_e4_inv(vector c) {
    return set(2*c.x, 2*c.y, 2*c.z, length2(c)-1) / (length2(c)+1.);
}

/*! \fn vector sphere_inversion(vector z; vector center; float scale)
    \brief Sphere inversion

    Perform a Möbius tranformation to project every point inside the the unit
    sphere in \f$R^3\f$ to outside and vice versa.

    \param z the original vector in \f$R^3\f$
    \param center the center of the sphere
    \param scale the radius of the sphere

    \return the inverted vector
*/
vector sphere_inversion(vector z; vector center; float scale) {
    // Compute translation, then transform in the origin and retranslate
    vector translation = set(center.x, center.y, center.z);
    vector transformed = z - translation;
    return transformed / length2(transformed) * pow(scale, 2) + translation;
}
