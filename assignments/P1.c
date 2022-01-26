// P1 Assignment
// Author: Laura Salcido
// Date:   1/21/2022
// Class:  CS270

// Include files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// example of a global array
double input[5];
double output[4];

// this function can be used as a guide for the funtions you will implement
void computeSphere(double radius, double *addressOfVolume)
{
    // Compute volume
    double result = (4.0 / 3.0 ) * 3.141593 * radius * radius * radius;

    // Dereference pointer to return result
    *addressOfVolume = result;
}

void computeCube(double side, double *addressOfVolume)
{ 
    // Compute volume
    double result = side * side * side;

    // Dereference pointer to return result
    *addressOfVolume = result;
}

void computeTetrahedron(double side, double *addressOfVolume)
{ 
    // Compute volume
    double result = 0.117851 * side * side * side;

    // Dereference pointer to return result
    *addressOfVolume = result;
}

void computeCylinder(double radius, double height, double *addressOfVolume)
{ 
    // Compute area
    double result = 3.141593 * radius * radius * height;

    // Dereference pointer to return result
    *addressOfVolume = result;
}

int main(int argc, char *argv[])
{
    // Check number of arguments
    if (argc != 6) {
        printf("usage: ./P1 <double> <double> <double> <double> <double>\n");
        return EXIT_FAILURE;
    }

    // Parse arguments
    for (int i = 1; i < 6; i++) {
        double argument = atof(argv[i]);
        input[i - 1] = argument;
    } 

    // Local variable

    // Call function
    computeSphere(input[0], &output[0]);
    computeCube(input[1], &output[1]);
    computeTetrahedron(input[2], &output[2]);
    computeCylinder(input[3], input[4], &output[3]);

    // Print area
    printf("SPHERE, radius = %.5f, volume = %.5f.\n", input[0], output[0]);
    printf("CUBE, side = %.5f, volume = %.5f.\n", input[1] , output[1]);
    printf("TETRAHEDRON, side = %.5f, volume = %.5f.\n", input[2], output[2]);
    printf("CYLINDER, radius = %.5f, height = %.5f, volume = %.5f.\n", input[3], input[4], output[3]);


    // Return success
    return EXIT_SUCCESS;
}
