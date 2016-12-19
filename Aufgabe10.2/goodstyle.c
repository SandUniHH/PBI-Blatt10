// Bocher Diedrich Sandmeier

#include <stdlib.h>
#include <stdio.h>

/* Returns the user input, an integer */
static int number_input()
{
  int input;
  
  if(scanf("%d",&input) != 1 || input <= 0) 
  {
    fprintf(stderr,"Wrong input!\n");
    return EXIT_FAILURE;
  }
  
  return(input);
}

/* Calculate the exponential using the two numbers the user has put in */
static int calculate_exponential(base, exponent)
{
  int i, result = base;
  
  for(i = 1; i < exponent; i++)
  {
    result *= base;
  }
  
  return(result);
}

int main ()
{
  int base, exponent, result;

  printf("Input base:\n");
  base = number_input();
  printf("Input exponent:\n");
  exponent = number_input();
  result = calculate_exponential(base, exponent);
  
  printf("The result is: %d\n", result);
  
  return(EXIT_SUCCESS);
}
