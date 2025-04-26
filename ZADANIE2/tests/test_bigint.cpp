// tests/test_bigint.cpp – intensywne testy Google Test dla klasy BigInt
#include "../bigint.h"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

/* konwersja BigInt → std::string */
static std::string to_str(const BigInt& x)
{
    std::ostringstream os; os << x; return os.str();
}

/*-----------------------------------------------------------------*/
/* PODSTAWOWA POPRAWNOŚĆ                                           */
/*-----------------------------------------------------------------*/
TEST(BigIntBasics, KonstruktorIZerowanie)
{
    EXPECT_EQ(to_str(BigInt()),            "0");
    EXPECT_EQ(to_str(BigInt("000")),      "0");
    EXPECT_EQ(to_str(BigInt("-0000")),    "0");
    EXPECT_EQ(to_str(BigInt("+42")),      "42");
}

TEST(BigIntBasics, UnaryOperators)
{
    BigInt a("-123");
    EXPECT_EQ(to_str(+a), "-123");
    EXPECT_EQ(to_str(-a),  "123");
    EXPECT_EQ(to_str(-(-a)), "-123");
}

/*-----------------------------------------------------------------*/
/* MAŁE LICZBY                                                     */
/*-----------------------------------------------------------------*/
TEST(BigIntSmall, AddSubPositive)
{
    BigInt a("37"), b("5");
    EXPECT_EQ(to_str(a + b), "42");
    EXPECT_EQ(to_str(b + a), "42");
    EXPECT_EQ(to_str(a - b), "32");
    EXPECT_EQ(to_str(b - a), "-32");
}

TEST(BigIntSmall, AddWithNegative)
{
    BigInt a("100"), b("-30");
    EXPECT_EQ(to_str(a + b),  "70");
    EXPECT_EQ(to_str(b + a),  "70");
    EXPECT_EQ(to_str(a - b), "130");
    EXPECT_EQ(to_str(b - a), "-130");
}

/*-----------------------------------------------------------------*/
/* DUŻE WARTOŚCI                                                   */
/*-----------------------------------------------------------------*/
TEST(BigIntLarge, HugeAddition)
{
    std::string s1(200, '9');        // 999… (200 razy)
    std::string s2(200, '1');        // 111… (200 razy)
    BigInt a(s1), b(s2);

    BigInt c = a + b;

    // wynik powinien mieć 201 cyfr: 200 razy '1' + końcowe '0'
    std::string expected(200, '1');
    expected.push_back('0');
    EXPECT_EQ(to_str(c), expected);
}

TEST(BigIntLarge, MixedSigns)
{
    BigInt a("1000000000000000000000000");   // 1e24
    BigInt b("-999999999999999999999999");   // -9.999e23
    EXPECT_EQ(to_str(a + b), "1");
    EXPECT_EQ(to_str(b + a), "1");
}

/*-----------------------------------------------------------------*/
/* WŁASNOŚCI ALGEBRAICZNE                                          */
/*-----------------------------------------------------------------*/
TEST(BigIntProperties, Commutativity)
{
    BigInt x("123456789"), y("-87654321");
    EXPECT_EQ(to_str(x + y), to_str(y + x));
}

TEST(BigIntProperties, AdditiveInverse)
{
    BigInt x("987654321");
    EXPECT_EQ(to_str(x + (-x)), "0");
    EXPECT_EQ(to_str((-x) + x), "0");
}

TEST(BigIntProperties, SubIsAddOfOpposite)
{
    BigInt p("777"), q("1234");
    EXPECT_EQ(to_str(p - q), to_str(p + (-q)));
    EXPECT_EQ(to_str(q - p), to_str(q + (-p)));
}
