- 计算x转化成二进制后包含1的数量

```cpp
#include <iostream>
using namespace std;
int func(int x)
{
  int count = 0;
  while(x){
    ++count;
    x = x & (x - 1);
  }
  return count;
}

int main()
{
  cout<<func(9999)<<endl;
  return 0;
}
//print 8, because bin(9999) is '0b10011100001111'
```
