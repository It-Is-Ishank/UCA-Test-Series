#include <string.h>

int base64encode(char *data, int length, char *result) {
  char base64chars[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  int resInd = 0;
  int x;
  int padCount = length % 3;
  int a, b, c, d;
  for (x = 0; x < length;) {
    int n = x < length ? data[x++] << 16 : 0;
    n += x < length ? data[x++] << 8 : 0;
    n += x < length ? data[x++] : 0;
    a = (n >> 18) & 63;
    b = (n >> 12) & 63;
    c = (n >> 6) & 63;
    d = n & 63;

    result[resInd++] = base64chars[a];
    result[resInd++] = base64chars[b];
    result[resInd++] = base64chars[c];
    result[resInd++] = base64chars[d];
  }

  result[resInd] = 0;

  if (padCount > 0) {
    for (; padCount < 3; padCount++) {
      result[--resInd] = '=';
    }
  }
  return 0;
}

char *encode(char *input) {

  int size = strlen(input);
  int outSize = 4 * ((size + 2) / 3);
  char *res = malloc(outSize);
  base64encode(input, size, res);
  return res;
}
