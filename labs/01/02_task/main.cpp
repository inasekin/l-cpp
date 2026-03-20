//
// Created by Иван Насекин on 06.02.2026.
//
#include <iostream>
#include "const_utils.h"

int main() {
  int x = 42;

  printValue(&x);
  printValueRef(x);

  setValue(&x, 100);

  const int* p1 = &x;
  tryModify(p1);

  // *p1 = 50; error: read-only variable is not assignable

  int y = 200;
  int* const p2 = &y;

  // p2 = &x; error: cannot assign to variable 'p2' with const-qualified type 'int *const'
  *p2 = 300;

  std::cout << *p2 << '\n';

  return 0;
}