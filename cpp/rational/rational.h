#ifndef __RATIONAL_H__
#define __RATIONAL_H__

#include <exception>

template <typename Integral = int>
class Rational {
public:
    Rational(Integral numer): Rational(numer, 1) {}
    Rational(Integral numer, Integral denom) {
        if (denom < 0) {
            // TODO: INT_MIN
            this->__n = -numer;
            this->__d = -denom;
        } else if (denom > 0) {
            this->__n = numer;
            this->__d = denom;
        } else {
            throw std::exception("divide by zero");
        }
    }

    Rational operator+(const Rational &that);
    Rational operator-(const Rational &that);
    Rational operator*(const Rational &that);
    Rational operator/(const Rational &that);

private:
    Integral __n, __d;
};


#endif  // __RATIONAL_H__