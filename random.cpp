// Class - companyName: string, modelName: string, fuelType: string,
// mileage: float, price: double;
// Functions - setData, displayData

#include <iostream>
using namespace std;

class Car {
 private:
  string companyName;
  string modelName;
  string fuelType;
  float mileage;
  double price;

 public:
  Car(string companyNameInput, string modelNameInput, string fuelTypeInput,
      float mileageInput, double priceInput) {
    companyName = companyNameInput;
    modelName = modelNameInput;
    fuelType = fuelTypeInput;
    mileage = mileageInput;
    price = priceInput;
  };

  Car() {
    companyName = "";
    modelName = "";
    fuelType = "";
    mileage = 0.0;
    price = 0.0;
  };

  void setData(string companyNameInput, string modelNameInput,
               string fuelTypeInput, float mileageInput, double priceInput) {
    companyName = companyNameInput;
    modelName = modelNameInput;
    fuelType = fuelTypeInput;
    mileage = mileageInput;
    price = priceInput;
  };

  void displayData() { cout << ""; }
};

int main() {
  Car car;
  return 1;
}