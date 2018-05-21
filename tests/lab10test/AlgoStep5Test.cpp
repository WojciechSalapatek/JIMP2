//
// Created by mwypych on 11.05.17.
//

#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <MemLeakTest.h>
#include <Algo.h>


using algo::DivisableBy;



class AlgoStep5 : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(AlgoStep5, DefineMethod_DivisableBy) {
  std::vector<int> arg {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  std::vector<int> exp1 {2,4,6,8,10,12,14,16};
  std::vector<int> exp2 {7,14};
  std::vector<int> exp3 {8,16};
  EXPECT_EQ(exp1, DivisableBy(arg,2));
  EXPECT_EQ(exp2, DivisableBy(arg,7));
  EXPECT_EQ(exp3, DivisableBy(arg,8));
}
