/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x|~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return  ~(x&y)&~(~x&~y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    int x_sig,y_sig;
    x_sig=x>>31;
    y_sig=y>>31;
    if (!x){
        if(!y){
            return 1;
        }
        return 0;
    }
    if(!y){
        return 0;
    }
    return !(x_sig ^ y_sig);

    // return !(x_sig ^ y_sig) && !(!x ^!y)

}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int step1=v>>16;
    int judge1=(step1>0);
    int cnt1=judge1<<4;
    v=v>>cnt1;

    int step2=v>>8;
    int judge2=(step2>0);
    int cnt2=judge2<<3;
    v=v>>cnt2;

    int step3=v>>4;
    int judge3=(step3>0);
    int cnt3=judge3<<2;
    v=v>>(cnt3);

    int step4=v>>2;
    int judge4=(step4>0);
    int cnt4=judge4<<1;
    v=v>>(cnt4);

    int step5=v>>1;
    int judge5=(step5>0);
    int cnt5=judge5;
    // v=v>>judge5;

    return cnt1 | cnt2 |cnt3 |cnt4| cnt5;

}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int st_n=n<<3; //n*8
    int st_m=m<<3;
    int byte_n=(x>>st_n)&0xFF;
    int byte_m=(x>>st_m)&0xFF;
    int mask=(255<<st_n) | (255<<st_m);    
    int x_sol=(x & ~mask);
    // int dif= byte_m ^ byte_n;
    // int ans=x ^ (dif << st_n) ^(dif<<st_m);

    int ans=x_sol | (byte_n<<st_m)|(byte_m<<st_n);    
    return ans;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned mark=31;
    unsigned res=0;
    while(mark){
        res+=(1 & v) << mark;
        mark=mark-1;
        v=v>>1; 
    }
    res+=v;
    return res;

}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int temp=x>>n;
    // int mask=(1<<(32+(~n+1)))-1;
    int mask=~((1<<31)>>n<<1);
    return temp & mask;

}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    x=~x;
    int judge1=!(x>>16);
    int cnt1=judge1<<4;
    x=x>>((!judge1)<<4) ;

    int judge2=!(x>>8);
    int cnt2=judge2<<3;
    x=x>>((!judge2)<<3);
    
    int judge3=!(x>>4);
    int cnt3=judge3<<2;
    x=x>>((!judge3)<<2);

    int judge4=!(x>>2);
    int cnt4=judge4<<1;
    x=x>>((!judge4)<<1);

    int judge5=!(x>>1);
    int cnt5=judge5;
    x=x>>((!judge5));

    int judge6=!x;
    int cnt6=judge6;


    return (cnt1 | cnt2 | cnt3 |cnt4 |cnt5 )+cnt6 ;


}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    //Note: LSB(Least Significant Bit)|guard|sticky
    if (x==0){
        return 0;
    }
    if(x==0x80000000){
        return 0xCF000000;
    }

    unsigned res=0;
    unsigned absx;

    if (x < 0){
        res=0x80000000;
        absx=~x+1;
    }
    else{
        absx=x;
    }


    int mark=0;

    for(unsigned i=0x40000000;!(i&absx);i=i>>1){
        mark=mark+1;
    }

    unsigned pow=30-mark;
    unsigned bias=127;

    res+=((pow+bias)<<23);
    unsigned mask=(1<<pow)-1;
    unsigned cover=mask & absx;
    unsigned temp1=pow-24;
    // unsigned temp2=pow-25;
    unsigned add;
    unsigned dump,add2,add3;
    if (pow<24){
        add=(cover<<(23-pow));
    }else{
        dump=cover&((1<<temp1)-1);
        add2=cover>>temp1;
        // add=add2;
        if(add2 & 1){
            add2=add2>>1;
            add3=add2+1;
            if(dump){      
                add2=add3;
            }else{
                if(add2 & 1){
                    add2=add3;
                }
            }
        }else{
            add2=add2>>1;
        }
        add=add2;
    }

    return res+add;

    


}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned exp=uf &0x7F800000;
    unsigned M=0x007FFFFF & uf;
    unsigned sig=0x80000000 & uf;
    if (exp>0x7F000000){
        return uf;
    }else if(exp>0){
        if(exp==0x7F000000){
            M=0;
        }
        exp=exp+0x00800000;
    }else{
        M=M<<1;
    }
    return sig | exp | M;

}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sig=0x80000000 & uf2;
    unsigned M1=(0x000FFFFF &uf2) | 0x00100000;
    unsigned M2 =uf1; 
    int exp=(0x7FF00000 & uf2)>>20;
    int pow=exp-1023;
    unsigned abs;
    int cnt1=(52-pow);
    if(pow<0){
        return 0;
    
    }else if(pow<31){
        if(pow<=20){
            abs=M1>>(20-pow);
        }else{
            abs=(M1<<(pow-20)) | (M2>>cnt1);
        }
    }else{
        return 0x80000000;
    }
    // unsigned temp;
    int res;
    if(sig){
        res=-abs;
    }else{
        res=abs;
    }
    return res;

}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if(x>127){
        return 0x7F800000;
    }
    unsigned exp=0,M=0;
    if(x>-127){
        exp=x+127;
        exp=exp<<23;
        return exp;
    }else if(x>=-149){
        M=1<<(149+x);
        return M;
    }else{
        return 0;
    }
    

}
