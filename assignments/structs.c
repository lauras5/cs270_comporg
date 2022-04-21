typedef struct dStruct {
    int *x;         // pointer to int
    int y;          // int
} dStruct_t;

int main() {
    dStruct_t *d = (dStruct_t *) malloc(sizeof(dStruct_t));     // allocating mem for pointer to dstruct
    // malloc has garbage values, initialize members of struct
    d->x = (int *) malloc(sizeof(int));     // store pointer to int in x
    // (*d).x = 6
    *d->x = 6;                              // deref x and set
    d->y = 5;
    // use d for program
    // ...
    // end free pointer
    free(d->x);
    free(d);                                // address gets freed last
}