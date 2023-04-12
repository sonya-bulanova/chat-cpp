//DynamicArray.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class DynamicArray{
public:
  DynamicArray();
  DynamicArray(int n, const T & object);
  DynamicArray(const DynamicArray & dyn_array);
  ~DynamicArray();
  DynamicArray & operator=(const DynamicArray & dyn_array);

  int Size();
  void Resize(int new_length);
  void PushBack(const T & val);
  void PopBack(const T & val);

  void DeleteElement(int idx, const T & val);

private:
  int length;
  T * array_data;
};

template <typename T>
DynamicArray::DynamicArray(){
  this -> length = 0;
  array_data = nullptr;
  std::cout << "Default constructor worked" << std::endl;
}

template <typename T>
DynamicArray::DynamicArray(int n, const T & object){
  this -> length = n;
  array_data = new T[length];
  for (int i = 0; i < length; i++){
    array_data[i] = object;
  }
  
}
