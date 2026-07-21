#ifndef GREEKS_HPP
#define GREEKS_HPP

#include "option.hpp"
class Greeks {
public:
  static double delta(const Option &option);
  static double gamma(const Option &option);
  static double theta(const Option &option);
  static double vega(const Option &option);
  static double rho(const Option &option);

private:
  static double normalPDF(double x);
};
#endif
