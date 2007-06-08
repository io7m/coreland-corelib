#include <stdio.h>
#include <math.h>
#include "../fmt.h"
#include "../str.h"

struct fmt_test {
  unsigned int sig;
  unsigned int len;
  double num;
  char *str;
};

static const struct fmt_test tests[] = {
  /* zero tests */
  { 0, 0, 0.0, "" },
  { 1, 3, 0.0, "0.0" },
  { 2, 4, 0.0, "0.00" },
  { 3, 5, 0.0, "0.000" },
  { 4, 6, 0.0, "0.0000" },
  { 5, 7, 0.0, "0.00000" },
  { 6, 8, 0.0, "0.000000" },
  { 7, 9, 0.0, "0.0000000" },
  { 8, 10, 0.0, "0.00000000" },
  { 9, 11, 0.0, "0.000000000" },
  { 10, 12, 0.0, "0.0000000000" },
  { 11, 13, 0.0, "0.00000000000" },
  { 12, 14, 0.0, "0.000000000000" },
  { 13, 15, 0.0, "0.0000000000000" },
  { 14, 16, 0.0, "0.00000000000000" },
  { 15, 17, 0.0, "0.000000000000000" },

  /* negative zero tests */
  { 0, 0, -0.0, "" },
  { 1, 4, -0.0, "-0.0" },
  { 2, 5, -0.0, "-0.00" },
  { 3, 6, -0.0, "-0.000" },
  { 4, 7, -0.0, "-0.0000" },
  { 5, 8, -0.0, "-0.00000" },
  { 6, 9, -0.0, "-0.000000" },
  { 7, 10, -0.0, "-0.0000000" },
  { 8, 11, -0.0, "-0.00000000" },
  { 9, 12, -0.0, "-0.000000000" },
  { 10, 13, -0.0, "-0.0000000000" },
  { 11, 14, -0.0, "-0.00000000000" },
  { 12, 15, -0.0, "-0.000000000000" },
  { 13, 16, -0.0, "-0.0000000000000" },
  { 14, 17, -0.0, "-0.00000000000000" },
  { 15, 18, -0.0, "-0.000000000000000" },

  /* integral */
  { 0, 0, 123456789.0, "" },
  { 1, 11, 123456789.0, "123456789.0" },
  { 2, 12, 123456789.0, "123456789.00" },
  { 3, 13, 123456789.0, "123456789.000" },
  { 4, 14, 123456789.0, "123456789.0000" },
  { 5, 15, 123456789.0, "123456789.00000" },
  { 6, 16, 123456789.0, "123456789.000000" },
  { 7, 17, 123456789.0, "123456789.0000000" },
  { 8, 18, 123456789.0, "123456789.00000000" },
  { 9, 19, 123456789.0, "123456789.000000000" },
  { 10, 20, 123456789.0, "123456789.0000000000" },
  { 11, 21, 123456789.0, "123456789.00000000000" },
  { 12, 22, 123456789.0, "123456789.000000000000" },
  { 13, 23, 123456789.0, "123456789.0000000000000" },
  { 14, 24, 123456789.0, "123456789.00000000000000" },
  { 15, 25, 123456789.0, "123456789.000000000000000" },

  /* fractional */
  { 0, 0, 0.123456789, "" },
  { 1, 3, 0.123456789, "0.1" },
  { 2, 4, 0.123456789, "0.12" },
  { 3, 5, 0.123456789, "0.123" },
  { 4, 6, 0.123456789, "0.1235" },
  { 5, 7, 0.123456789, "0.12346" },
  { 6, 8, 0.123456789, "0.123457" },
  { 7, 9, 0.123456789, "0.1234568" },
  { 8, 10, 0.123456789, "0.12345679" },
  { 9, 11, 0.123456789, "0.123456789" },
  { 10, 13, 0.123456789, "0.12345678810" },
  { 11, 14, 0.123456789, "0.123456788910" },
  { 12, 15, 0.123456789, "0.1234567889910" },
  { 13, 16, 0.123456789, "0.12345678899910" },
  { 14, 17, 0.123456789, "0.123456788999910" },
  { 15, 18, 0.123456789, "0.1234567889999910" },

  /* negative integral */
  { 0, 0, -123456789.0, "" },
  { 1, 12, -123456789.0, "-123456789.0" },
  { 2, 13, -123456789.0, "-123456789.00" },
  { 3, 14, -123456789.0, "-123456789.000" },
  { 4, 15, -123456789.0, "-123456789.0000" },
  { 5, 16, -123456789.0, "-123456789.00000" },
  { 6, 17, -123456789.0, "-123456789.000000" },
  { 7, 18, -123456789.0, "-123456789.0000000" },
  { 8, 19, -123456789.0, "-123456789.00000000" },
  { 9, 20, -123456789.0, "-123456789.000000000" },
  { 10, 21, -123456789.0, "-123456789.0000000000" },
  { 11, 22, -123456789.0, "-123456789.00000000000" },
  { 12, 23, -123456789.0, "-123456789.000000000000" },
  { 13, 24, -123456789.0, "-123456789.0000000000000" },
  { 14, 25, -123456789.0, "-123456789.00000000000000" },
  { 15, 26, -123456789.0, "-123456789.000000000000000" },

  /* negative fractional */
  { 0, 0, -0.123456789, "" },
  { 1, 4, -0.123456789, "-0.1" },
  { 2, 5, -0.123456789, "-0.12" },
  { 3, 6, -0.123456789, "-0.123" },
  { 4, 7, -0.123456789, "-0.1235" },
  { 5, 8, -0.123456789, "-0.12346" },
  { 6, 9, -0.123456789, "-0.123457" },
  { 7, 10, -0.123456789, "-0.1234568" },
  { 8, 11, -0.123456789, "-0.12345679" },
  { 9, 12, -0.123456789, "-0.123456789" },
  { 10, 14, -0.123456789, "-0.12345678810" },
  { 11, 15, -0.123456789, "-0.123456788910" },
  { 12, 16, -0.123456789, "-0.1234567889910" },
  { 13, 17, -0.123456789, "-0.12345678899910" },
  { 14, 18, -0.123456789, "-0.123456788999910" },
  { 15, 19, -0.123456789, "-0.1234567889999910" },

  /* large */
  { 0, 0, 123456789.987654321, "" },
  { 1, 12, 123456789.987654321, "123456789.10" },
  { 2, 12, 123456789.987654321, "123456789.99" },
  { 3, 13, 123456789.987654321, "123456789.988" },
  { 4, 14, 123456789.987654321, "123456789.9877" },
  { 5, 15, 123456789.987654321, "123456789.98765" },
  { 6, 16, 123456789.987654321, "123456789.987654" },
  { 7, 17, 123456789.987654321, "123456789.9876543" },
  { 8, 18, 123456789.987654321, "123456789.98765433" },
  { 9, 19, 123456789.987654321, "123456789.987654328" },
  { 10, 20, 123456789.987654321, "123456789.9876543283" },
  { 11, 21, 123456789.987654321, "123456789.98765432835" },
  { 12, 22, 123456789.987654321, "123456789.987654328346" },
  { 13, 23, 123456789.987654321, "123456789.9876543283463" },
  { 14, 24, 123456789.987654321, "123456789.98765432834625" },
  { 15, 25, 123456789.987654321, "123456789.987654328346252" },

  /* negative large */
  { 0, 0, -123456789.987654321, "" },
  { 1, 13, -123456789.987654321, "-123456789.10" },
  { 2, 13, -123456789.987654321, "-123456789.99" },
  { 3, 14, -123456789.987654321, "-123456789.988" },
  { 4, 15, -123456789.987654321, "-123456789.9877" },
  { 5, 16, -123456789.987654321, "-123456789.98765" },
  { 6, 17, -123456789.987654321, "-123456789.987654" },
  { 7, 18, -123456789.987654321, "-123456789.9876543" },
  { 8, 19, -123456789.987654321, "-123456789.98765433" },
  { 9, 20, -123456789.987654321, "-123456789.987654328" },
  { 10, 21, -123456789.987654321, "-123456789.9876543283" },
  { 11, 22, -123456789.987654321, "-123456789.98765432835" },
  { 12, 23, -123456789.987654321, "-123456789.987654328346" },
  { 13, 24, -123456789.987654321, "-123456789.9876543283463" },
  { 14, 25, -123456789.987654321, "-123456789.98765432834625" },
  { 15, 26, -123456789.987654321, "-123456789.987654328346252" },

  /* DBL_MIN, DBL_MAX */
  { 15, 20, 1e37, "1.000000000000001e37" },
  { 14, 19, 1e37, "1.00000000000000e37" },
  { 13, 18, 1e37, "1.0000000000000e37" },
  { 12, 17, 1e37, "1.000000000000e37" },
  { 11, 16, 1e37, "1.00000000000e37" },
  { 10, 15, 1e37, "1.0000000000e37" },
  { 9, 14, 1e37,  "1.000000000e37" },
  { 8, 13, 1e37,  "1.00000000e37" },
  { 7, 12, 1e37,  "1.0000000e37" },
  { 6, 11, 1e37,  "1.000000e37" },
  { 5, 10, 1e37,  "1.00000e37" },
  { 4, 9, 1e37,  "1.0000e37" },
  { 3, 8, 1e37,  "1.000e37" },
  { 2, 7, 1e37,  "1.00e37" },
  { 1, 6, 1e37,  "1.0e37" },

  { 15, 21, 1e-37, "1.000000000000001e-37" },
  { 14, 20, 1e-37, "1.00000000000000e-37" },
  { 13, 19, 1e-37, "1.0000000000000e-37" },
  { 12, 18, 1e-37, "1.000000000000e-37" },
  { 11, 17, 1e-37, "1.00000000000e-37" },
  { 10, 16, 1e-37, "1.0000000000e-37" },
  { 9, 15, 1e-37,  "1.000000000e-37" },
  { 8, 14, 1e-37,  "1.00000000e-37" },
  { 7, 13, 1e-37,  "1.0000000e-37" },
  { 6, 12, 1e-37,  "1.000000e-37" },
  { 5, 11, 1e-37,  "1.00000e-37" },
  { 4, 10, 1e-37,  "1.0000e-37" },
  { 3, 9, 1e-37,  "1.000e-37" },
  { 2, 8, 1e-37,  "1.00e-37" },
  { 1, 7, 1e-37,  "1.0e-37" },

  /* t_scan_doub */
  { 15, 18, 1e1, "10.000000000000000" },
  { 14, 17, 1e1, "10.00000000000000" },
  { 13, 16, 1e1, "10.0000000000000" },
  { 12, 15, 1e1, "10.000000000000" },
  { 11, 14, 1e1, "10.00000000000" },
  { 10, 13, 1e1, "10.0000000000" },
  { 9, 12, 1e1, "10.000000000" },
  { 8, 11, 1e1, "10.00000000" },
  { 7, 10, 1e1, "10.0000000" },
  { 6, 9, 1e1, "10.000000" },
  { 5, 8, 1e1, "10.00000" },
  { 4, 7, 1e1, "10.0000" },
  { 3, 6, 1e1, "10.000" },
  { 2, 5, 1e1, "10.00" },
  { 1, 4, 1e1, "10.0" },

  { 15, 17, 1e-1, "0.100000000000000" },
  { 14, 16, 1e-1, "0.10000000000000" },
  { 13, 15, 1e-1, "0.1000000000000" },
  { 12, 14, 1e-1, "0.100000000000" },
  { 11, 13, 1e-1, "0.10000000000" },
  { 10, 12, 1e-1, "0.1000000000" },
  { 9, 11, 1e-1,  "0.100000000" },
  { 8, 10, 1e-1,  "0.10000000" },
  { 7, 9, 1e-1,   "0.1000000" },
  { 6, 8, 1e-1,   "0.100000" },
  { 5, 7, 1e-1,   "0.10000" },
  { 4, 6, 1e-1,   "0.1000" },
  { 3, 5, 1e-1,   "0.100" },
  { 2, 4, 1e-1,   "0.10" },
  { 1, 3, 1e-1,   "0.1" },

  { 15, 27, 1e10, "10000000000.000000000000000" },
  { 14, 26, 1e10, "10000000000.00000000000000" },
  { 13, 25, 1e10, "10000000000.0000000000000" },
  { 12, 24, 1e10, "10000000000.000000000000" },
  { 11, 23, 1e10, "10000000000.00000000000" },
  { 10, 22, 1e10, "10000000000.0000000000" },
  { 9, 21, 1e10,  "10000000000.000000000" },
  { 8, 20, 1e10,  "10000000000.00000000" },
  { 7, 19, 1e10,  "10000000000.0000000" },
  { 6, 18, 1e10,  "10000000000.000000" },
  { 5, 17, 1e10,  "10000000000.00000" },
  { 4, 16, 1e10,  "10000000000.0000" },
  { 3, 15, 1e10,  "10000000000.000" },
  { 2, 14, 1e10,  "10000000000.00" },
  { 1, 13, 1e10,  "10000000000.0" },

  { 15, 17, 1e-10, "0.000000000100000" },
  { 14, 16, 1e-10, "0.00000000010000" },
  { 13, 15, 1e-10, "0.0000000001000" },
  { 12, 14, 1e-10, "0.000000000100" },
  { 11, 13, 1e-10, "0.00000000010" },
  { 10, 12, 1e-10, "0.0000000001" },
  { 9, 11, 1e-10,  "0.000000000" },
  { 8, 10, 1e-10,  "0.00000000" },
  { 7, 9, 1e-10,   "0.0000000" },
  { 6, 8, 1e-10,   "0.000000" },
  { 5, 7, 1e-10,   "0.00000" },
  { 4, 6, 1e-10,   "0.0000" },
  { 3, 5, 1e-10,   "0.000" },
  { 2, 4, 1e-10,   "0.00" },
  { 1, 3, 1e-10,   "0.0" },

  { 15, 19, -1e1, "-10.000000000000000" },
  { 14, 18, -1e1, "-10.00000000000000" },
  { 13, 17, -1e1, "-10.0000000000000" },
  { 12, 16, -1e1, "-10.000000000000" },
  { 11, 15, -1e1, "-10.00000000000" },
  { 10, 14, -1e1, "-10.0000000000" },
  { 9, 13, -1e1, "-10.000000000" },
  { 8, 12, -1e1, "-10.00000000" },
  { 7, 11, -1e1, "-10.0000000" },
  { 6, 10, -1e1, "-10.000000" },
  { 5, 9, -1e1, "-10.00000" },
  { 4, 8, -1e1, "-10.0000" },
  { 3, 7, -1e1, "-10.000" },
  { 2, 6, -1e1, "-10.00" },
  { 1, 5, -1e1, "-10.0" },

  { 15, 18, -1e-1, "-0.100000000000000" },
  { 14, 17, -1e-1, "-0.10000000000000" },
  { 13, 16, -1e-1, "-0.1000000000000" },
  { 12, 15, -1e-1, "-0.100000000000" },
  { 11, 14, -1e-1, "-0.10000000000" },
  { 10, 13, -1e-1, "-0.1000000000" },
  { 9, 12, -1e-1,  "-0.100000000" },
  { 8, 11, -1e-1,  "-0.10000000" },
  { 7, 10, -1e-1,  "-0.1000000" },
  { 6, 9, -1e-1,   "-0.100000" },
  { 5, 8, -1e-1,   "-0.10000" },
  { 4, 7, -1e-1,   "-0.1000" },
  { 3, 6, -1e-1,   "-0.100" },
  { 2, 5, -1e-1,   "-0.10" },
  { 1, 4, -1e-1,   "-0.1" },

  { 15, 28, -1e10, "-10000000000.000000000000000" },
  { 14, 27, -1e10, "-10000000000.00000000000000" },
  { 13, 26, -1e10, "-10000000000.0000000000000" },
  { 12, 25, -1e10, "-10000000000.000000000000" },
  { 11, 24, -1e10, "-10000000000.00000000000" },
  { 10, 23, -1e10, "-10000000000.0000000000" },
  { 9, 22, -1e10,  "-10000000000.000000000" },
  { 8, 21, -1e10,  "-10000000000.00000000" },
  { 7, 20, -1e10,  "-10000000000.0000000" },
  { 6, 19, -1e10,  "-10000000000.000000" },
  { 5, 18, -1e10,  "-10000000000.00000" },
  { 4, 17, -1e10,  "-10000000000.0000" },
  { 3, 16, -1e10,  "-10000000000.000" },
  { 2, 15, -1e10,  "-10000000000.00" },
  { 1, 14, -1e10,  "-10000000000.0" },

  { 15, 18, -1e-10, "-0.000000000100000" },
  { 14, 17, -1e-10, "-0.00000000010000" },
  { 13, 16, -1e-10, "-0.0000000001000" },
  { 12, 15, -1e-10, "-0.000000000100" },
  { 11, 14, -1e-10, "-0.00000000010" },
  { 10, 13, -1e-10, "-0.0000000001" },
  { 9, 12, -1e-10,  "-0.000000000" },
  { 8, 11, -1e-10,  "-0.00000000" },
  { 7, 10, -1e-10,  "-0.0000000" },
  { 6, 9, -1e-10,   "-0.000000" },
  { 5, 8, -1e-10,   "-0.00000" },
  { 4, 7, -1e-10,   "-0.0000" },
  { 3, 6, -1e-10,   "-0.000" },
  { 2, 5, -1e-10,   "-0.00" },
  { 1, 4, -1e-10,   "-0.0" },

  { 15, 18, 1.0e1, "10.000000000000000" },
  { 14, 17, 1.0e1, "10.00000000000000" },
  { 13, 16, 1.0e1, "10.0000000000000" },
  { 12, 15, 1.0e1, "10.000000000000" },
  { 11, 14, 1.0e1, "10.00000000000" },
  { 10, 13, 1.0e1, "10.0000000000" },
  { 9, 12, 1.0e1,  "10.000000000" },
  { 8, 11, 1.0e1,  "10.00000000" },
  { 7, 10, 1.0e1,  "10.0000000" },
  { 6, 9, 1.0e1,   "10.000000" },
  { 5, 8, 1.0e1,   "10.00000" },
  { 4, 7, 1.0e1,   "10.0000" },
  { 3, 6, 1.0e1,   "10.000" },
  { 2, 5, 1.0e1,   "10.00" },
  { 1, 4, 1.0e1,   "10.0" },

  { 15, 17, 1.0e-1, "0.100000000000000" },
  { 14, 16, 1.0e-1, "0.10000000000000" },
  { 13, 15, 1.0e-1, "0.1000000000000" },
  { 12, 14, 1.0e-1, "0.100000000000" },
  { 11, 13, 1.0e-1, "0.10000000000" },
  { 10, 12, 1.0e-1, "0.1000000000" },
  { 9, 11, 1.0e-1, "0.100000000" },
  { 8, 10, 1.0e-1, "0.10000000" },
  { 7, 9, 1.0e-1, "0.1000000" },
  { 6, 8, 1.0e-1, "0.100000" },
  { 5, 7, 1.0e-1, "0.10000" },
  { 4, 6, 1.0e-1, "0.1000" },
  { 3, 5, 1.0e-1, "0.100" },
  { 2, 4, 1.0e-1, "0.10" },
  { 1, 3, 1.0e-1, "0.1" },

  { 15, 27, 1.0e10, "10000000000.000000000000000" },
  { 14, 26, 1.0e10, "10000000000.00000000000000" },
  { 13, 25, 1.0e10, "10000000000.0000000000000" },
  { 12, 24, 1.0e10, "10000000000.000000000000" },
  { 11, 23, 1.0e10, "10000000000.00000000000" },
  { 10, 22, 1.0e10, "10000000000.0000000000" },
  { 9, 21, 1.0e10, "10000000000.000000000" },
  { 8, 20, 1.0e10, "10000000000.00000000" },
  { 7, 19, 1.0e10, "10000000000.0000000" },
  { 6, 18, 1.0e10, "10000000000.000000" },
  { 5, 17, 1.0e10, "10000000000.00000" },
  { 4, 16, 1.0e10, "10000000000.0000" },
  { 3, 15, 1.0e10, "10000000000.000" },
  { 2, 14, 1.0e10, "10000000000.00" },
  { 1, 13, 1.0e10, "10000000000.0" },

  { 15, 17, 1.0e-10, "0.000000000100000" },
  { 14, 16, 1.0e-10, "0.00000000010000" },
  { 13, 15, 1.0e-10, "0.0000000001000" },
  { 12, 14, 1.0e-10, "0.000000000100" },
  { 11, 13, 1.0e-10, "0.00000000010" },
  { 10, 12, 1.0e-10, "0.0000000001" },
  { 9, 11, 1.0e-10, "0.000000000" },
  { 8, 10, 1.0e-10, "0.00000000" },
  { 7, 9, 1.0e-10, "0.0000000" },
  { 6, 8, 1.0e-10, "0.000000" },
  { 5, 7, 1.0e-10, "0.00000" },
  { 4, 6, 1.0e-10, "0.0000" },
  { 3, 5, 1.0e-10, "0.000" },
  { 2, 4, 1.0e-10, "0.00" },
  { 1, 3, 1.0e-10, "0.0" },

  { 15, 19, -1.0e1, "-10.000000000000000" },
  { 14, 18, -1.0e1, "-10.00000000000000" },
  { 13, 17, -1.0e1, "-10.0000000000000" },
  { 12, 16, -1.0e1, "-10.000000000000" },
  { 11, 15, -1.0e1, "-10.00000000000" },
  { 10, 14, -1.0e1, "-10.0000000000" },
  { 9, 13, -1.0e1, "-10.000000000" },
  { 8, 12, -1.0e1, "-10.00000000" },
  { 7, 11, -1.0e1, "-10.0000000" },
  { 6, 10, -1.0e1, "-10.000000" },
  { 5, 9, -1.0e1, "-10.00000" },
  { 4, 8, -1.0e1, "-10.0000" },
  { 3, 7, -1.0e1, "-10.000" },
  { 2, 6, -1.0e1, "-10.00" },
  { 1, 5, -1.0e1, "-10.0" },

  /* longest string in characters assuming DBL_MAX == 15 */
  { 15, 32, -1e14, "-100000000000000.000000000000000" },
  { 14, 31, -1e14, "-100000000000000.00000000000000" },
  { 13, 30, -1e14, "-100000000000000.0000000000000" },
  { 12, 29, -1e14, "-100000000000000.000000000000" },
  { 11, 28, -1e14, "-100000000000000.00000000000" },
  { 10, 27, -1e14, "-100000000000000.0000000000" },
  { 9, 26, -1e14, "-100000000000000.000000000" },
  { 8, 25, -1e14, "-100000000000000.00000000" },
  { 7, 24, -1e14, "-100000000000000.0000000" },
  { 6, 23, -1e14, "-100000000000000.000000" },
  { 5, 22, -1e14, "-100000000000000.00000" },
  { 4, 21, -1e14, "-100000000000000.0000" },
  { 3, 20, -1e14, "-100000000000000.000" },
  { 2, 19, -1e14, "-100000000000000.00" },
  { 1, 18, -1e14, "-100000000000000.0" },

  { 15, 18, -1.0e-1, "-0.100000000000000" },
  { 14, 17, -1.0e-1, "-0.10000000000000" },
  { 13, 16, -1.0e-1, "-0.1000000000000" },
  { 12, 15, -1.0e-1, "-0.100000000000" },
  { 11, 14, -1.0e-1, "-0.10000000000" },
  { 10, 13, -1.0e-1, "-0.1000000000" },
  { 9, 12, -1.0e-1,  "-0.100000000" },
  { 8, 11, -1.0e-1,  "-0.10000000" },
  { 7, 10, -1.0e-1,  "-0.1000000" },
  { 6, 9, -1.0e-1,  "-0.100000" },
  { 5, 8, -1.0e-1,  "-0.10000" },
  { 4, 7, -1.0e-1,  "-0.1000" },
  { 3, 6, -1.0e-1,  "-0.100" },
  { 2, 5, -1.0e-1,  "-0.10" },
  { 1, 4, -1.0e-1,  "-0.1" },

  { 15, 28, -1.0e10, "-10000000000.000000000000000" },
  { 15, 18, -1.0e-10, "-0.000000000100000" },

  { 15, 17, 0.1, "0.100000000000000" },
  { 15, 17, 0.01, "0.010000000000000" },
  { 15, 17, 0.001, "0.001000000000000" },
  { 15, 17, 0.0001, "0.000100000000000" },
  { 15, 17, 0.00001, "0.000010000000000" },
  { 15, 17, 0.000001, "0.000001000000000" },
  { 15, 17, 0.0000001, "0.000000100000000" },
  { 15, 17, 0.00000001, "0.000000010000000" },
  { 15, 17, 0.000000001, "0.000000001000000" },
  { 15, 17, 0.0000000001, "0.000000000100000" },
  { 15, 18, 0.00000000001, "0.0000000000099910" },
  { 15, 18, 0.000000000001, "0.0000000000009910" },
  { 15, 18, 0.0000000000001, "0.0000000000000910" },
  { 15, 21, 0.00000000000001, "9.999999999999998e-15" },
  { 15, 21, 0.000000000000001, "1.000000000000001e-15" },

  { 15, 18, -0.1, "-0.100000000000000" },
  { 15, 18, -0.01, "-0.010000000000000" },
  { 15, 18, -0.001, "-0.001000000000000" },
  { 15, 18, -0.0001, "-0.000100000000000" },
  { 15, 18, -0.00001, "-0.000010000000000" },
  { 15, 18, -0.000001, "-0.000001000000000" },
  { 15, 18, -0.0000001, "-0.000000100000000" },
  { 15, 18, -0.00000001, "-0.000000010000000" },
  { 15, 18, -0.000000001, "-0.000000001000000" },
  { 15, 18, -0.0000000001, "-0.000000000100000" },
  { 15, 19, -0.00000000001, "-0.0000000000099910" },
  { 15, 19, -0.000000000001, "-0.0000000000009910" },
  { 15, 19, -0.0000000000001, "-0.0000000000000910" },
  { 15, 22, -0.00000000000001, "-9.999999999999998e-15" },
  { 15, 22, -0.000000000000001, "-1.000000000000001e-15" },

  { 15, 18, 1.234567890, "1.2345678899999910" },
  { 15, 18, 12.34567890, "12.345678899999999" },
  { 15, 19, 123.4567890, "123.456789000000001" },
  { 15, 20, 1234.567890, "1234.567890000000034" },
  { 15, 21, 12345.67890, "12345.678900000000795" },
  { 15, 22, 123456.7890, "123456.789000000004307" },
  { 15, 23, 1234567.890, "1234567.889999999897555" },
  { 15, 24, 12345678.90, "12345678.900000000372529" },
  { 15, 25, 123456789.0, "123456789.000000000000000" },

  { 15, 19, -1.234567890, "-1.2345678899999910" },
  { 15, 19, -12.34567890, "-12.345678899999999" },
  { 15, 20, -123.4567890, "-123.456789000000001" },
  { 15, 21, -1234.567890, "-1234.567890000000034" },
  { 15, 22, -12345.67890, "-12345.678900000000795" },
  { 15, 23, -123456.7890, "-123456.789000000004307" },
  { 15, 24, -1234567.890, "-1234567.889999999897555" },
  { 15, 25, -12345678.90, "-12345678.900000000372529" },
  { 15, 26, -123456789.0, "-123456789.000000000000000" },
};

int main(void)
{
  char cnum[FMT_DOUBLE];
  unsigned int ind;
  unsigned int len;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct fmt_test); ++ind) {
    len = fmt_double(cnum, tests[ind].num, tests[ind].sig);
    cnum[len] = 0;
    if (len != tests[ind].len) {
      printf("[%u] fail: len %u != %u %s %s\n", ind, len, tests[ind].len, cnum, tests[ind].str);
      return 1;
    }
    len = fmt_double(FMT_LEN, tests[ind].num, tests[ind].sig);
    if (len != tests[ind].len) {
      printf("[%u] fail: FMT_LEN len %u != %u\n", ind, len, tests[ind].len);
      return 1;
    }
    if (!str_same(cnum, tests[ind].str)) {
      printf("[%u] fail: %s != %s\n", ind, cnum, tests[ind].str);
      return 1;
    }
    printf("[%u] pass: %s == %s\n", ind, tests[ind].str, cnum);
  }

  return 0;
}