#include <cstdlib>
#include <string>
#include <optional>
#include <variant>
#include <iostream>

template <class S, class... Types>
constexpr bool is_one_of_v = (... || std::is_same_v<S, Types>);

template <class d>
class a {
    auto& get() {
        return static_cast<d*>(this)->v;
    }

    const auto& get() const {
        return static_cast<d*>(this)->v;
    }
public:
    void f() {
        std::cout << get() << std::endl;
    }
};

struct b : a<b> {
    int v = 42;
};

int main(int argc, char** argv) {
  b bb;
  bb.f();
  static_assert(is_one_of_v<int, double, int>);
  !static_assert(is_one_of_v<int, double>);
  
  std::optional<int> abc = argc;
  std::variant<int, double> vvv = argc;

  if( argc > 1 && std::string(argv[1]) == "--crashplx" ) {
      // this will crash
      delete (int*)0xffffffff;    
  }

  return 0 * (*abc) * std::get<int>(vvv); 
}
