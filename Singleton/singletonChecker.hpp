#include <functional>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    T* firstObj = factory();
    T* secondObj = factory();
    return (firstObj == secondObj);
  }
};