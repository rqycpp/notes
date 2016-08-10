// 插入排序
// https://zh.wikipedia.org/wiki/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F
// 它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
//
// 从第一个元素开始，该元素可以认为已经被排序
// 取出下一个元素，在已经排序的元素序列中从后向前扫描
// 如果该元素（已排序）大于新元素，将该元素移到下一位置
// 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
// 将新元素插入到该位置后
// 重复步骤2~5

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

template<typename T>
void insertion_sort(T arr[], int len)
{
	int i, j;
	for (i = 1; i < len; ++i) {//总体思想就是将未排序数插入到已经排序的集合中。
		for (j = i - 1; j >= 0; --j) {
			if (arr[j] > arr[j + 1])
				swap(arr[j],arr[j + 1] );
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
