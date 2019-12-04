// See LICENSE for license details.

#ifndef _RISCV_ARITH_H
#define _RISCV_ARITH_H

#include <cstdint>
#include <climits>
#include <cmath>

inline uint64_t mulhu(uint64_t a, uint64_t b)
{
  uint64_t t;
  uint32_t y1, y2, y3;
  uint64_t a0 = (uint32_t)a, a1 = a >> 32;
  uint64_t b0 = (uint32_t)b, b1 = b >> 32;

  t = a1*b0 + ((a0*b0) >> 32);
  y1 = t;
  y2 = t >> 32;

  t = a0*b1 + y1;
  y1 = t;

  t = a1*b1 + y2 + (t >> 32);
  y2 = t;
  y3 = t >> 32;

  return ((uint64_t)y3 << 32) | y2;
}

inline int64_t mulh(int64_t a, int64_t b)
{
  int negate = (a < 0) != (b < 0);
  uint64_t res = mulhu(a < 0 ? -a : a, b < 0 ? -b : b);
  return negate ? ~res + (a * b == 0) : res;
}

inline int64_t mulhsu(int64_t a, uint64_t b)
{
  int negate = a < 0;
  uint64_t res = mulhu(a < 0 ? -a : a, b);
  return negate ? ~res + (a * b == 0) : res;
}

//ref:  https://locklessinc.com/articles/sat_arithmetic/
template<typename T, typename UT>
static inline T sat_add(T x, T y, bool &sat)
{
  UT ux = x;
  UT uy = y;
  UT res = ux + uy;
  sat = false;
  int sh = sizeof(T) * 8 - 1;

  /* Calculate overflowed result. (Don't change the sign bit of ux) */
  ux = (ux >> sh) + (((UT)0x1 << sh) - 1);

  /* Force compiler to use cmovns instruction */
  if ((T) ((ux ^ uy) | ~(uy ^ res)) >= 0) {
    res = ux;
    sat = true;
  }

  return res;
}

template<typename T, typename UT>
static inline T sat_sub(T x, T y, bool &sat)
{
  UT ux = x;
  UT uy = y;
  UT res = ux - uy;
  sat = false;
  int sh = sizeof(T) * 8 - 1;

  /* Calculate overflowed result. (Don't change the sign bit of ux) */
  ux = (ux >> sh) + (((UT)0x1 << sh) - 1);

  /* Force compiler to use cmovns instruction */
  if ((T) ((ux ^ uy) & (ux ^ res)) < 0) {
    res = ux;
    sat = true;
  }

  return res;
}

template<typename T>
T sat_addu(T x, T y, bool &sat)
{
  T res = x + y;
  sat = false;

  sat = res < x;
  res |= -(res < x);

  return res;
}

template<typename T>
T sat_subu(T x, T y, bool &sat)
{
  T res = x - y;
  sat = false;

  sat = !(res <= x);
  res &= -(res <= x);

  return res;
}

inline void Bool2Arith( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1 );
inline void Arith2Bool( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1 );
  
inline void  BoolMask  ( uint32_t* r_0, uint32_t* r_1, uint32_t x                 );
inline void  BoolUnmask( uint32_t* r,                  uint32_t x_0, uint32_t x_1 );
inline void  BoolRemask( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1 );
  
inline void  BoolNOT( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1                             );
inline void  BoolAND( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 );
inline void  BoolIOR( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 );
inline void  BoolXOR( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 );

inline void  BoolLSH( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, int i );
inline void  BoolRSH( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, int i );

inline void  BoolAdd( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 );
inline void  BoolSub( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 );
  
inline void ArithMask  ( uint32_t* r_0, uint32_t* r_1, uint32_t x                 );
inline void ArithUnmask( uint32_t* r,                  uint32_t x_0, uint32_t x_1 );
inline void ArithRemask( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1 );

inline void Bool2Arith( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1 ) {
  uint32_t x; 

  BoolUnmask( &x, x_0, x_1 ); ArithMask( r_0, r_1, x );
}

inline void Arith2Bool( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1 ) {
  uint32_t x; 

  ArithUnmask( &x, x_0, x_1 ); BoolMask( r_0, r_1, x );
}

inline void  BoolMask  ( uint32_t* r_0, uint32_t* r_1, uint32_t x                 ) {
  uint32_t m = rand(); 

  *r_0 = ( x   ^ m   ); 
  *r_1 = (       m   );
}

inline void  BoolUnmask( uint32_t* r,                  uint32_t x_0, uint32_t x_1 ) {
  *r   = ( x_0 ^ x_1 );
}

inline void  BoolRemask( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1 ) {
  uint32_t m = rand(); 

  *r_0 = ( x_0 ^ m   ); 
  *r_1 = ( x_1 ^ m   );
}

inline void  BoolNOT( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1                       ) {
  *r_0 =  ( x_0 );
  *r_1 = ~( x_1 ); 
}

inline void  BoolAND( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 ) {
  *r_0 = ( x_0 & y_1 ) ^ ( x_0 | ~y_0 );
  *r_1 = ( x_1 & y_1 ) ^ ( x_1 | ~y_0 );
}

inline void  BoolIOR( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 ) {
  *r_0 = ( x_0 | y_1 ) ^ ( x_0 &  y_0 );
  *r_1 = ( x_1 & y_1 ) ^ ( x_1 |  y_0 );
}

inline void  BoolXOR( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 ) {
  *r_0 = ( x_0 ^ ( x_1 ^ y_0 ) );
  *r_1 = (       (       y_1 ) );
}

inline void  BoolLSH( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, int i ) {
  uint32_t m = rand();

  *r_0 = ( x_0 << i ) ^ ( ( x_1 << i ) ^ m );
  *r_1 =                (                m );

}

inline void  BoolRSH( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, int i ) {
  uint32_t m = rand();

  *r_0 = ( x_0 >> i ) ^ ( ( x_1 >> i ) ^ m );
  *r_1 =                (                m );
}

inline void  BoolAdd( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 ) {
  uint32_t z_0, z_1, p_0, p_1, g_0, g_1, h_0, h_1, u_0, u_1;

    BoolXOR( &p_0, &p_1, y_0, y_1, x_0, x_1 );
    BoolAND( &g_0, &g_1, x_0, x_1, y_0, y_1 );

  int n = ( int )( fmax( 1, ceil( log2( 8 * sizeof( uint32_t ) - 1 ) ) ) );

  for( int i = 1; i <= ( n - 1 ); i++ ) {
    BoolLSH( &h_0, &h_1, g_0, g_1, 1 << ( i - 1 ) );
    BoolAND( &u_0, &u_1, p_0, p_1, h_0, h_1 );
    BoolXOR( &g_0, &g_1, g_0, g_1, u_0, u_1 );

    BoolLSH( &h_0, &h_1, p_0, p_1, 1 << ( i - 1 ) );
    BoolAND( &p_0, &p_1, p_0, p_1, h_0, h_1 );
  }

    BoolLSH( &h_0, &h_1, g_0, g_1, 1 << ( n - 1 ) );
    BoolAND( &u_0, &u_1, p_0, p_1, h_0, h_1 );
    BoolXOR( &g_0, &g_1, g_0, g_1, u_0, u_1 );

    BoolLSH( &h_0, &h_1, g_0, g_1, 1        );
    BoolXOR( &z_0, &z_1, y_0, y_1, x_0, x_1 );
    BoolXOR( &z_0, &z_1, z_0, z_1, h_0, h_1 );

  *r_0 = z_0;
  *r_1 = z_1;
}

inline void  BoolSub( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1, uint32_t y_0, uint32_t y_1 ) {
  uint32_t z_0, z_1, p_0, p_1, g_0, g_1, h_0, h_1, u_0, u_1, m;

    BoolNOT( &y_0, &y_1, y_0, y_1           );
    BoolXOR( &p_0, &p_1, y_0, y_1, x_0, x_1 );
    BoolAND( &g_0, &g_1, x_0, x_1, y_0, y_1 );
    BoolAND( &u_0, &u_1, p_0, p_1,   1,   0 );
    BoolXOR( &g_0, &g_1, g_0, g_1, u_0, u_1 );

  int n = ( int )( fmax( 1, ceil( log2( 8 * sizeof( uint32_t ) - 1 ) ) ) );

  for( int i = 1; i <= ( n - 1 ); i++ ) {
    BoolLSH( &h_0, &h_1, g_0, g_1, 1 << ( i - 1 ) );
    BoolAND( &u_0, &u_1, p_0, p_1, h_0, h_1 );
    BoolIOR( &g_0, &g_1, g_0, g_1, u_0, u_1 );

    BoolLSH( &h_0, &h_1, p_0, p_1, 1 << ( i - 1 ) );
    BoolAND( &p_0, &p_1, p_0, p_1, h_0, h_1 );
  }

    BoolLSH( &h_0, &h_1, g_0, g_1, 1 << ( n - 1 ) );
    BoolAND( &u_0, &u_1, p_0, p_1, h_0, h_1 );
    BoolIOR( &g_0, &g_1, g_0, g_1, u_0, u_1 );
    BoolLSH( &h_0, &h_1, g_0, g_1, 1        );
    BoolXOR( &z_0, &z_1, y_0, y_1, x_0, x_1 );
    BoolXOR( &z_0, &z_1, z_0, z_1, h_0, h_1 );
    BoolXOR( &z_0, &z_1, z_0, z_1,   1,   0 );

  *r_0 = z_0;
  *r_1 = z_1;
}

inline void ArithMask  ( uint32_t* r_0, uint32_t* r_1, uint32_t x                 ) {
  uint32_t m = rand(); 

  *r_0 = ( x   + m   ); 
  *r_1 = (       m   );
}

inline void ArithUnmask( uint32_t* r,                  uint32_t x_0, uint32_t x_1 ) {
  *r   = ( x_0 - x_1 );
}

inline void ArithRemask( uint32_t* r_0, uint32_t* r_1, uint32_t x_0, uint32_t x_1 ) {
  uint32_t m = rand(); 

  *r_0 = ( x_0 + m   ); 
  *r_1 = ( x_1 + m   );
}

#endif
