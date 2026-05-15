/* Copyright John E. Petersen III, 2026.
 * Any redistribution of this software in any form with 
 * any modifications must retain this license agreement. 
 * Commercial usage is forbidden without express written 
 * permission of the author/copyright holder.

 * John E. Petersen III, 2026
 * jepetersen@utexas.edu
 */

#ifndef ECHELON_H
#define ECHELON_H
#include "ndimensional.h"

//Swaps rows during echelon reduction
twoFormV rowSwap(twoFormV inMat, int index1, int index2)
{
    unsigned long int nSize = inMat.size();
    twoFormV tempMatrix = inMat;
    for (int n = 0; n < nSize - index1; n++)
        {
            inMat[index1 + n][index2] = tempMatrix[index1 + n][index1];
            inMat[index1 + n][index1] = tempMatrix[index1 + n][index2];
        }
    return inMat;
}

//Which indices to skip
bool skipCondition(int i, int j, int k)
{
    if(j <= i || k < i)
        return true;
    else return false;
}

//Echelon row reduction 
twoFormV echelonU(twoFormV inMatrix, twoFormV outMatrix)
{
    unsigned long int mSize = inMatrix.size();
    unsigned long int nSize = inMatrix[0].size();
    long double factor;
    for(int i = 0; i < nSize - 1; i++)
    {
        for (int j = 1; j < nSize; j++)
        {
            factor = -inMatrix[i][j] / inMatrix[i][i];
            if(inMatrix[i][i] != 0)
            {
                for(int k = 0; k < mSize; k++)
                {
                    if(skipCondition(i, j, k))
                        continue;
                    else
                    {
                        if(inMatrix[i][i] != 0)
                        {
                            if(factor != 0)
                            {
                                inMatrix[k][j] = (factor * inMatrix[k][i]) + inMatrix[k][j];
                            }
                        }
                        continue;
                    }
                }
            }
            else 
            {
                for (int p = nSize; p > 0; p--)
                {
                    if(inMatrix[i][i+nSize-p])
                        inMatrix = rowSwap(inMatrix, i, i+nSize-p);
                }
                j--;
                continue;
            }
        }
    }
    return inMatrix;
}

#endif // ECHELON_H
