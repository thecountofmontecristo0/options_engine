#ifndef BLACKSCHOLES_HPP
#define BLACKSCHOLES_HPP

#include "Option.hpp"
#include <cmath>
class BlackScholes {
public:
  static double price(const Option &option);

  static double normalCDF(double x);
};

#endif
