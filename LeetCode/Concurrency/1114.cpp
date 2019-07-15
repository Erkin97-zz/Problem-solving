class Foo {
 public:
  mutex first_mutex, second_mutex;
  Foo() {
    first_mutex.lock();
    second_mutex.lock();
  }

  void first(function<void()> printFirst) {
    printFirst();
    first_mutex.unlock();
  }

  void second(function<void()> printSecond) {
    first_mutex.lock();
    printSecond();
    first_mutex.unlock();
    second_mutex.unlock();
  }

  void third(function<void()> printThird) {
    second_mutex.lock();
    printThird();
    second_mutex.unlock();
  }
};