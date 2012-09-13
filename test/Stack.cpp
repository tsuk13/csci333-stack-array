#include "gtest/gtest.h"
#include "../src/Stack.h"

TEST(StackTest, Push) {
  Stack* s = new Stack();
  s->push(6);

  EXPECT_EQ(6, s->peek());

  for(int i = 0; i<50; ++i){
    s->push(i);
  }
  for(int i =0; i<50; ++i){
    EXPECT_EQ(49-i, s->pop());
  } 
  EXPECT_EQ(6, s->peek());
  delete s;
}
