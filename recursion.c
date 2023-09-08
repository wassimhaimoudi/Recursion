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
  return 0;
}