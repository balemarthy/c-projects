#include <stdio.h>
/* print Fahrenheit-Celsius table */
main()
{
    int fahr;
  
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)  // Fahrenheit to Celsius conversion using for loop
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
