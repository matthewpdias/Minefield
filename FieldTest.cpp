/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, outOfBounds)
{
  Field minefield;
  ASSERT_ANY_THROW(minefield.get(11,11));
}

TEST(FieldTest, unsafe)
{
  Field minefield;
  minefield.placeMine(4,5);
  ASSERT_EQ(false, minefield.isSafe(4,5));
}

TEST(FieldTest, safe)
{
  Field minefield;
  minefield.placeMine(4,5);
  ASSERT_EQ(EMPTY_HIDDEN, minefield.get(4,4));
}

TEST(FieldTest, revealed)
{
  Field minefield;
  minefield.placeMine(1,1);
  minefield.revealAdjacent(2,1);
  ASSERT_EQ(EMPTY_SHOWN, minefield.get(2,1));
}
