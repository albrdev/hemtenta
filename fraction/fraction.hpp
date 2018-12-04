#ifndef _FRACTION_HPP_
#define _FRACTION_HPP_

/* class fraction:  Represents a number as a fraction with two integers numerator and denominator, e.g. N/D
                    Supports basic math operations on the fraction as a whole
*/
class fraction {
  private:
      int numer, denom;
      static int GCD(int a, int b);
  public:
      // fraction(): Default constructor that creates a fraction with the value 1/1
      fraction();
      // fraction(int N, int D): Default constructor that takes a numerator N and a denominator D and creates a fraction with the value of N/D
      fraction(int N, int D);

      // operator+(fraction F): Adds the fraction F (rvalue) to this fraction (lvalue), returns a new fraction with the result
      fraction operator+(fraction F);
      // operator-(fraction F): Subtracts the fraction F (rvalue) from this fraction (lvalue), returns a new fraction with the result
      fraction operator-(fraction F);
      // operator*(fraction F): Multiplies the fraction F (rvalue) by this fraction (lvalue), returns a new fraction with the result
      fraction operator*(fraction F);
      // operator/(fraction F): Divides this fraction (lvalue) by the fraction F (rvalue), returns a new fraction with the result
      fraction operator/(fraction F);
      // operator-(): Return a new fraction which is the negative of this (N/D becomes -N/D)
      fraction operator-();
      // inv(): Returns a new fraction which is the inverse of this (N/D becomes D/N)
      fraction inv();

      // print(): Prints the fraction (numerator and denominator separated by a forward slash) to the standard output stream
      void print();
};

#endif // _FRACTION_HPP_
