#include "Stack.h"
#include <iostream>
#include <cassert>

Stack::Stack(int initialSize) {
  theStack = new int[initialSize];
  top = 0;
  currentSize = initialSize;
}

Stack::~Stack() {
  delete[] theStack;
}

void Stack::push(int value) {
  //if theStack is full
  // create new stack twice as big
  // copy all elements to new stack
  // delete old stack
  // point old stack pointer to new stack
  if(top >= currentSize){
    int* tmpStack = new int[currentSize * 2];
    for(int i = 0; i < currentSize; i++){
      tmpStack[i] = theStack[i];
    }
    currentSize = currentSize * 2;
    delete[] theStack;
    theStack = tmpStack;
  }
  assert(top < currentSize);
  theStack[top] = value;
  top++;
}

int Stack::pop() {
  top--;
  return theStack[top];
}

int Stack::peek() {
  return theStack[top-1];
}

int Stack::size() {
  return top;
}
