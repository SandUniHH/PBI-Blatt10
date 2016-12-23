// Bocher Diedrich Sandmeier

#include <stdlib.h>
#include <stdio.h>
#include <limits.h> // for the the max value of an unsigned long ULONG_MAX

/* checks the argv element if it is a valid unsigned long */
void check_input(unsigned long array_element)
{
  if(array_element < 0 || array_element > ULONG_MAX)
    {
      fprintf(stderr,"Wrong input!\n");
      exit(EXIT_FAILURE);
    }    
}

/* calculates the checksum of the input number */
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
    char *unneeded_pointer;

    // convert the argv element to an unsigned long
    value = strtoul(argv[i], &unneeded_pointer, 10);

    check_input(value); // exit program if wrong value in array
    qsum = quersumme(value);
    printf("%lu\t%lu\n", value, qsum);    
  }
  
  return (EXIT_SUCCESS);
}