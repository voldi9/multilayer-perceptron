#include "literals.hpp"

const int MAX_COLOR_VALUE = 255;
const int IMG_MAGIC_NUMBER = 2051;
const int LBL_MAGIC_NUMBER = 2049;
const char* IMG_SOURCE = "train-images.idx3-ubyte";
const char* LBL_SOURCE = "train-labels.idx1-ubyte";
const char* IMG_FOLDER = "images/";
const char* LBL_FOLDER = "labels/";
const char* IMG_FORMAT = ".pgm";
const char* LBL_FORMAT = ".txt";
const int MAX_HEADER_LENGTH = 25;
const char* HEADER_PATTERN = "P5\n\n%d\n%d\n%d\n";

