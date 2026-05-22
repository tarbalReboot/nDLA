nDLA 0.2.1.0

N-dimensional Linear Algebra in classless C++.

This project began as The Euclidean Project (https://github.com/tarbalReboot/euclideanSpace/) by the same sole author. The goal of this project is to generalize several of the R2, R3, and R4 linear algebra routines in Euclidean to N-dimensionality. This goal is quite a bit more complex, so the function calls are much more difficult to master, as a result. 

Included is an example.cpp file, as a crude example of how to allocate a memory buffer for Echelon row reduction, etc. This package is in its infancy, and even the author does not know how far it will go.

Copyright John E. Petersen III, 2026. Any redistribution of this software in any form with any modifications must retain this license agreement. Commercial usage is forbidden without express written permission of the author/copyright holder.

My echelon.h header file is in need of peer review, so despite an extra superflous boolean check on line 57, I'm not taking it out right now -- I'd prefer to retain the timestamp on the row reduction algorithm. The typeform definitions are in the other (nDimensional.h) header file, mainly my personal licensing reasons. 

In this release, long doubles have been changed to doubles for stability reasons, despite enhancing rounding errors, and the algorithm has been tested on up to a 50x49 matrix successfully in the order of microseconds on a modest CPU. Also included in this release is a shell script designed to generate your own matrix of your own test dimensions. The example file example.cpp tests the generated 50x49 matrix.

John E. Petersen III, 2026
jepetersen@utexas.edu
