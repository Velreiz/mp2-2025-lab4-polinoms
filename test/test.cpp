#include "Polynomial.h"
#include "pch.h"

// because of private section in Polynomial class, function read info from
// console
std::string getPrint(const Polynomial &p) {
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
  p.print();
  std::cout.rdbuf(old);
  std::string s = buffer.str();
  if (!s.empty() && s.back() == '\n')
    s.pop_back();
  return s;
}

TEST(PolyTest, AddSingle) {
  Polynomial p;
  p.add_monom(5, 1, 0, 0);
  EXPECT_EQ(getPrint(p), "5x^1");
}

TEST(PolyTest, AddZeroCoeff) {
  Polynomial p;
  p.add_monom(0, 1, 1, 1);
  EXPECT_EQ(getPrint(p), "0");
}

TEST(PolyTest, AddNegative) {
  Polynomial p;
  p.add_monom(-3, 0, 0, 2);
  EXPECT_EQ(getPrint(p), " - 3z^2");
}

TEST(PolyTest, CombineSimilar) {
  Polynomial p;
  p.add_monom(2, 1, 1, 1);
  p.add_monom(3, 1, 1, 1);
  EXPECT_EQ(getPrint(p), "5x^1y^1z^1");
}

TEST(PolyTest, SelfCancel) {
  Polynomial p;
  p.add_monom(5, 2, 0, 0);
  p.add_monom(-5, 2, 0, 0);
  EXPECT_EQ(getPrint(p), "0");
}

TEST(PolyTest, Degree) {
  Polynomial p;
  EXPECT_THROW(p.add_monom(1, 10, 0, 0), std::out_of_range);
}

TEST(PolyTest, NegativeDegree) {
  Polynomial p;
  EXPECT_THROW(p.add_monom(1, -1, 0, 0), std::out_of_range);
}

TEST(PolyTest, Sum) {
  Polynomial p1, p2;
  p1.add_monom(1, 1, 0, 0);
  p2.add_monom(1, 0, 1, 0);
  EXPECT_EQ(getPrint(p1 + p2), "x^1 + y^1");
}

TEST(PolyTest, SumWith0) {
  Polynomial p1, p2;
  p1.add_monom(2, 1, 0, 0);
  p2.add_monom(-2, 1, 0, 0);
  EXPECT_EQ(getPrint(p1 + p2), "0");
}

TEST(PolyTest, Sub) {
  Polynomial p1, p2;
  p1.add_monom(5, 1, 0, 0);
  p2.add_monom(2, 1, 0, 0);
  EXPECT_EQ(getPrint(p1 - p2), "3x^1");
}

TEST(PolyTest, SubToZero) {
  Polynomial p1;
  p1.add_monom(1, 2, 2, 2);
  EXPECT_EQ(getPrint(p1 - p1), "0");
}

TEST(PolyTest, ScalarMult) {
  Polynomial p;
  p.add_monom(2, 1, 1, 1);
  EXPECT_EQ(getPrint(p * 4), "8x^1y^1z^1");
}

TEST(PolyTest, ScalarZero) {
  Polynomial p;
  p.add_monom(10, 5, 5, 5);
  EXPECT_EQ(getPrint(p * 0), "0");
}

TEST(PolyTest, PolyMult) {
  Polynomial p1, p2;
  p1.add_monom(2, 1, 0, 0);
  p2.add_monom(3, 0, 1, 0);
  EXPECT_EQ(getPrint(p1 * p2), "6x^1y^1");
}

TEST(PolyTest, PolyMult2) {
  Polynomial p1, p2;
  p1.add_monom(1, 1, 0, 0);
  p1.add_monom(1, 0, 0, 0);
  p2.add_monom(1, 1, 0, 0);
  p2.add_monom(-1, 0, 0, 0);
  EXPECT_EQ(getPrint(p1 * p2), "x^2 - 1");
}

TEST(PolyTest, MultDegree) {
  Polynomial p1, p2;
  p1.add_monom(1, 6, 0, 0);
  p2.add_monom(1, 5, 0, 0);
  EXPECT_EQ(getPrint(p1 * p2), "0");
}
TEST(PolyTest, CopyConstructor) {
  Polynomial p1;
  p1.add_monom(4, 2, 0, 0);
  Polynomial p2 = p1;
  EXPECT_EQ(getPrint(p2), "4x^2");
}

TEST(PolyTest, Assignment) {
  Polynomial p1, p2;
  p1.add_monom(7, 0, 3, 0);
  p2 = p1;
  EXPECT_EQ(getPrint(p2), "7y^3");
}

TEST(PolyTest, Independence) {
  Polynomial p1;
  p1.add_monom(1, 1, 0, 0);
  Polynomial p2 = p1;
  p2.add_monom(1, 1, 0, 0);
  EXPECT_NE(getPrint(p1), getPrint(p2));
}

TEST(PolyTest, PrintEmpty) {
  Polynomial p;
  EXPECT_EQ(getPrint(p), "0");
}