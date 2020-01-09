#include "circle.h"
#include <gtest.h>

TEST(Circle, file_is_empty)
{
  ASSERT_EQ(Finding_biggest_circle_without_intersections("empty.txt"), -1);
}

TEST(Circle, file_not_found)
{
  ASSERT_ANY_THROW(Finding_biggest_circle_without_intersections("no.txt"));
}

TEST(Circle, provided_input_data)
{
  ASSERT_EQ(Finding_biggest_circle_without_intersections("input.txt"), 7);
}
