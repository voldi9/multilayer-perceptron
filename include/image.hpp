#pragma once

#include <string>

class Image {
  private:
    std::string data;
    int label;

  public:
    static int items, width, heigth;
    Image(int l, std::string data);
    Image(std::ifstream& images, std::ifstream& labels);
    int get_label();
    void write(std::string filename);
};