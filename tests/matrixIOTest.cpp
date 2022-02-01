#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <iostream>

#include "matrixIO.hpp"

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expectedA = MatrixXd(3, 3);
    expectedA << 0.680375, 0.59688, -0.329554,
                 -0.211234, 0.823295, 0.536459,
                 0.566198, -0.604897, -0.444451;
  }
  MatrixXd expectedA;
};

BOOST_FIXTURE_TEST_SUITE(OpenDataTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(m3)
{
  MatrixXd A = matrixIO::openData("../data/m3.csv", 3);
  BOOST_TEST(expectedMatrix.isApprox(A));
};

BOOST_AUTO_TEST_SUITE_END()
