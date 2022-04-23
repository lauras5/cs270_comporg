#include <stdio.h>
#define TOTAL_FLIGHTS 100

/* Structure Definition */
// struct containing 6 member elements
// tag flightType
struct flightType {
    char flightNum[7];      // max 6 chars
    int altitude;           // in meters
    int longitude;          // in tenth of degrees
    int latitude;           // in tenth of degrees
    int heading;            // in tenth of degrees
    double airSpeed;        // in kilometers/hour
}

// typedef --> Flight == struct flightType
typedef struct flightType Flight;

int Collide(Flight *planeA, Flight *planeB);
void PotentialCollisions(Flight planes[]);

int Collide(Flight *planeA, Flight *planeB) {   // pass pointers, more efficient
    if (planeA->altitude == planeB->altitude) {
        /** additional logic **/
    }
    else
        return 0;
}

void PotentialCollisions(Flight planes[]) {
    int i, j;
    for (i = 0; i < TOTAL_FLIGHTS; i++) {
        for (j = 0; j < TOTAL_FLIGHTS; j++) {
            printf("Flights %s and %s are on collision course!\n",
            planes[i].flightNum, planes[j].flightNum);
        }
    }
}

//
//// declare var of new struct type
//// struct flightType plane;
//Flight plane;
///*  plane gets allocated on (rt)stack if local and
//    occupies region of memory large enough to
//    hold all member elements
//*/
//
//// structs use dot notation
//plane.airSpeed = 800.0;
//plane.altitude = 10000;
//
//Flight planes[100]; // array of 100 structures
//
//int i;
//double sum = 0;
//double averageAirspeed;
//for (i = 0; i < 100; i++)
//    sum += plane[i].airSpeed;
//averageAirSpeed = sum / airSpeed;
//
//// can also create pointer to structure
//Flight *planePtr;
//planePtr = &plane[34];
//// access
//(*planePtr).longitude;
//// or
//planePtr->longitude;    // deref elements of structure type


