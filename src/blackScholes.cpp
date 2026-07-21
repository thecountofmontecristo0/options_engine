#include "../include/blackScholes.hpp"
#include <cmath>

double BlackScholes::normalCDF(double x) {
  return 0.5 * (1.0 + erf(x / sqrt(2.0)));
}

double BlackScholes::normalPDF(double x) {
  return std::exp(-0.5 * x * x) / std::sqrt(2.0 * M_PI);
}
double BlackScholes::calcD1(const Option &option) {
  double S = option.getSpotPrice();
  double K = option.getStrikePrice();
  double T = option.getTimeToExpiry();
  double r = option.getRiskFreeRate();
  double vol = option.getIv();

  double d1;

  d1 = (log(S / K) + (r + (vol * vol) / 2.0) * T) / (vol * sqrt(T));
  return d1;
}

double BlackScholes::calcD2(const Option &option) {
  double d2;
  double T = option.getTimeToExpiry();
  double vol = option.getIv();

  d2 = calcD1(option) - vol * sqrt(T);
  return d2;
}
double BlackScholes::price(const Option &option) {
  double S = option.getSpotPrice();
  double K = option.getStrikePrice();
  double T = option.getTimeToExpiry();
  double r = option.getRiskFreeRate();

  double d1, d2;

  d1 = calcD1(option);
  d2 = calcD2(option);

  if (option.getOptionType() == OptionType::Call) {
    return S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);
  } else {
    return K * std::exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
  }
}
