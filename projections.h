// This contains some basic projections in one- to four-dimensional real space.

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
