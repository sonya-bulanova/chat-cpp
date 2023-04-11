//DynamicArray.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class DynamicArray{
public:
  DynamicArray();
  DynamicArray(size_t n, const T & object);
private:
  size_t length;
  T * array_data;
};
