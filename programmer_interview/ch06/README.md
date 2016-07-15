## 预处理、const与sizeof()

- const int *a; //正确
- const int *a = &b; 与 int const *a = &b; 两者一样
- 在const成员函数中，一旦企图修改数据成员的值，则编译器按错误处理。
```cpp
class pointer{
  int xVal, yVal;
  public:
  int GetY() const;//不改变数据成员值
  //const int GetY(); 返回值是常量，与上面的函数意义不同
};
```
- const与#define相比有什么不同？

  1. const常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行类型安全检查，而对后者只能
进行字符替换，没有类型安全检查，并且在字符替换中可能会产生意料不到的错误（边际效应）。

  2. 有些集成化的调试工具可以对const常量进行调试，但是不能对宏常量进行调试。

- 若在const成员函数中修改成员变量，需要`mutable`修饰。
```cpp
class C
{
  public:
  C(int i):m_count(i){};
  int incr() const
  {
    return ++m_count;
  }

  private:
  mutable int m_count;
}
```
