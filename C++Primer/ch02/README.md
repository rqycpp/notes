### 类型转换

- 当我们赋给无符号类型一个超出它表示范围的值时，结果是初始值对无符号类型表示数值总数取模后的余数。
- 当我们赋给带符号类型一个超出它表示范围的值时，结果是**未定义**的。
- 当一个算数表达式中既有无符号数又有int值时，那个int值就会转换成无符号数。
- 当从无符号数中减去一个值时，不管这个值是不是无符号数，我们都必须确保结果不能是一个负值：
```cpp
unsigned u1 = 42, u2 = 10;
cout<<u1 - u2<<endl;//32
cout<<u2 - u1<<endl;//4294967264
/*------------------------------*/
for(unsigned u = 10; u >= 0; --u){//死循环
    cout<<u<<endl;
}
```

### 变量

- 可以用先定义的变量值去初始化后定义的其他变量。
```cpp
double price = 109.99, discount = price * 0.16;
```
- 初始化和赋值是两个完全不同的操作：初始化的含义是创建变量时赋予其一个初始值；赋值的含义是把对象的当前值擦去，以一个新值来替代。
- 如果我们使用列表初始化且初始值存在丢失信息的风险，则编译器将报错。
```cpp
long double ld = 3.1415926;
int a{ld}, b = {ld};//错误
int c(ld), b(ld);//正确
```
- 如果内置类型的变量未被显示初始化，它的值由定义的位置决定。定义于任何函数体之外的变量被初始化为0。
- 如果想声明一个变量而非定义它，就在变量名前添加关键字`extern`，而且不要显示地初始化变量。
```cpp
extern int i;//声明i而非定义i
int j;//声明并定义
extern double pi = 3.14159;//定义
```

### 引用

- 引用并非对象，相反的，它只是为一个已经存在的对象所起的另外一个名字。
- 因为引用本身不是一个对象，所以不能定义引用的引用。
- 引用只能绑定在对象上。

```cpp
int *p = &i;
itn *&r = p;//指针的引用
```
### 指针

- 把int变量直接赋值给指针是错误的操作。
```cpp
itn zero = 0;
int *p = zero;//错误
```

### const限定符

- const对象必须初始化（编译时初始化或运行时初始化）。
- 常量特征仅仅在执行改变操作时才会发挥作用。
- 如果想在多个文件之间共享const对象，必须在变量的定义之前添加`extern`关键字。
- 常量引用是对const的引用，即`reference to const`。严格来说，并不存在**常量引用**。因为引用不是一个**对象**，所以我们没法让引用本身恒定不变。事实上，由于C++语言并不允许随意改变引用所绑定的对象，所以从这层意义上理解所有的引用又都算是常量。引用的对象是常量还是非常量可以觉得其所能参与的操作，却无论如何都不会印象到引用和对象的**绑定关系**本身。
- 初始化常量引用时允许任意表达式作为初始值,只要该表达式的结果能转换成引用的类型即可。
```cpp
int i = 42;
const int &r1 = i;//right
const int &r2 = 42;//right
const int &r3 = r1 * r2;//right
int &r4 = r1 * 2;//wrong
/*------------------------*/
//探究原理
double dval = 3.14;
const int &ri = dval;
//等价于
const int temp = dval;//类型转换，由double转换为int
const int &ri = temp;//让ri绑定这个临时量
```
- 对const的引用可能引用一个并非const的对象，常量引用仅对引用可参与的操作做出了限定，对于引用的对象本身是不是一个常量未作限定。
```cpp
int i = 42;
int &r1 = i;
const int &r2 = i;
r1 = 0;
r2 = 0;//wrong
```

### 指针和const

- 指向常量的指针`pointer to const`，不能用于改变其**所指对象**的值。
```cpp
const double pi = 3.14;
double *ptr = &pi;//wrong
const double *cptr = &pi;
*cptr = 42;//wrong
```
- 允许一个指向常量的指针指向一个非常量对象。
```cpp
double dval = 3.14;
const double *cptr = dval;
```
- 指向常量的指针仅仅要求**不能通过该指针**改变对象的值，而没有规定那个对象的值能不能通过其他途径改变。简单的来说，const修饰的是指针，使指针达到一种**自以为是**的效果，它觉得自己指向了常量，所以不会去做对不起常量的事。
- 常量指针`const pointer`，指针是**对象**而引用不是，因此就像其他对象类型一样，允许把指针本身定为常量。常量指针必须初始化，而且一旦初始化完成，则它的值（也就是存放在指针中的那个**地址*）就不能再改变了。
```cpp
int errNumb = 0;
int *const curErr = &errNumb; //curErr一直指向errNumb
const double pi = 3.14;
const double *const pip = &pi;//pip是一个指向常量对象的.常量指针。（从右至左阅读，分析pip属性）
```
- 指针本身是一个常量并不意味着不能通过指针修改其所指对象的值。
```cpp
*pip = 2.72; //错误，pip是一个指向常量的指针
if(*curErr){
    errorHandler();
    *currErr = 0;//正确
}
```
- 顶层const(`top-level const`)表示指针**本身**是个**常量**。
- 底层const(`low-level const`)表示指针**所指**是一个**常量**。
```cpp
int i = 0;
int *const p1 = &i;//top
const int ci = 42;//top
const int *p2 = &ci;//low
const int *const p3 = p2; //low + top
```
- 用于声明引用的const都是**底层const**。
```cpp
const int &r = ci;//low
```
- 当执行对象的拷贝操作时，顶层const不受影响。
```cpp
i = ci;//正确，ci是一个顶层const，对该操作无影响
p2 = p3;//正确，p2和p3均指向常量，p3的顶层const对该操作无影响
```
- 底层const的限制却不能忽视，当执行对象的拷贝操作时，拷入和拷出的对象必须具有相同的底层const资格，或者两个对象的数据类型必须能够转换。一般来说，非常量可以转换成常量，反之则不行。

### constexpr和常量表达式

- 常量表达式`const expression`是指**值不会改变**并且在**编译过程**就能得到计算结果的表达式。
- 一个对象（或表达式）是不是常量表达式由它的**数据类型**和**初始值**共提决定
```cpp
const int max_files = 20;//max_files是常量表达式
const int limit = max_files + 1;//limit是常量表达式
int staff_size = 27;//staff_size不是常量表达式
const int sz = get_size();//sz不是常量表达式
```

### auto类型说明符

- auto定义的类型变量必须有**初始值**（让编译器通过初始值来推算变量的类型）。
- auto一般会忽略掉**顶层const**，同时**底层const**则会保留下来。

### decltype类型指示符

- decltype返回该变量的类型（包括顶层const和引用在内）。
```cpp
const int ci = 0, &cj = ci;
decltype(ci) x = 0;//x的类型是const int
decltype(cj) y = x;//y的类型是const int&，y绑定到变量x
decltype(cj) z;//错误，z是一个引用，必须初始化
```
- 引用从来都作为其所指对象的同义词出现，只有在decltype处是一个例外。
- 如果decltype使用的表达式不是一个变量，则decltype返回表达式结果对应的类型。有些表达式将向decltype返回一个**引用类型**。一般来说当这种情况发生时，意味着该表达式的结果对象能作为一条**赋值语句的左值**。
```cpp
int i = 42, *p = &i, &r = i;
decltype(r + 0)b;//正确，加法的结果是int
decltype(*p) c;//错误，c是int&，必须初始化
```
- 如果表达式的内容是**解引用**操作，则decltype将得到引用类型。
- `decltype((varibale))`的结果永远是**引用**，而`decltype(variable)`结果只有当varibale本身就是一个引用时才是引用。

### 自定义数据结构

- C++11新标准规定，可以为数据成员提供一个**类内初始值**。























