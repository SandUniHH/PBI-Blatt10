// Bocher Diedrich Sandmeier

#include <stdlib.h>
#include <stdio.h>
#include <limits.h> // for the the max value of an unsigned long ULONG_MAX

static int check_input(array_element)
{
  if(array_element < 0 || array_element > ULONG_MAX)
    {
      fprintf(stderr,"Wrong input!\n");
      return EXIT_FAILURE;
    }    
}

unsigned long quersumme(unsigned long value)
{
  unsigned long result = 0;
  
  while (value > 0)
  {
    result += value % 10;
    value = value / 10;
  }
 
  return result;
}

int main(int argc, char* argv[])
{
  int i;
  unsigned long value;  
  
  for(i = 1; i < argc; i++)
  {
    unsigned long qsum;
    char *endptr;
    
    value = strtoul(argv[i], &endptr, 10);
    check_input(value); // exits program if wrong value in array
    qsum = quersumme(value);
    printf("%lu\t%lu\n", value, qsum);    
  }
  
  return (EXIT_SUCCESS);
}