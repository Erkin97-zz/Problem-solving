class FooBar {
 private:
  int n;

 public:
  mutex foo_mu, bar_mu;
  FooBar(int n) {
    this->n = n;
    foo_mu.lock();
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      bar_mu.lock();
      printFoo();
      foo_mu.unlock();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      foo_mu.lock();
      printBar();
      bar_mu.unlock();
    }
  }
};