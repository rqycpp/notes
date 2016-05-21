#include <iostream>
#include <cstring>
#include "Vector.h"
using namespace std;

void Vector::insertion_sort(){
  for(int i = 0; i < length; ++i){
    for(int j = i - 1; j >= 0; --j){
      if(data[j] > data[j + 1]){
        swap(data[j], data[j + 1]);
      }
      else
        break;
    }
  }
}

int main(){
  Vector arr(10);
  int a[10] = {1,3,5,7,9,2,4,6,8,10};
  for(int i = 0; i < 10; ++i){
    arr.insert(i,a[i]);
  }
  arr.insertion_sort();
  arr.print();
}
