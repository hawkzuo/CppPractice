
#include "Stack.h"
#include "require.h"
using namespace std;

// new & delete:
// new creates the ptr and object
// delete removes the object from memory

void Stack::Node::initialize(void* dat, Node* nxt) {
  data = dat;
  next = nxt;
}

void Stack::initialize() { head = nullptr; len = 0; }

void Stack::push(void* dat) {
  // Use 'auto' instead of explicit 'Node'
  auto * newLink = new Node;
  newLink->initialize(dat, head);
  head = newLink;
  len ++;
}

void* Stack::peek() { 
  require(head != nullptr, "Stack empty");
  return head->data; 
}

void* Stack::pop() {
  if(head == nullptr) return nullptr;
  void* result = head->data;
  Node* oldHead = head;
  head = head->next;
  delete oldHead;
  len --;
  return result;
}

void Stack::cleanup() {
  require(head == nullptr, "Stack not empty");
}

int Stack::size() {
  return len;
}
///:~
