#include <fstream>
#include <string>
#include <exception>

#include "image_container.hpp"

ImageContainer::ImageContainer() : images({}) { }

ImageContainer::ImageContainer(int r, int c) : images({}), rows(r), cols(c) { }

void ImageContainer::write_to_files() {
    int file = -1;
    for (auto& img : images) {
      img.write(std::to_string(++file));
      printf("Image %d printed (label %d)\n", file, img.get_label());
    }
}

void ImageContainer::insert(Image& img) {
    images.push_back(img);
}

int ImageContainer::get_items() {
    return images.size();
}

int ImageContainer::get_rows() {
    return rows;
}

int ImageContainer::get_cols() {
    return cols;
}