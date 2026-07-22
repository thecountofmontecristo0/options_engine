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

double Greeks::theta(const Option &option) {
  double s = option.getSpotPrice();
  double r = option.getRiskFreeRate();
  double d1 = BlackScholes::calcD1(option);
  double d2 = BlackScholes::calcD2(option);
  double t = option.getTimeToExpiry();
  double k = option.getStrikePrice();
  double vol = option.getIv();
  double common_term =
      -(s * vol * BlackScholes::normalPDF(d1)) / (2 * std::sqrt(t));
  if (option.getOptionType() == OptionType::Call) {
    return common_term - r * k * std::exp(-r * t) * BlackScholes::normalCDF(d2);
  }
  return common_term + r * k * std::exp(-r * t) * BlackScholes::normalCDF(-d2);
}

double Greeks::rho(const Option &option) {
  double d2 = BlackScholes::calcD2(option);
  double t = option.getTimeToExpiry();
  double r = option.getRiskFreeRate();
  double k = option.getStrikePrice();

  if (option.getOptionType() == OptionType::Put)
    return -(k * t * std::exp(-r * t) * BlackScholes::normalCDF(-d2));
  return k * t * std::exp(-r * t) * BlackScholes::normalCDF(d2);
}
