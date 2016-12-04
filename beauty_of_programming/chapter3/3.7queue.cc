#include <iostream>
#include <climits>
using namespace std;
const int MAX = 1000;

class Stack{
private:
  int elements_[MAX];
  int max_index_;
  int next_max_index_[MAX];
  int top_index_;
public:
  Stack();
  void Push(int x);
  int Pop();
  inline int Max();
  inline bool Empty();
};

Stack::Stack() {
  max_index_ = -1;
  top_index_ = -1;
  for (int i = 0; i < MAX; i++) {
    next_max_index_[i] = -1;
    elements_[i] = 0;
  }
}

void Stack::Push(int x) {
  if (top_index_ == MAX) {
    throw "Stack Overflow";
  }
  top_index_++;
  elements_[top_index_] = x;
  if (x > elements_[max_index_]) {
    next_max_index_[top_index_] = max_index_;
    max_index_ = top_index_;
  }
}

int Stack::Pop() {
  if (top_index_ < 0) {
    throw "Stack Empty";
  }
  int ret = elements_[top_index_];
  if (top_index_ == max_index_) {
    max_index_ = next_max_index_[top_index_];
  }
  top_index_--;

  return ret;
}

inline int Stack::Max() {
  if (max_index_ >= 0) {
    return elements_[max_index_];
  } else {
    return INT_MIN;
  }
}

inline bool Stack::Empty() {
  return top_index_ < 0 ? true : false;
}

class Queue {
private:
  Stack s1;// This for Enqueue
  Stack s2; // This for Dequeue
public:
  inline int Max();
  void Enqueue(int x);
  int Dequeue();
};

inline int Queue::Max() {
  int x = s1.Max();
  //cout << "The x = " << x << endl;
  int y = s2.Max();
  //cout << "The y = " << y << endl;
  return x > y ? x : y;
}

void Queue::Enqueue(int x) {
  s1.Push(x);
}

int Queue::Dequeue() {
  if (s2.Empty()) {
    while (!s1.Empty()) {
      s2.Push(s1.Pop());
    }
  }
  return s2.Pop();
}

int main(int argc, char const *argv[])
{
  Queue queue;
  queue.Enqueue(5);
  queue.Enqueue(4);
  queue.Enqueue(3);
  queue.Enqueue(7);
  queue.Enqueue(1);
  cout << "Dequeue = " << queue.Dequeue() << endl;
  cout << "Dequeue = " << queue.Dequeue() << endl;
  cout << "Max = " << queue.Max() << endl;
  return 0;
}






