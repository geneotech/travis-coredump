#include <cstdlib>
#include <string>
#include <optional>
#include <variant>

int main(int argc, char** argv) {
  std::optional<int> abc = argc;
  std::variant<int, double> vvv = argc;

  if( argc > 1 && std::string(argv[1]) == "--crashplx" ) {
      // this will crash
      delete (int*)0xffffffff;    
  }

  return 0 * (*abc) * std::get<int>(vvv); 
}