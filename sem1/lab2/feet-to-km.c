#include <stdio.h>

int main()
{
  // Input vars
  float lengthInFeet;

  // 1 ft = 0.0003048 km
  float conversionValue = 0.0003048;

  float lengthInKMs;

  // Take input
  printf("Enter length in feet: ");
  scanf("%f", &lengthInFeet);

  lengthInKMs = lengthInFeet * conversionValue;

  printf("Length in KMs: %f \n", lengthInKMs);

  return 0;
}