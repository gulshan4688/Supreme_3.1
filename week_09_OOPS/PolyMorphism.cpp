#include <iostream>
using namespace std;
class Complex {
public:
  int real, imag;
  bool isR,isI;
  Complex() { real = imag = -1; }
  Complex(int r, int i) : real(r), imag(i) {};
  void print() { cout << "[ " << real << " + i" << imag << " ]" << endl; }
  Complex operator+(const Complex B) {
    Complex temp;
    temp.real = this->real + B.real;
    temp.imag = this->imag + B.imag;
    return temp;
  }
  Complex operator-(const Complex B) {
    Complex temp;
    temp.real = this->real - B.real;
    temp.imag = this->imag - B.imag;
    return temp;
  }
  bool operator==(const Complex B) {
    return (this->real==B.real) && (this->imag==B.imag);
  }
};
int main() {
  Complex A(4, 2);
  A.print();
  Complex B(4, 2 );
  B.print();
//   Complex C = A + B;
//   Complex C = A - B;
  bool a = A == B;
  cout<<a<<endl;
  return 0;
}