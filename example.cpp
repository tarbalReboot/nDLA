// Perhaps some of the memory allocation can be handled in methods in header files in future. 
// As of now, they are a bit verbose in main()

#include <cmath>
#include <iostream>
#include "ndimensional.h"
#include "echelon.h"

int main()
{
	//input
	oneFormV testVector3 {3.0, 7.7, 9.1};
	oneFormV testVector4 {1.1, 4.1, 7.4};

	// add
	oneFormV *resultAdd;
	resultAdd = (oneFormV *)malloc((testVector3.size() + testVector4.size()) * sizeof(long double));
    *resultAdd = add(testVector3, testVector4);
	std::cout << "add: " << resultAdd[0][0] << ", " << resultAdd[0][1] << ", " << resultAdd[0][2] << std::endl;
	free(resultAdd);

	// normalize
	oneFormV *resultNorm;
	resultNorm = (oneFormV *)malloc((testVector3.size() * sizeof(long double)));
	*resultNorm = normalize(testVector3);
	std::cout << "normalize: " << resultNorm[0][0] << ", " << resultNorm[0][1] << ", " << resultNorm[0][2] << std::endl;
	free(resultNorm);

	
	// dot product
	long double *dotP;
	dotP = (long double *)malloc(testVector3.size() * sizeof(long double));
	*dotP = dot(testVector3, testVector4, *dotP);
	std::cout << "dot: " << *dotP << " " << std::endl;
	free(dotP);
	
	// outer product
    twoFormV *outerP = new twoFormV;
    outerP->assign(testVector3.size(), testVector4);
    outerP->reserve(testVector3.size() * testVector4.size() * sizeof(long double));
    *outerP = outerProduct(testVector3, testVector4, *outerP);
    std::cout << "outer product: " << std::endl;
    for (int i = 0; i < testVector3.size(); i++)
    {
        for(int j = 0; j < testVector4.size(); j++)
        {
            std::cout << " " << outerP[0][i][j] << " ";  // compiler bug? Output only works as a three-form tensor, so the first zero must be included. It is in fact a two-form.
	    }                     
        std::cout << std::endl;
    }
    free(outerP);

	////////// Input row vectors in Euclidean are column vectors in nDLA
	
//	twoForm testInMatrix1 {{3, -7, -2}, {-3, 5, 1}, {6, -4, 0}};
	twoFormV testInMatrix1 {{3, -3, 6}, {-7, 5, -4}, {-2, 1, 0}};

	//twoForm testInMatrix2 {{4, 3, -5}, {-4, -5, 7}, {8, 6, -8}};
    twoFormV testInMatrix2 {{4, -4, 8},{3, -5, 6},{-5, 7, -8}};

//	twoForm testInMatrix3 {{2, -1, 2}, {-6, 0, -2}, {8, -1, 5}};
	twoFormV testInMatrix3 {{2,-6,8},{-1,0,-1},{2,-2,5}};

//	twoForm testInMatrix4 {{2, -2, 4}, {1, -3, 1}, {3, 7, 5}};
	twoFormV testInMatrix4 {{2,1,3},{-2,-3,7},{4,1,5},{7,5,9}};

//	twoForm testInMatrix5 {{1, -2, -4, -3}, {2, -7, -7, -6}, {-1, 2, 6, 4}, {-4, -1, 9, 8}};
	twoFormV testInMatrix5 {{1,2,-1,-4},{-2,-7,2,-1},{-4,-7,6,9},{-3,-6,4,8}};

//	twoForm testInMatrix6 {{1, 3, 4, 0}, {-3, -6, -7, 2}, {3, 3, 0, -4}, {-5, -3, 2, 9}};
	twoFormV testInMatrix6 {{1,-3,3,-5},{3,-6,3,-3},{4,-7,0,2},{0,2,-4,9}};

//	twoFormV testInMatrix7 {{1, 2, 3, 4, 5}, {5, 4, 1, 2, 3},{10, 11, 12, 13, 14},{20, 25, 18, 24, 4},{2, 1, 12, 9, 11}};
	twoFormV testInMatrix7 {{1,5,10,20,2},{2,4,11,25,1},{3,1,12,18,12},{4,2,13,24,9},{5,3,14,4,11}};

	twoFormV testInMatrix8 {{1,2,4,6,8,10},{2,8,2,-1,-8,-2},{4,6,-1,2,10,4},{2,8,4,6,4,2},{-1,-4,2,12,-2,1},{1,8,18,-2,4,1}};

//	twoForm testInMatrix10 {{1, 2, 3, 4, 5, 6, 7}, {7, 6, 5, 4, 3, 2, 1}, {4, 3, 2, 1, 5, 6, 7}, {9, 8, 7, 6, 12, 14, 16},
//	 {50, 25, 20, 14, 12, 10, 8}, {20, 10, 25, 9, 22, 24, 32}, {36, 60, 18, 13, 17, 11, 2}};

	twoFormV testInMatrix9 {{3,4,3,2,1,5,6,10},{12,8,9,7,13,23,24,11},{10,21,22,13,14,15,16,17},{9,8,7,6,31,32,33,34},{8,1,1,2,1,1,1,1},{12,2,4,4,4,4,4,4},{3,3,3,3,3,3,3,3},{1,2,3,4,5,6,7,8},{55,44,33,32,31,22,25,41}};
    ///////////

	// begin row reduction:

    twoFormV *rowReduced = new twoFormV;
    rowReduced->assign(testInMatrix9.size(), testInMatrix9[0]);
    rowReduced->reserve(testInMatrix9.size() * testInMatrix9[0].size() * sizeof(long double));
    *rowReduced = echelonU(testInMatrix9, *rowReduced);

	std::cout << std::endl;
    std::cout << "Test OUT 9x8 matrix Echelon U reduction: " << std::endl;

    for(int i = 0; i < testInMatrix9[0].size(); i++)
	{
		for(int j = 0; j < testInMatrix9.size(); j++)
		{
            std::cout << rowReduced[0][j][i] << "    ";
		}
		std::cout << std::endl;
	}
	

	free(rowReduced);

	return 0;
}