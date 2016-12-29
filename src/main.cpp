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

int main()
{
    const auto basic = make_shared<Basic>("pp");

    cout << basic->name() << endl;
    cout << basic->run(&Basic::name) << endl;

    return 0;
}
