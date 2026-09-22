#include <iostream>
using namespace std;

class Student {
public:
  int id;
  int age;
  string name;
  int nos;

private:
  float *gpa;
  string gf;

public:
  Student(int id, int age, string name, float gpa, string gf) {
    cout << "constructor has been called";
    this->id = id;
    this->age = age;
    this->name = name;
    this->gpa = new float(gpa);
    this->gf = gf;
    cout << endl;
  }
  // getters and setters
  // for gpa
  void setGpa(float m){
    *this->gpa=m;
  }
  float getGpa(){
    return *this->gpa;
  }
  //for age
  void setAge(int age){
    this->age=age;
  }
  int getAge(){
    return this->age; // this matlb jo bhi object call kr rha hai usika age return kro kisi aur ka nahi 
  }
  void sleeps() { cout << this->name << " is sleeping" << endl; }
  void bunk() { cout << this->name << " is bunking" << endl; }
  void study() { cout << this->name << " is studying" << endl; }
  ~Student() {
    cout << "destructor has been called ";
    cout << endl;
  }

private:
  void gfChatting() { cout << "chatting with gf"; }
};
int main() {
  Student A(1, 13, "mani", 9.1, "nupur ");
  cout << A.id << endl;
  // cout<<A.gf<<endl;
  A.bunk();
  A.setGpa(8.9);
  cout<<"age->"<<A.getAge()<<endl;
  cout<<A.getGpa()<<endl;
  return 0;
}