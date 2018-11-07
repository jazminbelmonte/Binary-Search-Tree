#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <sstream>
#include "binary_search_tree.h"
using namespace std;

stringstream sout;
template <typename T> 
void showFUNC(const Node<T>* node, int depth){
  sout << "<" << node->info << ">";
}
#include "binary_search_tree.h"

TEST_CASE("Test Binary Search Tree Function") {
  BinarySearchTree<int> nums;
  CHECK(nums.height() == 0);
  CHECK(nums.size() == 0);
  CHECK(nums.leavesCount() == 0);
  CHECK(nums.minimum() == nullptr);
  CHECK(nums.maximum() == nullptr);
  nums.insert(10);
  nums.insert(17);
  nums.insert(6);
  nums.insert(17);
  nums.insert(9);
  nums.insert(7);
  nums.insert(8);
  nums.insert(14);
  CHECK(nums.search(17)->info == 17);
  CHECK(nums.search(18) == nullptr);

  CHECK(nums.height() == 5);
  CHECK(nums.size() == 7);
  CHECK(nums.leavesCount() == 2);
  CHECK(nums.level(10) == 0);
  CHECK(nums.level(7) == 3);
  CHECK(nums.minimum()->info == 6);
  CHECK(nums.maximum()->info == 17);

  nums.inorderTraversal(showFUNC);
  CHECK(sout.str() == "<6><7><8><9><10><14><17>");
  sout.str("");
  nums.preorderTraversal(showFUNC);
  CHECK(sout.str() == "<10><6><9><7><8><17><14>");

  Node<int>* array1;
  nums.toSortedArray(array1);
  
  CHECK(array1[0].info == 6);
  CHECK(array1[6].info == 17);

  Node<int>* array2;
  nums.toSortedArray(array2, true);
  CHECK(array2[0].info == 17);
  CHECK(array2[6].info == 6);
}