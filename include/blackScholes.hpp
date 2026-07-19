#ifndef BLACKSCHOLES_HPP
#define BLACKSCHOLES_HPP

#include "Option.hpp"

class BlackScholes {
public:
  static double price(const Option &option);
};
#endif
