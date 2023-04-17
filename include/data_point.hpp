#pragma once

#include <boost/multi_array.hpp>
#include <vector>

// A single unit of training/test data. 
// Can have any number of dimensions but usually has 2 - for a 2D image. 
// Only accepts integer values.
template<size_t D>
class DataPoint {
private:
   const int label_;
   const boost::multi_array<int, D> data_;

public:
    DataPoint(const int label, const boost::multi_array<int, D>& data);
    const inline int label() const;
    const boost::multi_array<int, D>& data() const;
    void print() const;
    // static int items, width, heigth;
    // Image(int l, std::string data);
    // Image(std::ifstream& images, std::ifstream& labels);
    // int get_label();
    // void write(std::string filename);
};