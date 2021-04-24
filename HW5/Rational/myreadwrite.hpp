#ifndef MYREADWRITE_HPP
#define MYREADWITE_HPP

#include <iostream>
#include <array> 
#include <fstream>

template<typename T>
void myWrite(std::ofstream& ofile, const T &data){
    ofile.write(reinterpret_cast<const char *>(&data), sizeof(data));
}
template<typename T>
void myRead(std::ifstream& ifile, T &data){
    ifile.read(reinterpret_cast<char *>(&data), sizeof(data));
}


#endif