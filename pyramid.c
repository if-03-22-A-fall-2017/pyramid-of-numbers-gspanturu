/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 * ---------------------------------------------------------
 * Title:			Pyramid of Numbers
 * Author:			Panturu Gloria Sara
 * ---------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#define MAX_DIGITS 80
struct BigInt
{
  int digits_count;
  unsigned int the_int[MAX_DIGITS];
};

int strtobig_int (const char* string, int length, struct BigInt* big_int);
void print_big_int(const struct BigInt* big_int);
void multiply( const struct BigInt * big_int, int factor, struct BigInt * big_result);
void divide(const struct BigInt * big_int, int divisor, struct BigInt *  big_result);
void copy_big_int(const struct BigInt * from, struct BigInt * to);

int main(int argc, char* argv[])
{
  char input[MAX_DIGITS+1];
  printf("Pyramid of Numbers\n" );
  printf("Please enter a number: " );
  scanf("%s",input);
  int length = strlen(input);

  struct BigInt big_int;
  struct BigInt big_result;
  strtobig_int(input, length, &big_int);
  print_big_int(&big_int);

   int count = 2;
  while (count <= 9) {
    multiply(&big_int, count, &big_result);
    print_big_int(&big_result);
    copy_big_int(&big_result, &big_int);
    count++;
  }
  while (count >=2) {
    divide(&big_int, count, &big_result);
    print_big_int(&big_result);
    copy_big_int(&big_result, &big_int);
    count--;
  }
  return 0;
}

void print_big_int (const struct BigInt *big_int)
{
  for (int i = big_int->digits_count; i >=0 ; i--) {
    printf("%d",big_int->the_int[i-1]);
  }
}
int strtobig_int(const char *string, int length, struct BigInt *big_int)
{
  int digits_count;
  for (int i = 0;i < length; i++)
  {
     if (string[i] >= '0' && string[i] <= '9')
      {
       big_int->the_int[length-i] = string[i]-'0';
       digits_count ++;
    }
    else{
      return i;
        }
  }
  return digits_count;
}

void multiply( const struct BigInt * big_int, int factor, struct BigInt * big_result)
{
  int product;
  int carry;
 for (int i = 0; i < big_int->digits_count ; i++)
 {
   product = big_int -> the_int[i] * factor;
   if (product > 9)
   {
     carry = product/10;
     big_result->the_int[i] = product % 10 + carry;
   }
   else
   {
     carry = product/10;
     big_result->the_int[i] = product + carry;
   }
 }
}

void divide(const struct BigInt * big_int, int divisor, struct BigInt *  big_result)
{
  int quotient;
  int rest;
  rest = 0;
  char number_to_divide;
 for (int i = big_int->digits_count; i >0; i--)
 {
   number_to_divide = big_int->the_int[i];

   while (number_to_divide < divisor && i == big_int->digits_count) {
     number_to_divide += big_int->the_int[i];
}
   if (i != big_int->digits_count ){
     rest = rest + (char)big_int->the_int[i];
   }
   quotient = number_to_divide / divisor;
   big_result ->the_int[i] = quotient;
   rest = number_to_divide % divisor;
  }
}

void copy_big_int(const struct BigInt * from, struct BigInt * to)
{
for (int i = 0; i < from -> digits_count; i++)
  {
  to->the_int[i] = from->the_int[i];
  }
  if (from->digits_count != to->digits_count) {
    to->digits_count = from->digits_count;
  }
}
