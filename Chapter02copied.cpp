//
// Created by Jianyu Zuo on 12/12/17.
//

// "" headers are locally defined headers
// <> headers are pre-defined headers in system
// <> header without .h extension is better for portability of codes
//    usually <> header should not use both with and without .h extension versions
#include "Chapter02.h"
#include "Chap2testExtern.h"
#include <cstdlib>
#include <iostream> // Stream for standard I/O operations
#include <fstream>  // Stream for file operations
#include <vector>   // vector container

// namespace mechanism: wraps set of libraries and variables [names] into a namespace. More at Chap10
//                      include <iostream.h> <=> include<iostream> using namespace std;
using namespace std;

int func1(int a, int b) {
  return a/b;
}
int func1_explicit(int a, int b) {
  return a/b;
}
int func2() {
  return static_cast<int>(random());
}

int main() {

  // C++ uses static type checking

  cout << "Hello, World! I am "
         << func1(32,4)+ func1_explicit(32, 4) << " Today!" << endl;
  cout << "Output of func2 " << func2() << endl;
  // if 'testExtern.h' file is not included, then the following will have runtime error
  cout << testExtern << endl;

  // TODO: These codes will change the base to hex, which will influence later functions. Require changes
//  cout << "Number 15 in decimal: "
//  << dec << 15 << endl;
//  cout << "in octal: " << oct << 15 << endl;
//  cout << "in hex: " << hex << 15 << endl;

  cout << "a floating-point number: "
       << 3.14159 << endl;
  cout << "non-printing char (escape): "
       << char(27) << endl;

  // About file streams ifstream ofstream
  ifstream in("Chapter02.cpp"); // Open for reading
  ofstream out("Chapter02copied.cpp"); // Open for writing
  string s;
  while(getline(in, s)) // Discards newline char
    out << s << "\n"; // ... must add it back

  // Another way is to hold all the file content in a container
  vector<string> v;
  ifstream in2("Chapter02.h");
  string line;
  while(getline(in2, line))
    v.push_back(line); // Add the line to the end

  cout << "Total elements in vector: " << v.size() << endl;
  for(int i = 0; i < v.size(); i++)
    cout << i << ": " << v[i] << endl;
}
