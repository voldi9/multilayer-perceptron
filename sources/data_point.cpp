#include <iostream>

#include "data_point.hpp"

template<size_t D>
const boost::multi_array<int, D>& DataPoint<D>::data() const {
	return data_;
}

template<size_t D>
const inline int DataPoint<D>::label() const {
	return label_;
}

template<>
DataPoint<2>::DataPoint(const int label, const boost::multi_array<int, 2>& data) : label_(label), data_(data) {}


template<>
void DataPoint<2>::print() const {
	std::cout << label_ << ":\n";
	for (const auto& row : data_) {
		for (const auto& cell : row) {
			std::cout << " " << cell;
		}
		std::cout << std::endl;
	}
}