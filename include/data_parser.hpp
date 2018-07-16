#pragma once

#include <fstream>

#include "literals.hpp"
#include "image_container.hpp"
#include "image.hpp"

class DataParser {
  private:
    bool lbl_stream;
    int items, rows, cols;
    std::ifstream images, labels;
    Image load_next_image();
    void init_stream(const char* name, int magic_number);
    unsigned char fetch_byte(std::ifstream& stream);
  public:    
    ImageContainer container;
    DataParser(const char* image_file, const char* label_file);
    void load_data();
};