int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int bitXor(int x, int y) {
    return ~(x & y) & ~(~x & ~y); 
}

int sign(int x) {
    int signBit = x >> 31;
    return (!!x) | signBit;
}

int getByte(int x, int n){
    int bytePos = n << 3;
    int mask = 255;
    return (x >> bytePos) & mask;
}

int logicalShift(int x,int n){
    int mask = ~(((1 << 31) >> n) >> 1);
    return (x >> n) & mask;
}

int conditional(int x,int y,int z){
    int temp = (x >> 31) | ((~x + 1) >> 31);
    return ((temp & y) + (~temp & z));
}

int bang(int x) {
    int res = (((~x + 1) | x) >> 31);
    return res + 1;
}

int invert(int x, int p, int n) {
    int mask = ((1 << n) - 1) << p;
    return x ^ mask;
}
