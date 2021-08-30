// Khoa Tran
// CSE 374 HW 7
// 06/04/2020

// Purpose of Rational.cpp:
// Implementation of the type Rational class
// interface that is in Rational.h

#include "Rational.h"

namespace rational374 {

  int greatest_factor(int n, int d);

  Rational::Rational() {
    numer_ = 0;
    denom_ = 1;
  }

  Rational::Rational(int n) {
    numer_ = n;
    denom_ = 1;
  }

  Rational::Rational(int n, int d) {
    numer_ = n;
    denom_ = d;
  }

  // Return the lowest term numerator
  int Rational::n() const {
    if (denom_ == 0) {
      return numer_;
    } else if (denom_ > 0) {
      return numer_ / greatest_factor(numer_, denom_);
    } else {
      return -1 * (numer_ / greatest_factor(numer_, denom_));
    }
  }

  // Return the lowest term denominator
  // never being zero
  int Rational::d() const {
    if (denom_ == 0) {
      return denom_;
    } else if (denom_ > 0) {
      return denom_ / greatest_factor(numer_, denom_);
    } else {
      return -1 * (denom_ / greatest_factor(numer_, denom_));
    }
  }

  // Compute the greatest common factor
  // between the numerator and denominator
  int greatest_factor(int n, int d) {
    while (d != 0) {
      int temp = d;
      d = n % d;
      n = temp;
    }
    return n;
  }

  Rational Rational::plus(Rational other) const {
    int den = denom_ * other.denom_;
    int num = (denom_ * other.numer_) + (numer_ * other.denom_);
    return Rational(num, den);
  }

  Rational Rational::minus(Rational other) const {
    int den = denom_ * other.denom_;
    int num = (numer_ * other.denom_) - (denom_ * other.numer_);
    return Rational(num, den);
  }

  Rational Rational::times(Rational other) const {
    int den = denom_ * other.denom_;
    int num = numer_ * other.numer_;
    return Rational(num, den);
  }

  Rational Rational::div(Rational other) const {
    int num = numer_ * other.denom_;
    int den = denom_ * other.numer_;
    return Rational(num, den);
  }
}

