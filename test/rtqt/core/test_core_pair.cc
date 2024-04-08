/**
 * @file test_core_pair.cc
 * @author TONBUL, Muhammet
*/

#include <gmock/gmock.h>

#include <rtqt/core/core_pair.h>

using namespace rtqt;
using namespace testing;

TEST(test_core_pair, core_pair_default_ctor)
{
  core_pair<int, int> __pair;

  EXPECT_TRUE(__pair.first == 0);
  EXPECT_TRUE(__pair.second == 0);
}

TEST(test_core_pair, core_pair_ctor_with_two_args)
{
  core_pair<int, int> __pair(1, 2);

  EXPECT_TRUE(__pair.first == 1);
  EXPECT_TRUE(__pair.second == 2);
}

TEST(test_core_pair, core_pair_equal)
{
  core_pair<int, int> __pair_x(1, 2);
  core_pair<int, int> __pair_y(1, 2);

  EXPECT_TRUE(__pair_x == __pair_y);
}

TEST(test_core_pair, core_pair_not_equal)
{
  core_pair<int, int> __pair_x(1, 2);
  core_pair<int, int> __pair_y(10, 20);

  EXPECT_TRUE(__pair_x != __pair_y);
}

TEST(test_core_pair, core_pair_less_than)
{
  core_pair<int, int> __pair_x(1, 2);
  core_pair<int, int> __pair_y(10, 20);

  EXPECT_TRUE(__pair_x < __pair_y);
}

TEST(test_core_pair, core_pair_less_than_or_equal)
{
  core_pair<int, int> __pair_x(1, 2);
  core_pair<int, int> __pair_y(1, 2);

  EXPECT_TRUE(__pair_x <= __pair_y);
}

TEST(test_core_pair, core_pair_greater_than)
{
  core_pair<int, int> __pair_x(1, 2);
  core_pair<int, int> __pair_y(10, 20);

  EXPECT_TRUE(__pair_y > __pair_x);
}

TEST(test_core_pair, core_pair_greater_than_or_equal)
{
  core_pair<int, int> __pair_x(1, 2);
  core_pair<int, int> __pair_y(1, 2);

  EXPECT_TRUE(__pair_y >= __pair_x);
}

int
main(int argc, char **argv)
{
  InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}