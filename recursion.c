#include <stdio.h>
#include <stdlib.h>
#define MAX 4
// printArray
void printArray(int *array, int n)
{
    static int i = 0;
    if (i < n)
    {
      printf("%d ", array[i]);
      i++;
      printArray(array, n);
    }
}

// count the number of digits in a given integer
int countDigit(int n)
{
    static int c = 0;
    if (n != 0)
    {
      c++;
      countDigit(n/10);
    }
    // n > 10
    return c;
}

// ex sum of digits

int sumDigits(int n)
{
  if (n < 9) {
    return n;
  }
  else {
    return sumDigits(n/10) + n%10;
  }
}

// find the GCD of 2 nums
int findGCD(int a, int b)
{
    if (b == 0)
    {
      return a;
    }
    else {
      return findGCD(b, a % b);
    }
}

// find LCM of 2 nums
int findLCM(int a, int b)
{
  int gcd = findGCD(a, b);
  int lmc = (a * b) / gcd;
  return lmc;
}

// calculate the power of n

int power(int base, int expon)
{
  if (expon == 0)
  {
    return 1;
  }
  if (expon == 1)
  {
    return base;
  }
  else {
    return base * power(base, expon - 1);
  }
}
/* iterating over all the numbers starting from i - 1 down the row with i > 0 */
int primeHelper(int n, int i)
{
  if (i == 1)
    return 1;
  else if (n % i == 0 && i > 0)
    return 0;
  
  return (primeHelper(n, i - 1));
}
/* checking if n is prime using the previous term n - 1 as an iterator */
int is_prime(int n)
{
  if (n <= 1)
    return 0;
  return primeHelper(n, n - 1);
}
/* prime chec using a for loop */
int is_prime2(int n)
{
  int i;
  
  if (n <= 1) return (0);
  
  for (i = n; i > 0;)
  {
    i--;
    if (i == 1)
      break;
    if (n % i == 0)
      return 0;
  }
  return 1;
}
int main()
{
/*
  int array[] = {2, 4, 6, 8};
  printf("The elements of the array are: ");
  printArray(array, MAX);

  int n = 133;
  printf("the number of digits of n: %d ", countDigit(n));

  int n = 123;
  printf("The sum of the digits in %d is: %d", n, sumDigits(n));
*/

  int a = 8, b = 3;
  printf("The GCD of %d and %d is %d\n", a, b, findGCD(a, b));
  printf("The LCM of %d and %d is %d\n", a, b, findLCM(a, b));
  printf("%d to the power of %d is %d", a, b, power(a, b));
  // prime test
  int r, p;
  // recursion test  
  r = is_prime(1);
  printf("%d\n", r);
  r = is_prime(11);
  printf("%d\n", r);
  // loop test  
  p = is_prime2(1);
  printf("%d\n", p);
  p = is_prime2(11);
  printf("%d\n", p);
  r = is_prime2(4);
  printf("%d\n", p);
  p = is_prime2(-1);
  printf("%d\n", p);
  p = is_prime2(0);
  printf("%d\n", p);
  p = is_prime2(17);
  printf("%d\n", p);
  return 0;
}
