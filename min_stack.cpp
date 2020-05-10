#include <algorithm>
#include <iostream>
#include <vector>

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
      v.push_back(x);
      size++;
  }

  void pop() {
    if (v.size() != 0)
    {
      v.pop_back();
      size--;
    }
  }

  int top() {
    if (size)
      return v[size-1];
    return 0;
  }

  int getMin() {
    if (size)
    {
      auto min = std::min_element(std::begin(v), std::end(v));
      return *min;
    }
    return 0;
  }
private:
  std::vector<int> v{};
  int size{0};
};

int main()
{
  MinStack s{};
  s.push(-2);
  s.push(0);
  s.push(-3);
  s.getMin();
  s.pop();
  s.top();
  s.getMin();
  return 0;
}
