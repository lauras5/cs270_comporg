
/**
 *  @author Laura Salcido
 */

#include <stdio.h>

/** @todo implement in <code>numconv.c</code> based on documentation contained
 *  in <code>numconv.h</code>.
 */
char int_to_char (int value, int radix) {
    if (value > (radix - 1)) return '?';
    int remainder = value % radix;
    return remainder < 10 ? remainder + '0' : remainder - 10 + 'A';
}

/** @todo implement in <code>numconv.c</code> based on documentation contained
 *  in <code>numconv.h</code>.
 */
int char_to_int (char digit, int radix) {
    if (radix < 2 || radix > 36) return -1;
    int value = (int)digit;

    if (47 < value && value < 58) {
        value = value - '0';
    }
    else if (64 < value && value < 91) {
        value = value - 'A' + 10;
    }
    else if (96 < value && value < 123) {
        value = value - 'a' + 10;
    }

    return (value <= (radix - 1)) ? value : -1;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained
 *  in <code>numconv.h</code>.
 */
void div_rem (int numerator, int divisor, int* remainder, int* quotient) {
    *remainder = numerator % divisor;
    *quotient = numerator / divisor;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained
 *  in <code>numconv.h</code>.
 */
int ascii_to_int (int valueOfPrefix, int radix) {
    char prefix = getchar();
    if (prefix == '\n') return valueOfPrefix;

    valueOfPrefix = radix * valueOfPrefix + char_to_int(prefix, radix);
    return ascii_to_int(valueOfPrefix, radix);
}

/** @todo implement in <code>numconv.c</code> based on documentation contained
 *  in <code>numconv.h</code>.
 */
void int_to_ascii (int value, int radix) {
    if (value != 0) {
        int quotient = value / radix;
        int remainder = value % radix;
        int_to_ascii(quotient, radix);
        putchar(int_to_char(remainder, radix));
    }
}

/** @todo implement in <code>numconv.c</code> based on documentation contained
 *  in <code>numconv.h</code>.
 */
double frac_to_double (int radix) {
    char input = getchar();
    if (input == '\n') return 0.0;

    return (double)char_to_int(input)/ + frac_to_double
    return -1.0;
}
