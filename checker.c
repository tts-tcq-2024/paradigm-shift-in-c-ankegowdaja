#include <stdio.h>
#include <assert.h>

// Function to check if a value is within a specified range
int range_checking(float value, float lower_value, float upper_value) 
{
  return (value >= lower_value && value <= upper_value);
}

//function to check if battery parameters are okay
int batteryIsOk(float temperature, float soc, float chargeRate)
{
  int tempInRange = range_checking(temperature, 0, 45);
  int socInRange = range_checking(soc, 20, 80);
  int chargeRateInRange = (chargeRate <= 0.8);

  if (!tempInRange)
  {
    printf("Temperature out of range!\n");
  }
  if (!socInRange) 
  {
    printf("State of Charge out of range!\n");
  }
  if (!chargeRateInRange) 
  {
    printf("Charge Rate out of range!\n");
  }
  
 if(tempInRange && socInRange && chargeRateInRange)
 {
     printf("battery is ok \n");
 }
  printf("\n");
  return tempInRange && socInRange && chargeRateInRange;
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(50, 85, 1.3));
}
