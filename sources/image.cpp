#include <string>
#include <cstring>
#include <fstream>

#include "image.hpp"
#include "literals.hpp"

Image::Image(int l, std::string d) : label(l), data(d) { }

int Image::get_label() {
    return label;
}

void Image::write(std::string filename) {
    char header[MAX_HEADER_LENGTH];
    std::snprintf(header, sizeof(header), HEADER_PATTERN, Image::width, Image::heigth, MAX_COLOR_VALUE);

    std::ofstream image(IMG_FOLDER + filename + IMG_FORMAT, std::ios::binary);
    image.write(header, strlen(header));
    image.write(data.c_str(), data.length());

    label += '0';
    std::ofstream labelfile(LBL_FOLDER + filename + LBL_FORMAT);
    labelfile.write((char*) &label, sizeof(label));
    labelfile.write((char*) "\n", sizeof(label));
    label -= '0';
}


int Image::items;
int Image::width;
int Image::heigth;