//
// Created by Jianyu Zuo on 12/13/17.
//


#include "Chapter04.h"
#include "Stack.h"
#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {
  ifstream in("Chapter02.h");
  Stack textlines;
  textlines.initialize();
  string line;
  // Read file and store lines in the Stack:
  while(getline(in, line)) {
    textlines.push(new string(line));
    cout << *((string*)(textlines.peek())) << endl;
  }
  cout << "Stack size: " << textlines.size() << endl;
  // Pop the lines from the Stack and print them:
  string* s;
  while((s = (string*)textlines.pop()) != nullptr) {
    cout << *s << endl;
    // this s deletion is only wrp. to the above new string(line) statement
    delete s;
  }
  textlines.cleanup();
}




