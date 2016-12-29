#include <string>
#include <iostream>
#include <memory>
using namespace std;

// without inheritance
class Basic
{
public:
    Basic(const string& name) : name_(name) {}
    const string& name() const { return name_; }

    template <typename F>
    auto run(F f) { return bind(f, this)(); }
private:
    const string name_;
};

// with inheritance
template <class C>
class Base
{
public:
    template <typename F>
    auto run(F f) { return bind(f, static_cast<C*>(this))(); }
};

class Derived : public Base<Derived>
{
public:
    Derived(const string& name) : name_(name) {}
    const string& name() const { return name_; }
private:
    const string name_;
};

int main()
{
    const auto basic = make_shared<Basic>("without inheritance");

    cout << basic->name() << endl;
    cout << basic->run(&Basic::name) << endl;

    const auto derived = make_shared<Derived>("inheritance");

    cout << derived->name() << endl;
    cout << derived->run(&Derived::name) << endl;
    return 0;
}
