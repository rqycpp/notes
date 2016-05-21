#include <iostream>
#include <cstring>
#include "Vector.h"
using namespace std;

void Vector::bubble_sort(){
  for(int i = 0; i < length - 1; ++i){
    bool swapped = false;
    for(int j = 0; j < length - i - 1; ++j){
      if(data[j] > data[j + 1]){
        swap(data[j], data[j + 1]);
        swapped = true;
      }
    }
    if(!swapped)
      break;
  }
}

int main(){
  Vector arr(10);
  int a[10] = {1,3,5,7,9,2,4,6,8,10};
  for(int i = 0; i < 10; ++i){
    arr.insert(i,a[i]);
  }
  arr.bubble_sort();
  arr.print();
}
