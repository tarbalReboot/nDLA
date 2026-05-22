/* Copyright John E. Petersen III, 2026.
 * Any redistribution of this software in any form with 
 * any modifications must retain this license agreement. 
 * Commercial usage is forbidden without express written 
 * permission of the author/copyright holder.

 * John E. Petersen III, 2026
 * jepetersen@utexas.edu
 */

#ifndef NDIMENSIONAL_H
#define NDIMENSIONAL_H
#include <cmath>
#include <iostream>
#include <vector>

typedef std::vector<double> oneFormV;

typedef std::vector<std::vector <double>> twoFormV;

// adds two vectors of the same length -- will not add and will return only the first vector, if the two vectors have different dimensions. Flip sign of vec2 to subtract.
oneFormV add(oneFormV vec1, oneFormV vec2)
{
    int m = vec1.size();
    if(m != vec2.size())
    {
        std::cerr << "The two provided vectors are of different dimensions and cannot be added! See std::vector<float> add(...) method in vectorMath.h" << std::endl;
        return vec1;
    }
    else
    {
        for (int i=0; i < m; i++)
        {
            vec1[i] += vec2[i];
        }
    }
    return vec1;
}

// The scalar dot product requires two vectors of the same dimension as input. 
// The return lvalue pointer must be defined in the main function with the 
// buffer updated via malloc before being passed here as a reference as
// the third variable. See example file, test.cpp.
long double dot(oneFormV vec1, oneFormV vec2, long double &rDouble)
{
    int m = vec1.size();
    if(m != vec2.size())
    {
        std::cerr << "The two provided vectors are of different dimensions and cannot produce a scalar product in any mathematically meaningful way!" << std::endl;
        return 0;
    }
    
    else
    {
        for (int i=0; i < m; i++)
        {
            rDouble += (vec1[i] * vec2[i]);
        }
    }
    return rDouble;
}

// vector outer products do not require equal dimensionality. Tested to high dimensionality. Memory must be allocated 
// appropriately, or you will have serious problems. See test.cpp.
twoFormV outerProduct(oneFormV columnVector, oneFormV rowVector, twoFormV rMatrix)
{
    for(int i=0; i< columnVector.size(); i++)
    {
        for(int j=0; j< rowVector.size(); j++)
        {
            rMatrix[i][j] = columnVector[i] * rowVector[j];
        }
    }
    return rMatrix;
}

// calculates a unit vector of the given vector of unit length one
oneFormV normalize(oneFormV givenVector)
{
    float sumOfSquares;
    for(int i=0; i< givenVector.size(); i++)
    {
        sumOfSquares += givenVector[i] * givenVector[i];
    }
    for(int i=0; i<= (int)givenVector.size(); i++)
    {
        givenVector[i] = givenVector[i] / sqrt(sumOfSquares);
    }
    return givenVector;
}

#endif // NDIMENSIONAL_H
