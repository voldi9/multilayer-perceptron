#include <exception>

#include "data_parser.hpp"
#include "image_container.hpp"
#include "image.hpp"

DataParser::DataParser(const char* image_file, const char* label_file) {
    lbl_stream = false;
    init_stream(image_file, IMG_MAGIC_NUMBER);
    lbl_stream = true;
    init_stream(label_file, LBL_MAGIC_NUMBER);
}

void DataParser::init_stream(const char* name, int magic_number) {
  std::ifstream stream(name, std::ios::binary);
  auto fetch_int = [magic_number,this,&stream](bool magic=false) {
      int number;
      stream.read((char*) &number, sizeof(number));
      number = __builtin_bswap32(number);
      if(magic && number != magic_number)
        throw std::runtime_error("Magic number incorrect\nexpected: " + \
              std::to_string(magic_number) + "\ngot: " + std::to_string(number) + "\n");
      if (lbl_stream && !magic && number != items) {
        throw std::runtime_error("Incompatible items number in image / label files\nexpected: " + \
              std::to_string(items) + "\ngot: " + std::to_string(number) + "\n");
    }
      if(number <= 0)
        throw std::runtime_error("Non-positive value in one of the headers");
      return number;
  };

  fetch_int(true);
  if (!lbl_stream) {
    items = fetch_int();
    rows = fetch_int();
    cols = fetch_int();
    images = std::move(stream);
  }
  else {
    items = fetch_int();
    labels = std::move(stream);
  }
}

unsigned char DataParser::fetch_byte(std::ifstream& stream) {
    unsigned char buff;
    stream.read((char*) &buff, sizeof(buff));
    return buff;
}

Image DataParser::load_next_image() {
    int label;
    std::string data = "";
    label = fetch_byte(labels);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data += fetch_byte(images);
    return Image(label, data);
}

void DataParser::load_data() {
  container = ImageContainer(rows, cols);
  while(items--) {
    auto img = load_next_image();
    container.insert(img);
  }
  images.close();
  labels.close();
}