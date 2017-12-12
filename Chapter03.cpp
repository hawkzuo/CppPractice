//
// Created by Jianyu Zuo on 12/12/17.
//

#include "Chapter03.h"

#include <iostream>


void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swapR(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void counter() {
  // This syntax is not allowed in Java
  // the declaration will only be executed once
  static int i = 0;
  i++;
  printf("i: %d\n",i);

}

int main(int argc, char* argv[]) {
  // General Idea 1: Use any type after explicit initialization


  // Data Types p130
  // 4 basic built-in types
  char  tp1;
  int   tp2;
  float tp3;
  double tp4;

  // boolean type
  bool shouldPrint = true;

  // 4 specifiers
  unsigned char sp1;
  signed int    sp2;
  long double   sp3;
  short int     sp4;  // int is optional in this case
  long int      sp5;

  // Memory Usage for each type
  std::cout
    << "\n char= " << sizeof(tp1)
    << "\n unsigned char = " << sizeof(sp1)
    << "\n int = " << sizeof(tp2)
    << "\n short = " << sizeof(sp4)
    << "\n long = " << sizeof(sp5)
    << "\n float = " << sizeof(tp3)
    << "\n double = " << sizeof(tp4)
    << "\n long double = " << sizeof(sp3)
    << std::endl;

  // &: used to get the memory address of given type
  std::cout
    << "main(): " << (long)&main << std::endl
    << "tp1:" << &tp1 << std::endl
    << "tp2:" << &tp2 << std::endl
    << "tp3:" << &tp3 << std::endl
    << "tp4:" << &tp4 << std::endl
    << "sp1:" << &sp1 << std::endl
    << "sp2:" << &sp2 << std::endl
    << "sp3:" << &sp3 << std::endl
    << "sp4:" << &sp4 << std::endl;

  // Pointer: like reference in Java, but not quite. Not same mechanism
  //          stores the address of given variable type
  //          cannot initialize more than 1 pointer at a time
  int a = 477;
  int* pta = &a;
  std::cout
    << "a:" << a << std::endl
    << "pta:" << pta << " pta value: "
    << *pta << std::endl;
  // pointer can be used to modify the variable it points to
  *pta = 100;
  std::cout
    << "Now a: " << a << std::endl
    << "pta:" << pta << " pta value: "
    << *pta << std::endl;
  // Why Pointer as a proxy of modifying data?
  // A: change "outside objects" from within a function
  // [due to pass-by-value technique]
  // [Java Reference can make same effect, but basic types are not applied]
  // B: Other Clever Techniques
  int left = 0;   int right = 10;
  swap(&left, &right);
  printf("left: %d, right: %d\n", left, right);
  // void pointer: no such void reference
  void* pVoid;
  pVoid = &left;
  printf("Any pointer void*: %p\n", pVoid);
  printf("void* cannot be dereferenced directly: %d\n", *(int*)pVoid);

  // Reference: Serves as an alias for the same variable. No complex works like pointer
  //            most of the tasks can be done by references can also be done via pointers
  swapR(left, right);
  printf("left: %d, right: %d\n", left, right);

  // static keyword:
  //      static existence inside a function;
  //      define file-scope variables [compared with extern]

  for(int x = 0; x < 10; x++)
    counter();

  // const/volatile keyword: Details later
  //

  // Operators, supports overloading
  // + - * /    > >= < <= == != && ||
  // << >> <<< >>> & ^ | &^|=
  // condition ? positive : negative;
  // static_cast<type> const_cast<type>: used only to remove "const" constraint
  // reinterpret_cast<type>;
  // sizeof operator: returns memory for data

  // typedef increases difficulty for readability but useful in structs as meaningfulness
  typedef unsigned long ulong;
  Node n1,n2;
  n1.next = &n2;
  n1.i = 1;
  n2.next = &n1;
  n2.i = 2;
  printf("Pause\n");

  // Arrays:  Initial values are random [unlike Java]
  int arr1[10]; int* arrptr1 = arr1;
  for(int i=0;i < 10; i++) {
    printf("%d\t", arr1[i]);
    printf("%d\t", arrptr1[i]);
  }
  printf("\nargv[0] is current path by default: %s", argv[0]);
  // Makefile


}

