template <typename T>
class MaxHeap {
 public:
  MaxHeap(int capacity) : capacity_(capacity), count_(0) {
    data_ = new T[capacity_ + 1];
  }

  MaxHeap(T arr[], int n) : capacity_(n), count_(0) {
    data_ = new T[capacity_ + 1];
    for (int i = 1; i <= n; ++i) {
      data_[i] = arr[i - 1];
    }
    for (int i = n / 2; i > 0; --i) {
      shiftDown(i);
    }
  }

  ~MaxHeap() { delete[] data_; }

  int size() { return count_; }

  bool empty() { return count_ == 0; }

  void push(T e) {
    assert(count_ + 1 <= capacity_);
    data_[++count_] = e;
    shiftUp(count_);
  }

  void pop() {
    assert(count_ > 0);
    swap(data_[count_], data_[1]);
    --count_;
    shiftDown(1);
  }

  T top() {
    assert(count_ > 0);
    return data_[1];
  }

  // 以树状打印整个堆结构
  void testPrint() {
    // 我们的testPrint只能打印100个元素以内的堆的树状信息
    if (size() >= 100) {
      cout << "This print function can only work for less than 100 int";
      return;
    }

    // 我们的testPrint只能处理整数信息
    if (typeid(T) != typeid(int)) {
      cout << "This print function can only work for int T";
      return;
    }

    cout << "The max heap size is: " << size() << endl;
    cout << "data_ in the max heap: ";
    for (int i = 1; i <= size(); i++) {
      // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
      assert(data_[i] >= 0 && data_[i] < 100);
      cout << data_[i] << " ";
    }
    cout << endl;
    cout << endl;

    int n = size();
    int max_level = 0;
    int number_per_level = 1;
    while (n > 0) {
      max_level += 1;
      n -= number_per_level;
      number_per_level *= 2;
    }

    int max_level_number = int(std::pow(2, max_level - 1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for (int level = 0; level < max_level; level++) {
      string line1 = string(max_level_number * 3 - 1, ' ');

      int cur_level_number =
          min(count_ - int(std::pow(2, level)) + 1, int(std::pow(2, level)));
      bool isLeft = true;
      for (int index_cur_level = 0; index_cur_level < cur_level_number;
           index++, index_cur_level++) {
        putNumberInLine(data_[index], line1, index_cur_level,
                        cur_tree_max_level_number * 3 - 1, isLeft);
        isLeft = !isLeft;
      }
      cout << line1 << endl;

      if (level == max_level - 1) break;

      string line2 = string(max_level_number * 3 - 1, ' ');
      for (int index_cur_level = 0; index_cur_level < cur_level_number;
           index_cur_level++)
        putBranchInLine(line2, index_cur_level,
                        cur_tree_max_level_number * 3 - 1);
      cout << line2 << endl;

      cur_tree_max_level_number /= 2;
    }
  }

 private:
  int capacity_;
  int count_;
  T *data_;

  void shiftUp(int k) {
    T e = data_[k];
    while (k > 1 && data_[k / 2] < e) {
      data_[k] = data_[k / 2];
      k /= 2;
    }
    data_[k] = e;
  }

  void shiftDown(int k) {
    T e = data_[k];
    while (2 * k <= count_) {
      int j = 2 * k;
      if (j + 1 <= count_ && data_[j] < data_[j + 1]) {
        ++j;
      }
      if (e >= data_[j]) {
        break;
      }
      data_[k] = data_[j];
      k = j;
    }
    data_[k] = e;
  }

  void putNumberInLine(int num, string &line, int index_cur_level,
                       int cur_tree_width, bool isLeft) {
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
    assert(offset + 1 < line.size());
    if (num >= 10) {
      line[offset + 0] = '0' + num / 10;
      line[offset + 1] = '0' + num % 10;
    } else {
      if (isLeft)
        line[offset + 0] = '0' + num;
      else
        line[offset + 1] = '0' + num;
    }
  }

  void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int sub_sub_tree_width = (sub_tree_width - 1) / 2;
    int offset_left =
        index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
    assert(offset_left + 1 < line.size());
    int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width +
                       1 + sub_sub_tree_width;
    assert(offset_right < line.size());

    line[offset_left + 1] = '/';
    line[offset_right + 0] = '\\';
  }
};