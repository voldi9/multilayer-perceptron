#include <cstdio>
#include <fstream>
#include <cstring>
#include "data_parser.hpp"
#include "literals.hpp"
#include "image.hpp"


int main()
{
  try {
    DataParser parser = DataParser(IMG_SOURCE, LBL_SOURCE);
    parser.load_data();
    parser.container.write_to_files();
  }
  catch(std::runtime_error& e) {
    printf("RUNTIME ERROR:\n%s\nABORTING...\n", e.what());
  }
  return 0;
}