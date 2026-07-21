#ifndef BLACKSCHOLES_HPP
#define BLACKSCHOLES_HPP

#include "option.hpp"
#include <cmath>
class BlackScholes {
public:
  static double price(const Option &option);
  static double calcD1(const Option &option);
  static double calcD2(const Option &option);
  static double normalPDF(double x);
  static double normalCDF(double x);
};

#endif
