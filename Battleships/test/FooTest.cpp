#include "gtest/gtest.h"
#include "Board.h"
#include <iostream>
using namespace std;
namespace {
  class Board2Test : public ::testing::Test {
  protected:
    Board board;
  };

  TEST_F(Board2Test, ConstructorTest) {
    ASSERT_EQ( 0, board.nullReturn());
  }

}
