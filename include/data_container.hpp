#pragma once

#include <vector>

#include "data_point.hpp"

// Container class for our dataset.
template<size_t D>
class DataContainer {
private:
    std::vector<DataPoint<D>> dataset_;
public:
    DataContainer() : dataset_({}) {};
    DataContainer(const std::vector<DataPoint<D>>& dataset) : dataset_(dataset) {};
    //void parse();
    void insert(const DataPoint<D>& point);
    void print() const;
    // void write_to_files();
    // void insert(Image& img);
    // int get_items();
    // int get_rows();
    // int get_cols();
};