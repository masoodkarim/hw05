/*******************************************************************************
Author :      Waqar Saleem
Email  :      waqar.saleem@sse.habib.edu.pk
File   :      main.cpp
Date   :      21 Oct 2018

Tests SmartString its implementation as described in Assignment 5 of CS 224 OOP, Fall 2018.

Uses auto which requires c++11.
*******************************************************************************/

#include <cassert>
#include <cstring>

#include <iostream>

#include "SmartString.h"

int main(int argc, char** argv) {
  char hello_array[] = "Hello ";
  char world_array[] = "World!";
  char hello_world_array[] = "Hello World!";
  char* texts[] = {hello_array, world_array, hello_world_array};

  std::cout << "Testing " << std::flush;

  for (auto text_array : texts) {
    SmartString smart_string(text_array);
    assert(smart_string.length() == strlen(text_array));
    std::cout << "." << std::flush;
    assert(smart_string.length() == SmartString(smart_string).length());
    std::cout << "." << std::flush;
    assert(smart_string == text_array);
    std::cout << "." << std::flush;
    assert(smart_string == SmartString(smart_string));
    std::cout << "." << std::flush;
  }

  {
    SmartString hello(hello_array);
    assert(hello + world_array == hello + SmartString(world_array));
    std::cout << "." << std::flush;
    SmartString temp(hello);
    temp += world_array;
    assert(temp == hello_world_array);
    std::cout << "." << std::flush;
    hello += SmartString(world_array);
    assert(temp == hello);
    std::cout << "." << std::flush;
  }  

  {
    SmartString hello(hello_array);
    SmartString temp(hello);
    temp.join(world_array);
    assert(temp == hello_world_array);
    std::cout << "." << std::flush;
    hello.join(SmartString(world_array));
    assert(temp == hello);
    std::cout << "." << std::flush;
  }  

  std::cout << "\nAll tests passed.\n";
  
  return 0;
}
