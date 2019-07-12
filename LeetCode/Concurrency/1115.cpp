class FooBar {
 private:
  int n;

 public:
  mutex foo_mu;
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      foo_mu.lock();
      printFoo();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      printBar();
      foo_mu.unlock();
    }
  }
};