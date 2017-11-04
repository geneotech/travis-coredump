#include <cstdlib>
#include <string>

int main(int argc, char** argv) {
  if( argc > 1 && std::string(argv[1]) == "--crashplx" ) {
      // this will crash
      delete (int*)0xffffffff;    
  }

  return 0; 
}