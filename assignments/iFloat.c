#include "Debug.h"
#include "iFloat.h"

/** @file iFloat.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in iFloat.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Your name</b> goes here
 */

/* declaration for useful function contained in testFloat.c */
const char* getBinary (iFloat_t value);

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetSign (iFloat_t x) {
  return (x & 0x8000) >> 15;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetExp (iFloat_t x) {
  return (x & 0x7F80) >> 10;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetVal (iFloat_t x) {
  int mantissa = (x & 0x07FF);
  return floatGetSign(x) == 1 ? (~mantissa + 1) : mantissa;
}

/** @todo Implement based on documentation contained in iFloat.h */
void floatGetAll(iFloat_t x, iFloat_t* sign, iFloat_t* exp, iFloat_t* val) {
   * sign = floatGetSign(x);
   * exp = floatGetExp(x);
   * val = floatGetVal(x);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatLeftMost1 (iFloat_t bits) {
  for (int i = 15; i > 0; i--) {
    int bitValue = (bits & (1 << i)) != 0;
    if(bitValue == 1) {
      return i;
    }
  }
  return -1;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAbs (iFloat_t x) {
  return (x & 0x7FFF);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatNegate (iFloat_t x) {
  return (x > 0 || x < 0) ? x ^ 0x8000 : x;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAdd (iFloat_t x, iFloat_t y) {
    if (x == 0 && y == 0) return 0;
    if (x == 0 && y != 0) return y;
    if (x != 0 && y == 0) return x;
    iFloat_t expX = floatGetExp(x);
    iFloat_t valX = floatGetVal(x);
    iFloat_t expY = floatGetExp(y);
    iFloat_t valY = floatGetVal(y);

    if (expX > expY){
       int diff = expX - expY;
       expY += diff;
       valY = valY >> diff;
    } else if (expX < expY){
       int diff = expY - expX;
       expX += diff;
       valX = valX >> diff;
    }

    iFloat_t finalExp = expY;
    iFloat_t finalVal = valX + valY;
    iFloat_t finalSign = floatGetSign(finalVal);

    iFloat_t valCheck = finalVal;
    if(finalSign == 1){
       valCheck = ~finalVal + 1;
    }

    iFloat_t floatCheck = floatLeftMost1(valCheck);
    if(floatCheck < 10){
       int diff = 10 - floatCheck;
       valCheck = valCheck << diff;
       finalExp -= diff;
    } else if (floatCheck > 10){
       int diff = floatCheck - 10;
       valCheck = valCheck >> diff;
       finalExp += diff;
    }

    valCheck = valCheck ^ 0x0400;
    return (finalSign << 15) | (finalExp << 10) | (valCheck);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatSub (iFloat_t x, iFloat_t y) {
  return floatAdd(x, floatNegate(y));
}