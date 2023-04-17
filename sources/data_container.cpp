#include <fstream>
#include <string>
#include <exception>
#include <iostream>

#include "data_container.hpp"

template<>
void DataContainer<2>::insert(const DataPoint<2>& point) {
    dataset_.push_back(point);
}

template<>
void DataContainer<2>::print() const {
    for (auto& item : dataset_)
        item.print();
}