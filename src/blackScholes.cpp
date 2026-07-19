#include "../include/blackScholes.hpp"
#include <cmath>

double BlackScholes::normalCDF(double x) {
  return 0.5 * (1.0 + erf(x / sqrt(2.0)));
}

double BlackScholes::price(const Option &option) {
  double S = option.getSpotPrice();
  double K = option.getStrikePrice();
  double T = option.getTimeToExpiry();
  double r = option.getRiskFreeRate();
  double vol = option.getIv();

  double d1, d2;

  d1 = (log(S / K) + (r + (vol * vol) / 2.0) * T) / (vol * sqrt(T));

  d2 = d1 - vol * sqrt(T);

  if (option.getOptionType() == OptionType::Call) {
    return S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);
  } else {
    return K * std::exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
  }
}
