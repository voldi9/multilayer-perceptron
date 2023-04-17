#include <cstdio>
#include <fstream>
#include <cstring>
#include<iostream>
// #include "data_parser.hpp"
// #include "literals.hpp"
// #include "image.hpp"
#include "data_point.hpp"
#include "data_container.hpp"
#include "mnist_parser.hpp"

int main()
{
  auto dataset = MnistParser::parse();

  std::cout << "eheh: ";
  dataset.print(); 
  return 0;
}

