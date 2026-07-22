#include "../include/greeks.hpp"
#include "../include/blackScholes.hpp"
#include <cmath>

double Greeks::delta(const Option &option) {
  double d = BlackScholes::calcD1(option);
  if (option.getOptionType() == OptionType::Call) {
    return BlackScholes::normalCDF(d);
  }
  return BlackScholes::normalCDF(d) - 1;
}
double Greeks::gamma(const Option &option) {
  double s = option.getSpotPrice();
  double vol = option.getIv();
  double t = option.getTimeToExpiry();
  double d1 = BlackScholes::calcD1(option);

  return BlackScholes::normalPDF(d1) / (vol * s * std::sqrt(t));
}

double Greeks::vega(const Option &option) {
  double s = option.getSpotPrice();
  double d1 = BlackScholes::calcD1(option);
  double t = option.getTimeToExpiry();

  return s * BlackScholes::normalPDF(d1) * std::sqrt(t);
}
