#include <bits/stdc++.h>
using namespace std;
class Student {
public:
  int id;
  int age;
  string name;
  int nos;
  float *gpa;
  // construtor // can be installed by default by compiler
  // Student(){
  //     cout << "----student default ctor is called" << endl;
  // }
  // parameterized constructor
  Student(int id, int age, string name, int nos, float gpa) {
    cout << "----student parameterized ctor is called " << "for" << this->name
         << endl;
    this->id = id;
    this->age = age;
    this->name = name;
    this->nos = nos;
    this->gpa = new float(gpa);
  }
  // ------ Parameterized copy constructor
  Student(const Student &srcobj) {
    cout << "----student copy ctor is called " << "for" << this->name << endl;
    this->id = srcobj.id;
    this->age = srcobj.age;
    this->name = srcobj.name;
    this->nos = srcobj.nos;
    // yaha pe humne sari values uthake new object mei daal that is srcobj
  }
  void sleep() { cout << this->name << ": sleeping" << endl; }
  void study() { cout << this->name << ": studying" << endl; }
  void bunk() { cout << this->name << ": bunking" << endl; }
  ~Student() {
    cout << "----student default dtor is called" << endl;
    delete this->gpa;
  }
};
int main() {
  //-----Normal Method
  // Student A;
  // A.name = "Gulshan";
  // A.id = 1;
  // A.age = 23;
  // A.nos = 4;
  // A.study();
  // Student B;
  // B.name = "Rahul";
  // B.id = 2;
  // B.age = 24;
  // B.nos = 5;
  // B.bunk();
  //----- Parameterized method
  // Student C(3, 44, "guddu", 5);
  // Student D(5, 24, "mani", 6);
  // Student E(6, 34, "rani", 4);
  // C.study();
  // D.bunk();
  // E.sleep();
  // cout<<C.id<<" "<<C.name<<" "<<C.age<<endl;
  // Student F=C;
  // cout<<F.id<<" "<<F.name<<" "<<F.age<<endl;
  // --------Dynamic memory allocation
  Student *G = new Student(8, 69, "dynamic memory", 6, 9.1);
  cout << G->id << endl;
  cout << G->name << endl;
  cout << G->age << endl;
  cout << *(G->gpa) << endl;
  delete G; // manaully deleting memory
  return 0;
}