/**
 * @file test_core_functional.cc
 * @author TONBUL, Muhammet
*/

#include <gmock/gmock.h>

#include <rtqt/core/core_functional.h>
#include <rtqt/core/core_pair.h>

using namespace rtqt;
using namespace testing;

TEST(test_core_function, core_function_less_true)
{
  int __x = 1;
  int __y = 2;
  
  bool __result = core_less<int>()(__x, __y);

  EXPECT_TRUE(__result);
}

TEST(test_core_function, core_function_less_false)
{
  int __x = 10;
  int __y = 2;
  
  bool __result = core_less<int>()(__x, __y);

  EXPECT_FALSE(__result);
}

TEST(test_core_function, core_function_less_true_pointer)
{
  int *__x = reinterpret_cast<int*>(0x100);
  int *__y = reinterpret_cast<int*>(0x200);
  
  bool __result = core_less<int*>()(__x, __y);

  EXPECT_TRUE(__result);
}

TEST(test_core_function, core_function_less_false_pointer)
{
  int *__x = reinterpret_cast<int*>(0x200);
  int *__y = reinterpret_cast<int*>(0x100);
  
  bool __result = core_less<int*>()(__x, __y);

  EXPECT_FALSE(__result);
}

TEST(test_core_function, core_function_greater_true)
{
  int __x = 10;
  int __y = 2;
  
  bool __result = core_greater<int>()(__x, __y);

  EXPECT_TRUE(__result);
}

TEST(test_core_function, core_function_greater_false)
{
  int __x = 1;
  int __y = 20;
  
  bool __result = core_greater<int>()(__x, __y);

  EXPECT_FALSE(__result);
}

TEST(test_core_function, core_function_greater_true_pointer)
{
  int *__x = reinterpret_cast<int*>(0x200);
  int *__y = reinterpret_cast<int*>(0x100);
  
  bool __result = core_greater<int*>()(__x, __y);

  EXPECT_TRUE(__result);
}

TEST(test_core_function, core_function_greater_false_pointer)
{
  int *__x = reinterpret_cast<int*>(0x100);
  int *__y = reinterpret_cast<int*>(0x200);
  
  bool __result = core_greater<int*>()(__x, __y);

  EXPECT_FALSE(__result);
}

TEST(test_core_function, core_function_use_self)
{
  int __x = 3;

  auto __result = core_identity<int>()(__x);

  EXPECT_EQ(__result, __x);
}

TEST(test_core_function, core_function_select1st)
{
  core_pair<int, int> __pair(1, 2);

  auto __result = core_select1st<core_pair<int, int>>()(__pair);

  EXPECT_EQ(__result, __pair.first);
}

TEST(test_core_function, core_function_select2nd)
{
  core_pair<int, int> __pair(1, 2);

  auto __result = core_select2nd<core_pair<int, int>>()(__pair);

  EXPECT_EQ(__result, __pair.second);
}

int
main(int argc, char **argv)
{
  InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}