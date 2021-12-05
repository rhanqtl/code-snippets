#include <vector>
#include <numeric>

#include <gtest/gtest.h>

#include "linked_list_ownership.hpp"

// enum class Direction {
//   FORWARD,
//   BACKWARD,
// };

// static void __populate_forward(hq::LinkedList<int> &lst, const std::vector<int> &data) {

// }

// static void populate(hq::LinkedList<int> &lst, Direction dir, std::size_t len) {
//   std::vector<int> data(len);
//   std::iota(data.begin(), data.end(), 0);
//   if (dir == Direction::FORWARD) {

//   } else if (dir == Direction::BACKWARD) {

//   }
// }

TEST(LinkedListOwnershipTest, Constructor) {
  hq::LinkedList<int> lst;
}

TEST(LinkedListOwnershipTest, AddFirst) {
  hq::LinkedList<int> lst;
  std::vector<int> data(10);
  std::iota(data.begin(), data.end(), 0);
  for (auto e : data) {
    lst.add_first(e);
  }
}

TEST(LinkedListOwnershipTest, RemoveFirst) {
  hq::LinkedList<int> lst;
  std::vector<int> data(10);
  std::iota(data.begin(), data.end(), 0);
  for (auto e : data) {
    lst.add_first(e);
  }
  int v;
  for (auto it = data.crbegin(), ed = data.crend(); it != ed; it++) {
    ASSERT_TRUE(lst.remove_first(v));
    ASSERT_EQ(v, *it);
  }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}