#include "../include/impliedVolatility.hpp"
#include "../include/blackScholes.hpp"
#include "../include/greeks.hpp"

double ImpliedVolatility::calc_iv(const Option &option, double marketPrice) {
  Option temp_option = option;

  double guess = 0.20;
  const double tolerance = 1e-8;
  const int maxiterations = 100;

  for (int i = 0; i < maxiterations; i++) {

    temp_option.setIv(guess);
    double price = BlackScholes::price(temp_option);

    double error = price - marketPrice;
    double vega = Greeks::vega(temp_option);

    if (std::fabs(error) < tolerance)
      return guess;

    if (std::fabs(vega) < 1e-10)
      break;

    guess = guess - (error / vega);
  }
  return guess;
}
