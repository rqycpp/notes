#include <iostream>
#include <cstring>
#include "Vector.h"
using namespace std;

void Vector::merge_sort(int l, int r) {
  if (l == r)
    return;
  int mid = (l + r) / 2;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);
  int x = l, y = mid + 1, loc = l;
  while (x <= mid || y <= r) {
    if (x <= mid && (y > r || data[x] <= data[y])) {
      temp[loc] = data[x++];
    } else {
      temp[loc] = data[y++];
    }
    ++loc;
  }
  for (int i = l; i <= r; ++i) {
    data[i] = temp[i];
  }
}

int main() {
  Vector arr(10);
  int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  for (int i = 0; i < 10; ++i) {
    arr.insert(i, a[i]);
  }
  arr.merge_sort(0, 9);
  arr.print();
}
