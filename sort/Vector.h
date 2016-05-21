//自定义顺序表类
class Vector {
private:
  int size, length;
  int *data, *temp; // temp在归并排序中会用到
public:
  Vector(int input_size) {
    size = input_size;
    length = 0;
    data = new int[size];
    temp = new int[size];
  }
  ~Vector() {
    delete[] data;
    delete[] temp;
  }
  bool insert(int loc, int value) {
    if (loc < 0 || loc > length) {
      return false;
    }
    if (length >= size) {
      return false;
    }
    for (int i = length; i > loc; --i) {
      data[i] = data[i - 1];
    }
    data[loc] = value;
    ++length;
    return true;
  }
  void print() {
    for (int i = 0; i < length; ++i) {
      if (i > 0) {
        std::cout << " ";
      }
      std::cout << data[i];
    }
    std::cout << std::endl;
  }
  void insertion_sort();
  void bubble_sort();
  void merge_sort(int l, int r);
};
