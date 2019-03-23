#include "gtest/gtest.h"
#include "numToString.hpp"

class NumToStringTest : public ::testing::Test
{
public:
    utils::NumToString nts;
};


TEST_F(NumToStringTest, getZero)
{
    EXPECT_EQ("zero", nts.getWord(0));
}

TEST_F(NumToStringTest, getOne)
{
    EXPECT_EQ("one", nts.getWord(1));
}

TEST_F(NumToStringTest, getTen)
{
    EXPECT_EQ("ten", nts.getWord(10));
}

TEST_F(NumToStringTest, getFifteen)
{
    EXPECT_EQ("fifteen", nts.getWord(15));
}

TEST_F(NumToStringTest, getTwenty)
{
    EXPECT_EQ("twenty", nts.getWord(20));
}

TEST_F(NumToStringTest, getTwentyOne)
{
    EXPECT_EQ("twenty-one", nts.getWord(21));
}

TEST_F(NumToStringTest, get110)
{
    EXPECT_EQ("one hundred and ten", nts.getWord(110));
}

TEST_F(NumToStringTest, get385)
{
    EXPECT_EQ("three hundreds and eighty-five", nts.getWord(385));
}

TEST_F(NumToStringTest, get_13_385)
{
    EXPECT_EQ("thirteen thousands three hundreds and eighty-five", nts.getWord(13385));
}

TEST_F(NumToStringTest, get_1_234_567)
{
    EXPECT_EQ("one million two hundreds and thirty-four thousands five hundreds and sixty-seven", nts.getWord(1234567));
}

TEST_F(NumToStringTest, get_17_000_000)
{
    EXPECT_EQ("seventeen millions", nts.getWord(17000000));
}

TEST_F(NumToStringTest, get_10_000_000)
{
    EXPECT_EQ("ten millions", nts.getWord(10000000));
}

TEST_F(NumToStringTest, get_10_000_001)
{
    EXPECT_EQ("ten millions one", nts.getWord(10000001));
}

TEST_F(NumToStringTest, get_min1)
{
   EXPECT_EQ("Wrong input", nts.getWord(-1));
}

