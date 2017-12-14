//: C04:Stack.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Nested struct in linked list
#ifndef STACK_H
#define STACK_H

struct Stack {
  struct Node {
    void* data;
    Node* next;
    void initialize(void* dat, Node* nxt);
  }* head;
  int len;
  void initialize();
  void push(void* dat);
  void* peek();
  void* pop();
  void cleanup();
  int size();
};
#endif // STACK_H ///:~
