#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    getline(cin,input);
    stringstream ss(input);
    int num;
    char c;
     while (ss >> c) { // Read one character at a time
        if (isdigit(c)) { 
            ss.unget(); // Put the digit back into the stream
            ss >> num;  // Extract full number
            cout << num << " ";
        }
    }
    return 0;
}