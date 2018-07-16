#pragma once

#include <vector>

#include "literals.hpp"
#include "image.hpp"

class ImageContainer {
  private:
    int rows, cols;
    std::vector<Image> images;
  public:
    ImageContainer();
    ImageContainer(int r, int c);
    void write_to_files();
    void insert(Image& img);
    int get_items();
    int get_rows();
    int get_cols();
};