#include "../include/option.hpp"
#include <stdexcept>
Option::Option(double spot, double strike, double time, double iv, double rate,
               OptionType type) {
  setSpotPrice(spot);
  setStrikePrice(strike);
  setTimeToExpiry(time);
  setIv(iv);
  setRiskFreeRate(rate);

  optionType = type;
}

void Option::setStrikePrice(double strike) {
  if (strike <= 0)
    throw std::invalid_argument("Strike must be positive");
  strikePrice = strike;
}

void Option::setSpotPrice(double spot) {
  if (spot <= 0)
    throw std::invalid_argument("Spot must be positive");
  spotPrice = spot;
}

void Option::setTimeToExpiry(double time) {
  if (time <= 0)
    throw std::invalid_argument("Time must be positive");
  timeToExpiry = time;
}

void Option::setIv(double iv) {
  if (iv < 0)
    throw std::invalid_argument("Volatility can not be negetive");
  volatility = iv;
}
void Option::setRiskFreeRate(double rate) { riskFreeRate = rate; }

// getter func
double Option::getSpotPrice() const { return spotPrice; }

double Option::getStrikePrice() const { return strikePrice; }

double Option::getTimeToExpiry() const { return timeToExpiry; }

double Option::getIv() const { return volatility; }

double Option::getRiskFreeRate() const { return riskFreeRate; }

OptionType Option::getOptionType() const { return optionType; }
