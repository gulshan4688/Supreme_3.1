#include <iostream>
using namespace std;
class Vehicles {
private:
  string bhp;

public:
  string name;
  string model;
  int noOfTyres;

public:
  Vehicles(string name, string model, int noOfTyres) {
    this->name = name;
    this->model = model;
    this->noOfTyres = noOfTyres;
    cout << "Vehicles constructor has been called" << endl;
  }
  string getBhp() {
    this->bhp = "200";
    return this->bhp;
  }
  void startEngine() {
    cout << "Engine has started, name: " << this->name
         << " Model: " << this->model << endl;
  }
  void stopEngine() {
    cout << "Engine has stopped, name: " << this->name
         << " Model: " << this->model << endl;
  }
  // destructor
  ~Vehicles() { cout << "Vehicles destuctor called " << endl; }
};
class Car : public Vehicles {
protected:
  int noOfDoors;
  string transmissionType;

public:
  Car(string name, string model, int noOfTyres, int noOfDoors,
      string transmissionType)
      : Vehicles(name, model, noOfTyres) {
    this->noOfDoors = noOfDoors;
    this->transmissionType = transmissionType;
    cout << "Car constructor has been called" << endl;
  }
  void startAC() { cout << "AC has started of " << this->name << endl; }
  ~Car() { cout << "Car destuctor called " << endl; }
};
class MotorCycle : public Vehicles {
protected:
  string handleBarStyle;
  string suspensionStyle;

public:
  MotorCycle(string name, string model, int noOftyres, string handleBarStyle,
             string suspension)
      : Vehicles(name, model, noOfTyres) {
    this->handleBarStyle = handleBarStyle;
    this->suspensionStyle = suspensionStyle;
    cout << "Motorcycle constructor called" << endl;
  }
  void Wheelie() { cout << "wheiles is performed by: " << name << endl; }
};
int main() {
  // Car A("NameA", "ModelA", 4, 4, "auto");
  // cout << A.name << " " << A.model << " " << A.noOfTyres;
  // cout << endl << "bhp: " << A.getBhp() << endl;
  MotorCycle M("nameM", "modelM", 4, "cruise", "air");
  cout << "name: " << M.name << " " << "model: " << M.model << endl;
  M.Wheelie();
  return 0;
}