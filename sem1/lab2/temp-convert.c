#include <stdio.h>

int main()
{
  float tempInFahrenheit, tempInCelsius;

  // Get the input
  printf("Enter temperature in Fahrenheit: ");

  // NOTE FOR SELF: Never use \n in `scanf
  scanf("%f", &tempInFahrenheit);

  // Calculate
  tempInCelsius = (5.0 / 9) * (tempInFahrenheit - 32);

  printf("Temperature in Celsius: %f \n", tempInCelsius);

  return 0;
}