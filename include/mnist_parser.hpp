#pragma once

#include <format>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "data_container.hpp"

class MnistParser {
private:
	MnistParser() {}
	static inline std::string default_filename_ = "data/mnist_train.csv";
	static inline int width = 28;
	static inline int height = 28;
public:
	static DataContainer<2> parse(std::string f);
	static DataContainer<2> parse();
};