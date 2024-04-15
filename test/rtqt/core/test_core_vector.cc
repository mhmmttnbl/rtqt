/**
 * @file test_core_vector.cc
 * @author TONBUL, Muhammet
*/

#include <gmock/gmock.h>

#include <rtqt/core/core_vector.h>

using namespace rtqt;
using namespace testing;

TEST(test_core_vector, core_vector_ctor_default_initialization)
{
  core_vector<int> __v(5);

  for (auto __el : __v) {
    EXPECT_TRUE(__el == 0);
  }
}

TEST(test_core_vector, core_vector_ctor_value_initialization)
{
  core_vector<int> __v(5, 15);

  for (auto __el : __v) {
    EXPECT_TRUE(__el == 15);
  }
}

TEST(test_core_vector, core_vector_copy_ctor)
{
  core_vector<int> __v_x;

  __v_x.push_back(10);
  __v_x.push_back(20);
  __v_x.push_back(30);
  __v_x.push_back(40);
  __v_x.push_back(50);

  core_vector<int> __v_y(__v_x);

  EXPECT_TRUE(__v_x == __v_y);
}

TEST(test_core_vector, core_vector_pop_back)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  __v.pop_back();

  auto __it = __v.end() - 1;

  EXPECT_TRUE(*__it == 40);
}

TEST(test_core_vector, core_vector_operator_subscription)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto &__el = __v[3];

  EXPECT_TRUE(__el == 40);
}

TEST(test_core_vector, core_vector_operator_subscription_const)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  const core_vector<int> __c(__v);

  auto &__el = __c[3];

  EXPECT_TRUE(__el == 40);
}

TEST(test_core_vector, core_vector_front)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto &__el = __v.front();

  EXPECT_TRUE(__el == 10);
}

TEST(test_core_vector, core_vector_front_const)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  const core_vector<int> __c(__v);

  auto &__el = __c.front();

  EXPECT_TRUE(__el == 10);
}

TEST(test_core_vector, core_vector_back)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto &__el = __v.back();

  EXPECT_TRUE(__el == 50);
}

TEST(test_core_vector, core_vector_back_const)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  const core_vector<int> __c(__v);

  auto &__el = __c.back();

  EXPECT_TRUE(__el == 50);
}

TEST(test_core_vector, core_vector_begin)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto __it = __v.begin();

  EXPECT_TRUE(*__it == 10);
}

TEST(test_core_vector, core_vector_begin_const)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto __it = __v.cbegin();

  EXPECT_TRUE(*__it == 10);
}

TEST(test_core_vector, core_vector_end)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto __it = __v.end() - 1;

  EXPECT_TRUE(*__it == 50);
}

TEST(test_core_vector, core_vector_end_const)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto __it = __v.cend() - 1;

  EXPECT_TRUE(*__it == 50);
}

TEST(test_core_vector, core_vector_size)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  EXPECT_TRUE(__v.size() == 5);
}

TEST(test_core_vector, core_vector_empty_true)
{
  core_vector<int> __v;

  EXPECT_TRUE(__v.empty());
}

TEST(test_core_vector, core_vector_empty_false)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  EXPECT_FALSE(__v.empty());
}

TEST(test_core_vector, core_vector_erase_iterator)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto __it = __v.erase(__v.begin());

  EXPECT_TRUE(*__it == 20);
}

TEST(test_core_vector, core_vector_erase_const_iterator)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto __it = __v.erase(__v.cbegin());

  EXPECT_TRUE(*__it == 20);
}

TEST(test_core_vector, core_vector_erase_iterator_range)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto __it = __v.erase(__v.begin(), __v.begin() + 2);

  EXPECT_TRUE(*__it == 30);
}

TEST(test_core_vector, core_vector_erase_const_iterator_range)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(30);
  __v.push_back(40);
  __v.push_back(50);

  auto __it = __v.erase(__v.cbegin(), __v.cbegin() + 2);

  EXPECT_TRUE(*__it == 30);
}

TEST(test_core_vector, core_vector_insert)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(40);
  __v.push_back(50);

  __v.insert(__v.begin() + 3, 30);

  EXPECT_TRUE(__v[3] == 30);
}

TEST(test_core_vector, core_vector_emplace)
{
  core_vector<int> __v;

  __v.push_back(10);
  __v.push_back(20);
  __v.push_back(40);
  __v.push_back(50);

  __v.emplace(__v.begin() + 3, 30);

  EXPECT_TRUE(__v[3] == 30);
}

TEST(test_core_vector, core_vector_emplace_back)
{
  core_vector<int> __v;

  __v.emplace_back(10);
  __v.emplace_back(20);
  __v.emplace_back(30);
  __v.emplace_back(40);
  __v.emplace_back(50);

  for (int __i = 1; __i <= 5; ++__i) {
    EXPECT_TRUE(__v[__i - 1] == __i * 10);
  }
}

TEST(test_core_vector, core_vector_reserve)
{
  core_vector<int> __v;

  __v.reserve(10);

  EXPECT_TRUE(__v.empty());
  EXPECT_TRUE(__v.size() == 0);
  EXPECT_TRUE(__v.capacity() == 10);
}

TEST(test_core_vector, core_vector_equal)
{
  core_vector<int> __v_x;
  __v_x.push_back(10);
  __v_x.push_back(20);
  __v_x.push_back(30);
  __v_x.push_back(40);
  __v_x.push_back(50);

  core_vector<int> __v_y;
  __v_y.push_back(10);
  __v_y.push_back(20);
  __v_y.push_back(30);
  __v_y.push_back(40);
  __v_y.push_back(50);

  EXPECT_TRUE(__v_x == __v_y);
}

TEST(test_core_vector, core_vector_not_equal)
{
  core_vector<int> __v_x;
  __v_x.push_back(1);
  __v_x.push_back(2);
  __v_x.push_back(3);
  __v_x.push_back(4);
  __v_x.push_back(5);

  core_vector<int> __v_y;
  __v_y.push_back(10);
  __v_y.push_back(20);
  __v_y.push_back(30);
  __v_y.push_back(40);
  __v_y.push_back(50);

  EXPECT_TRUE(__v_x != __v_y);
}

TEST(test_core_vector, core_vector_less_than)
{
  core_vector<int> __v_x;
  __v_x.push_back(1);
  __v_x.push_back(2);
  __v_x.push_back(3);
  __v_x.push_back(4);
  __v_x.push_back(5);

  core_vector<int> __v_y;
  __v_y.push_back(10);
  __v_y.push_back(20);
  __v_y.push_back(30);
  __v_y.push_back(40);
  __v_y.push_back(50);

  EXPECT_TRUE(__v_x < __v_y);
}

TEST(test_core_vector, core_vector_less_than_or_equal)
{
  core_vector<int> __v_x;
  __v_x.push_back(1);
  __v_x.push_back(2);
  __v_x.push_back(3);
  __v_x.push_back(4);
  __v_x.push_back(5);

  core_vector<int> __v_y;
  __v_y.push_back(10);
  __v_y.push_back(20);
  __v_y.push_back(30);
  __v_y.push_back(40);
  __v_y.push_back(50);

  EXPECT_TRUE(__v_x <= __v_y);
}

TEST(test_core_vector, core_vector_greater_than)
{
  core_vector<int> __v_x;
  __v_x.push_back(1);
  __v_x.push_back(2);
  __v_x.push_back(3);
  __v_x.push_back(4);
  __v_x.push_back(5);

  core_vector<int> __v_y;
  __v_y.push_back(10);
  __v_y.push_back(20);
  __v_y.push_back(30);
  __v_y.push_back(40);
  __v_y.push_back(50);

  EXPECT_TRUE(__v_y > __v_x);
}

TEST(test_core_vector, core_vector_greater_than_or_equal)
{
  core_vector<int> __v_x;
  __v_x.push_back(1);
  __v_x.push_back(2);
  __v_x.push_back(3);
  __v_x.push_back(4);
  __v_x.push_back(5);

  core_vector<int> __v_y;
  __v_y.push_back(10);
  __v_y.push_back(20);
  __v_y.push_back(30);
  __v_y.push_back(40);
  __v_y.push_back(50);

  EXPECT_TRUE(__v_y >= __v_x);
}

int
main(int argc, char **argv)
{
  InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}