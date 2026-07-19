#include "../include/blackScholes.hpp"
#include <cmath>
double BlackScholes::price(const Option &option) {
  double S = option.getSpotPrice();
  double K = option.getStrikePrice();
  double T = option.getTimeToExpiry();
  double r = option.getRiskFreeRate();
  double vol = option.getIv();

  double d1, d2;

  d1 = (log(S / K) + (r + (vol * vol) / 2) * T) / vol * sqrt(T);

  d2 = d1 - vol * sqrt(T);

  return 0.0;
}
