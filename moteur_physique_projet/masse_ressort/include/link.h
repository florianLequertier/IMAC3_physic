#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

class Pmat;

class Link
{
public :
    Pmat* M1;
    Pmat* M2;
    float k;
    float z;
    float l;
    float s1;
    float s2;
    float s3;

    Link();
    ~Link();

    void setConnection(Pmat* _M1, Pmat* _M2);
    void setParameters(float _k, float _z, float _l, float _s1, float _s2, float _s3);

};

#endif // LINK_H

