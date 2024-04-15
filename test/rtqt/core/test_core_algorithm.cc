/**
 * @file test_core_algorithm.cc
 * @author TONBUL, Muhammet
*/

#include <gmock/gmock.h>

#include <rtqt/core/core_algorithm.h>
#include <rtqt/core/core_vector.h>

using namespace rtqt;
using namespace testing;

TEST(test_core_algorithm, core_algorithm_minimum_element_vector)
{
  core_vector<int> __v;

  __v.push_back(50);
  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(40);
  __v.push_back(30);

  auto __result = core_minimum_element(__v.begin(), __v.end());

  EXPECT_EQ(*__result, 10);
}

int
main(int argc, char **argv)
{
  InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}