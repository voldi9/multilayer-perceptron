#include "data_point.hpp"
#include "mnist_parser.hpp"

DataContainer<2> MnistParser::parse(std::string f) {
	std::fstream file(f, std::ios::in);
	if (!file.is_open())
		throw std::invalid_argument("Could not open the file: " + f);

	std::string line, tmp;
	int label;
    DataContainer<2> data {};
    boost::multi_array<int, 2> image(boost::extents[width][height]);
	std::getline(file, line); // Skip the CSV column definitions
	int c = 5;
	while(std::getline(file, line)) {
		std::stringstream str(line);

		getline(str, tmp, ',');
		// Assuming label is always single-digit
		label = int(tmp[0] - '0');
		for (int i = 0; i < width * height; i++) {
			getline(str, tmp, ',');
			image[i / width][i % width] = std::stoi(tmp);
		}

		data.insert(DataPoint<2>{label, image});

		//DataPoint<2> datapoint {label, image};
		if (c-- < 0)
			break;
	}
	return data;
}

DataContainer<2> MnistParser::parse() {
	return parse(default_filename_);
}

