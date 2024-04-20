#ifndef FIXED_POINT_H
#define FIXED_POINT_H
#define F (1 << 14) //fixed point 1
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1 << 31))
// x and y denote fixed_point numbers in 17.14 format
// n is an integer
 
int int_to_fp(int n); /* Convert integer to fixed point */
int fp_to_int_round(int x); /* Convert FP to int (rounding) */
int fp_to_int(int x); /* Convert FP to int (discard) */
int add_fp(int x, int y); /* Addition of FP */
int add_mixed(int x, int n); /* Addition of FP and int */
int sub_fp(int x, int y); /* Subtraction of FP (x-y) */
int sub_mixed(int x, int n); /* Subtraction of FP and int (x-n) */
int mult_fp(int x, int y); /* Multiplication of FP */
int mult_mixed(int x, int y); /* Multiplication of FP and int */
int div_fp(int x, int y); /* Division of FP (x/y) */
int div_mixed(int x, int n); /* FP and int division (x/n) */

int int_to_fp(int n){
  int temp= n * F;
  return temp;
}
/* Convert integer to fixed point */

int fp_to_int_round(int x){
  if(x>=0){
    return (x + F / 2 ) / F;
  }
  else{
    return (x - F / 2 ) / F;
  }
}
/* Convert FP to int (rounding) */

int fp_to_int(int x){
  return x/F;
}
/* Convert FP to int (discard) */

int add_fp(int x, int y){
  return x+y;
}
/* Addition of FP */

int add_mixed(int x, int n){
  return x+int_to_fp(n);
}
/* Addition of FP and int */

int sub_fp(int x, int y){
  return x-y;
}
/* Subtraction of FP (x-y) */

int sub_mixed(int x, int n){
  return x-int_to_fp(n);
}
/* Subtraction of FP and int (x-n) */

int mult_fp(int x, int y){
  return (((int64_t)x) * y / F);
}
/* Multiplication of FP */

int mult_mixed(int x, int n){
  return x*n;
}
/* Multiplication of FP and int */


int div_fp(int x, int y){
  return ((int64_t) x) * F / y;
}
/* Division of FP (x/y) */

int div_mixed(int x, int n){
  return x/n;
}
#endif
