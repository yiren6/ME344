// Modified from Solution Adaptive Numerical Simulator (SANS)
// Copyright 2013-2022, Massachusetts Institute of Technology
// Licensed under The GNU Lesser General Public License, version 2.1
// See http://www.opensource.org/licenses/lgpl-2.1.php

//----------------------------------------------------------------------------//
// SurrealS4_btest
// testing of SurrealS<4> class

#include "Surreal/SurrealS.h"

#include <ostream>
#include <vector>
using namespace std;

#define Real                        double
#define BOOST_CHECK                 assert
#define BOOST_CHECK_EQUAL(A,B)      assert((A) == (B))
#define BOOST_AUTO_TEST_CASE( fun ) void fun()


// Explicitly instantiate the class to generate all the functions so that coverage
// information is correct
template class SurrealS<4>;


//############################################################################//
// BOOST_AUTO_TEST_SUITE( SurrealS4_test_suite )


typedef SurrealS<4> SurrealS4;


//----------------------------------------------------------------------------//
bool
chkSurrealS4( const SurrealS4& z, Real v, Real d0, Real d1, Real d2, Real d3 )
{
  bool isEqual = true;
  if ((z.value() != v) || (z.deriv(0) != d0) || (z.deriv(1) != d1) || (z.deriv(2) != d2) || (z.deriv(3) != d3))
  {
    isEqual = false;
    cout << "actual (" << z << ")  "
         << "expected ((" << v << ";" << d0 << "," << d1 << "," << d2 << "," << d3 << "))  "
         << "diff ((" << v - z.value()
         << ";" << d0 - z.deriv(0) << "," << d1 - z.deriv(1)
         << "," << d2 - z.deriv(2) << "," << d3 - z.deriv(3) << "))" << endl;
  }
#if 0
  else
  {
    cout << "(" << z << ")" << endl;
  }
#endif
  return isEqual;
}

bool
chkSurrealS4( const SurrealS<4, SurrealS4>& z, Real v, Real d0, Real d1, Real d2, Real d3,
                                                       vector<Real> dd0, vector<Real> dd1, vector<Real> dd2, vector<Real> dd3 )
{
  bool isEqual = true;
  if ((z.value() != v) ||
      (z.deriv(0).value() != d0) || (z.deriv(0).deriv(0) != dd0[0]) || (z.deriv(0).deriv(1) != dd0[1]) ||
                                    (z.deriv(0).deriv(2) != dd0[2]) || (z.deriv(0).deriv(3) != dd0[3]) ||
      (z.deriv(1).value() != d1) || (z.deriv(1).deriv(0) != dd1[0]) || (z.deriv(1).deriv(1) != dd1[1]) ||
                                    (z.deriv(1).deriv(2) != dd1[2]) || (z.deriv(1).deriv(3) != dd1[3]) ||
      (z.deriv(2).value() != d2) || (z.deriv(2).deriv(0) != dd2[0]) || (z.deriv(2).deriv(1) != dd2[1]) ||
                                    (z.deriv(2).deriv(2) != dd2[2]) || (z.deriv(2).deriv(3) != dd2[3]) ||
      (z.deriv(3).value() != d3) || (z.deriv(3).deriv(0) != dd3[0]) || (z.deriv(3).deriv(1) != dd3[1]) ||
                                    (z.deriv(3).deriv(2) != dd3[2]) || (z.deriv(3).deriv(3) != dd3[3]) )
  {
    isEqual = false;
    cout << "actual (" << z << ")  " << endl;
    cout << "expected ((" << v << ";(" << d0 << ";" << dd0[0] << "," << dd0[1] << "," << dd0[2] << "," << dd0[3] << ")"
                               << ",(" << d1 << ";" << dd1[0] << "," << dd1[1] << "," << dd1[2] << "," << dd1[3] << ")"
                               << ",(" << d2 << ";" << dd2[0 - z.deriv(1).deriv(0)] << "," << dd2[1] << "," << dd2[2] << "," << dd2[3] << ")"
                               << ",(" << d3 << ";" << dd3[0] << "," << dd3[1] << "," << dd3[2] << "," << dd3[3] << "))  " << endl;
    cout << "diff ((" << v - z.value().value()
         << ";(" << d0 - z.deriv(0).value() << ";" << dd0[0] - z.deriv(0).deriv(0) << "," << dd0[1] - z.deriv(0).deriv(1) << ","
                                                   << dd0[2] - z.deriv(0).deriv(2) << "," << dd0[3] - z.deriv(0).deriv(3) << ")"
         << ",(" << d1 - z.deriv(1).value() << ";" << dd1[0] - z.deriv(1).deriv(0) << "," << dd1[1] - z.deriv(1).deriv(1) << ","
                                                   << dd1[2] - z.deriv(1).deriv(2) << "," << dd1[3] - z.deriv(1).deriv(3) << ")"
         << ",(" << d2 - z.deriv(2).value() << ";" << dd2[0] - z.deriv(2).deriv(0) << "," << dd2[1] - z.deriv(2).deriv(1) << ","
                                                   << dd2[2] - z.deriv(2).deriv(2) << "," << dd2[3] - z.deriv(2).deriv(3) << ")"
         << ",(" << d3 - z.deriv(3).value() << ";" << dd3[0] - z.deriv(3).deriv(0) << "," << dd3[1] - z.deriv(3).deriv(1) << ","
                                                   << dd3[2] - z.deriv(3).deriv(2) << "," << dd3[3] - z.deriv(3).deriv(3) << "))  " << endl;
  }
#if 0
  else
  {
    cout << "(" << z << ")" << endl;
  }
#endif
  return isEqual;
}

bool
chkSurrealS4( const SurrealS4& z, Real v, Real d0, Real d1, Real d2, Real d3, Real tol )
{
  bool isEqual = true;
  if ((abs(z.value() - v) > tol) ||
      (abs(z.deriv(0) - d0) > tol) ||
      (abs(z.deriv(1) - d1) > tol) ||
      (abs(z.deriv(2) - d2) > tol) ||
      (abs(z.deriv(3) - d3) > tol))
  {
    isEqual = false;
    cout << "actual (" << z << ")  "
         << "expected ((" << v << ";" << d0 << "," << d1 << "," << d2 << "," << d3 << "))  "
         << "diff ((" << v - z.value()
         << ";" << d0 - z.deriv(0) << "," << d1 - z.deriv(1)
         << "," << d2 - z.deriv(2) << "," << d3 - z.deriv(3) << "))" << endl;
  }
#if 0
  else
  {
    cout << "(" << z << ")" << endl;
  }
#endif
  return isEqual;
}


bool
chkSurrealS4( const SurrealS<4, SurrealS4>& z, Real v, Real d0, Real d1, Real d2, Real d3,
                                                       vector<Real> dd0, vector<Real> dd1, vector<Real> dd2, vector<Real> dd3, Real tol )
{
  bool isEqual = true;
  if ((abs(z.value() - v) > tol) ||
      (abs(z.deriv(0).value() - d0) > tol) || (abs(z.deriv(0).deriv(0) - dd0[0]) > tol) || (abs(z.deriv(0).deriv(1) - dd0[1]) > tol) ||
                                              (abs(z.deriv(0).deriv(2) - dd0[2]) > tol) || (abs(z.deriv(0).deriv(3) - dd0[3]) > tol) ||
      (abs(z.deriv(1).value() - d1) > tol) || (abs(z.deriv(1).deriv(0) - dd1[0]) > tol) || (abs(z.deriv(1).deriv(1) - dd1[1]) > tol) ||
                                              (abs(z.deriv(1).deriv(2) - dd1[2]) > tol) || (abs(z.deriv(1).deriv(3) - dd1[3]) > tol) ||
      (abs(z.deriv(2).value() - d2) > tol) || (abs(z.deriv(2).deriv(0) - dd2[0]) > tol) || (abs(z.deriv(2).deriv(1) - dd2[1]) > tol) ||
                                              (abs(z.deriv(2).deriv(2) - dd2[2]) > tol) || (abs(z.deriv(2).deriv(3) - dd2[3]) > tol) ||
      (abs(z.deriv(3).value() - d3) > tol) || (abs(z.deriv(3).deriv(0) - dd3[0]) > tol) || (abs(z.deriv(3).deriv(1) - dd3[1]) > tol) ||
                                              (abs(z.deriv(3).deriv(2) - dd3[2]) > tol) || (abs(z.deriv(3).deriv(3) - dd3[3]) > tol) )
  {
    isEqual = false;
    cout << "actual (" << z << ")  " << endl;
    cout << "expected ((" << v << ";(" << d0 << ";" << dd0[0] << "," << dd0[1] << "," << dd0[2] << "," << dd0[3] << ")"
                               << ",(" << d1 << ";" << dd1[0] << "," << dd1[1] << "," << dd1[2] << "," << dd1[3] << ")"
                               << ",(" << d2 << ";" << dd2[0] << "," << dd2[1] << "," << dd2[2] << "," << dd2[3] << ")"
                               << ",(" << d3 << ";" << dd3[0] << "," << dd3[1] << "," << dd3[2] << "," << dd3[3] << "))  " << endl;
    cout << "diff ((" << v - z.value().value()
         << ";(" << d0 - z.deriv(0).value() << ";" << dd0[0] - z.deriv(0).deriv(0) << "," << dd0[1] - z.deriv(0).deriv(1) << ","
                                                   << dd0[2] - z.deriv(0).deriv(2) << "," << dd0[3] - z.deriv(0).deriv(3) << ")"
         << ",(" << d1 - z.deriv(1).value() << ";" << dd1[0] - z.deriv(1).deriv(0) << "," << dd1[1] - z.deriv(1).deriv(1) << ","
                                                   << dd1[2] - z.deriv(1).deriv(2) << "," << dd1[3] - z.deriv(1).deriv(3) << ")"
         << ",(" << d2 - z.deriv(2).value() << ";" << dd2[0] - z.deriv(2).deriv(0) << "," << dd2[1] - z.deriv(2).deriv(1) << ","
                                                   << dd2[2] - z.deriv(2).deriv(2) << "," << dd2[3] - z.deriv(2).deriv(3) << ")"
         << ",(" << d3 - z.deriv(3).value() << ";" << dd3[0] - z.deriv(3).deriv(0) << "," << dd3[1] - z.deriv(3).deriv(1) << ","
                                                   << dd3[2] - z.deriv(3).deriv(2) << "," << dd3[3] - z.deriv(3).deriv(3) << "))  " << endl;
  }
#if 0
  else
  {
    cout << "(" << z << ")" << endl;
  }
#endif
  return isEqual;
}

//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( ctors_access )
{
  Real d[4] = {1, 2, 3, 4};
  SurrealS4 v0(4, d, 4);
  SurrealS4 v1(1, 2);
  SurrealS4 v2(v1);
  SurrealS4 v3 = v1;
  SurrealS4 v4 = 1;
  SurrealS4 v5;

  // size
  BOOST_CHECK_EQUAL( 4, v0.size() );
  BOOST_CHECK_EQUAL( 4, v1.size() );
  BOOST_CHECK_EQUAL( 4, v2.size() );
  BOOST_CHECK_EQUAL( 4, v3.size() );
  BOOST_CHECK_EQUAL( 4, v4.size() );
  BOOST_CHECK_EQUAL( 4, v5.size() );

  // accessors
  BOOST_CHECK_EQUAL( 4, v0.value() );
  BOOST_CHECK_EQUAL( 1, v0.deriv() );
  BOOST_CHECK_EQUAL( 1, v0.deriv(0) );
  BOOST_CHECK_EQUAL( 2, v0.deriv(1) );
  BOOST_CHECK_EQUAL( 3, v0.deriv(2) );
  BOOST_CHECK_EQUAL( 4, v0.deriv(3) );

  BOOST_CHECK_EQUAL( 1, v1.value() );
  BOOST_CHECK_EQUAL( 2, v1.deriv(0) );
  BOOST_CHECK_EQUAL( 2, v1.deriv(1) );
  BOOST_CHECK_EQUAL( 2, v1.deriv(2) );
  BOOST_CHECK_EQUAL( 2, v1.deriv(3) );

  BOOST_CHECK_EQUAL( 1, v2.value() );
  BOOST_CHECK_EQUAL( 2, v2.deriv(0) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(1) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(2) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(3) );

  BOOST_CHECK_EQUAL( 1, v3.value() );
  BOOST_CHECK_EQUAL( 2, v3.deriv(0) );
  BOOST_CHECK_EQUAL( 2, v3.deriv(1) );
  BOOST_CHECK_EQUAL( 2, v3.deriv(2) );
  BOOST_CHECK_EQUAL( 2, v3.deriv(3) );

  BOOST_CHECK_EQUAL( 1, v4.value() );
  BOOST_CHECK_EQUAL( 0, v4.deriv(0) );
  BOOST_CHECK_EQUAL( 0, v4.deriv(1) );
  BOOST_CHECK_EQUAL( 0, v4.deriv(2) );
  BOOST_CHECK_EQUAL( 0, v4.deriv(3) );

//  BOOST_CHECK_EQUAL( 0, v5.value() );
//  BOOST_CHECK_EQUAL( 0, v5.deriv(0) );
//  BOOST_CHECK_EQUAL( 0, v5.deriv(1) );
//  BOOST_CHECK_EQUAL( 0, v5.deriv(2) );
//  BOOST_CHECK_EQUAL( 0, v5.deriv(3) );

  v2.value() = 3;
  BOOST_CHECK_EQUAL( 3, v2.value() );
  BOOST_CHECK_EQUAL( 2, v2.deriv(0) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(1) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(2) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(3) );
  v2.deriv() = 5;
  BOOST_CHECK_EQUAL( 3, v2.value() );
  BOOST_CHECK_EQUAL( 5, v2.deriv(0) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(1) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(2) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(3) );
  v2.deriv(0) = 1;
  BOOST_CHECK_EQUAL( 3, v2.value() );
  BOOST_CHECK_EQUAL( 1, v2.deriv(0) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(1) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(2) );
  BOOST_CHECK_EQUAL( 2, v2.deriv(3) );

  SurrealS4 v7(Real(4), Real(2));
  BOOST_CHECK_EQUAL( 4, v7.value() );
  BOOST_CHECK_EQUAL( 2, v7.deriv(0) );
  BOOST_CHECK_EQUAL( 2, v7.deriv(1) );
  BOOST_CHECK_EQUAL( 2, v7.deriv(2) );
  BOOST_CHECK_EQUAL( 2, v7.deriv(3) );
}


//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( assign_unary_accum )
{
  Real d[4] = {1, 2, 3, 4};
  SurrealS4 v1(1, d, 4);
  SurrealS4 v2(1, 0);
  SurrealS4 v3(v1);
  SurrealS4 v4, v5;

  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, 1, 2, 3, 4 ) );
//  BOOST_CHECK( chkSurrealS4( v4,  0, 0, 0, 0, 0 ) );
//  BOOST_CHECK( chkSurrealS4( v5,  0, 0, 0, 0, 0 ) );

  // assignment
  v3 = 2;
  BOOST_CHECK( chkSurrealS4( v3,  2, 0, 0, 0, 0 ) );

  v3 = v2;
  BOOST_CHECK( chkSurrealS4( v2,  1, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, 0, 0, 0, 0 ) );

  v3 = v2 = 2;
  BOOST_CHECK( chkSurrealS4( v2,  2, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2, 0, 0, 0, 0 ) );

  v3 = v2 = v1;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, 1, 2, 3, 4 ) );

  // unary
  v3 = +v2;
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, 1, 2, 3, 4 ) );

  v3 = -v2;
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, -1, -1, -2, -3, -4 ) );

  // binary accumulation
  v4 = v3 = v2 = v1;
  v5 = 4*v1;
  v2 += 3;
  v3 -= 3;
  v4 *= 3;
  v5 /= 2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  4, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, -2, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v4,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v5,  2, 2, 4, 6, 8 ) );

  v4 = v3 = v2 = v1;
  v5 = 4*v1;
  v2 += Real(3);
  v3 -= Real(3);
  v4 *= Real(3);
  v5 /= Real(2);
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  4, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, -2, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v4,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v5,  2, 2, 4, 6, 8 ) );

  v4 = v3 = v2 = v1;
  v5 = 4*v1;
  v2 += v1;
  v3 -= v1;
  v4 *= v1;
  v5 /= v1;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  0, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  1, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v5,  4, 0, 0, 0, 0 ) );
}


//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( addsubtract )
{
  Real d[4] = {1, 2, 3, 4};
  SurrealS4 v1(1, d, 4);
  SurrealS4 v2(v1), v3(v1), v4(v1), v5(v1);

  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v4,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v5,  1, 1, 2, 3, 4 ) );

  // binary +/- operators

  SurrealS4 v8 = v1 + v2;
  BOOST_CHECK_EQUAL( 4, v8.size() );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v8,  2, 2, 4, 6, 8 ) );

  v2 = v1;
  v3 = v1 + v2;
  v4 = v1 + v2 + v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );

  v3 = v1 - v2;
  v4 = v1 - v2 - v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  0, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  0, 0, 0, 0, 0 ) );

  v3 = 3;
  v4 = v1 + v2 - v3;
  v5 = v1 - v2 + v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v4, -1, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v5,  3, 0, 0, 0, 0 ) );

  v4 = v3 = v2 = v1;
  v2 += v1;
  v3 += v1 + v2;
  v4 += v1 + v2 + v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4, 4, 8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v4,  8, 8, 16, 24, 32 ) );

  v4 = v3 = v2 = v1;
  v2 -= v1;
  v3 -= v1 - v2;
  v4 -= v1 - v2 - v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  0, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  0, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  0, 0, 0, 0, 0 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = 4*v1;
  v5 = (v1 + v2) + (v3 + v4);
  BOOST_CHECK( chkSurrealS4( v5,  10, 10, 20, 30, 40 ) );
  v5 = (v1 + v2) + (v3 - v4);
  BOOST_CHECK( chkSurrealS4( v5,  2, 2, 4, 6, 8 ) );
  v5 = (v1 + v2) - (v3 + v4);
  BOOST_CHECK( chkSurrealS4( v5, -4, -4, -8, -12, -16 ) );
  v5 = (v1 + v2) - (v3 - v4);
  BOOST_CHECK( chkSurrealS4( v5,  4, 4, 8, 12, 16 ) );
  v5 = (v1 - v2) + (v3 + v4);
  BOOST_CHECK( chkSurrealS4( v5,  6, 6, 12, 18, 24 ) );
  v5 = (v1 - v2) + (v3 - v4);
  BOOST_CHECK( chkSurrealS4( v5, -2, -2, -4, -6, -8 ) );
  v5 = (v1 - v2) - (v3 + v4);
  BOOST_CHECK( chkSurrealS4( v5, -8, -8, -16, -24, -32 ) );
  v5 = (v1 - v2) - (v3 - v4);
  BOOST_CHECK( chkSurrealS4( v5,  0, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );

  v5 += (v1 + v2) + (v3 + v4);
  v5 += (v1 + v2) + (v3 - v4);
  v5 += (v1 + v2) - (v3 + v4);
  v5 += (v1 + v2) - (v3 - v4);
  v5 += (v1 - v2) + (v3 + v4);
  v5 += (v1 - v2) + (v3 - v4);
  v5 += (v1 - v2) - (v3 + v4);
  v5 += (v1 - v2) - (v3 - v4);
  BOOST_CHECK( chkSurrealS4( v5,  8, 8, 16, 24, 32 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );

  v5 -= (v1 + v2) + (v3 + v4);
  v5 -= (v1 + v2) + (v3 - v4);
  v5 -= (v1 + v2) - (v3 + v4);
  v5 -= (v1 + v2) - (v3 - v4);
  v5 -= (v1 - v2) + (v3 + v4);
  v5 -= (v1 - v2) + (v3 - v4);
  v5 -= (v1 - v2) - (v3 + v4);
  v5 -= (v1 - v2) - (v3 - v4);
  BOOST_CHECK( chkSurrealS4( v5,  0, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );

  v2 = +v1;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1,  1,  2,  3,  4 ) );
  v2 = -v1;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -1, -1, -2, -3, -4 ) );
  v3 = +(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -1, -1, -2, -3, -4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  0,  0,  0,  0,  0 ) );
  v3 = +(v1 - v2);
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -1, -1, -2, -3, -4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2,  2,  4,  6,  8 ) );
  v3 = -(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -1, -1, -2, -3, -4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  0,  0,  0,  0,  0 ) );
  v3 = -(v1 - v2);
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -1, -1, -2, -3, -4 ) );
  BOOST_CHECK( chkSurrealS4( v3, -2, -2, -4, -6, -8 ) );

  // addition/subtraction with scalar quantities

  v3 = v1 + 3;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4,  1,  2,  3,  4 ) );
  v3 = v1 + Real(3);
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4,  1,  2,  3,  4 ) );
  v3 = 3 + v1;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4,  1,  2,  3,  4 ) );
  v3 = Real(3) + v1;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4,  1,  2,  3,  4 ) );
  v3 += v1 + 1;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  6,  2,  4,  6,  8 ) );
  v3 -= v1 + 1;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4,  1,  2,  3,  4 ) );
  v3 = v1 - 3;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3, -2,  1,  2,  3,  4 ) );
  v3 = v1 - Real(3);
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3, -2,  1,  2,  3,  4 ) );
  v3 = 3 - v1;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2, -1, -2, -3, -4 ) );
  v3 = Real(3) - v1;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2, -1, -2, -3, -4 ) );

  v3 = +(v1 + v2) + 3;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -1, -1, -2, -3, -4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3,  0,  0,  0,  0 ) );
  v3 = -(v1 + v2) + 3;
  BOOST_CHECK( chkSurrealS4( v1,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -1, -1, -2, -3, -4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3,  0,  0,  0,  0 ) );
}


//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( multiply )
{
  Real d[4] = {1, 2, 3, 4};
  SurrealS4 v1(1, d, 4);
  SurrealS4 v2(v1), v3(v1), v4(v1), v5(v1);

  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v4,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v5,  1, 1, 2, 3, 4 ) );

  // binary * operators

  v2 = 3*v1;
  v3 = v2*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v3,  6, 6, 12, 18, 24 ) );

  v2 += 3*v1;
  v3 += v2*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  6, 6, 12, 18, 24 ) );
  BOOST_CHECK( chkSurrealS4( v3, 18, 18, 36, 54, 72 ) );

  v2 -= 3*v1;
  v3 -= v2*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v3, 12, 12, 24, 36, 48 ) );

  v2 = 3/v1;
  v3 = v2/1;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  3, -3, -6, -9, -12 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, -3, -6, -9, -12 ) );

  v2 = 2*v1;
  v3 = v1*v2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2, 4, 8, 12, 16 ) );
  v3 += v1*v2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4, 8, 16, 24, 32 ) );

  v3 = 2*v1;
  v3 = v1*v3; //Test when v3 is both on left and right
  BOOST_CHECK( chkSurrealS4( v3, 2, 4, 8, 12, 16 ) );
  v3 += v1*v3;
  BOOST_CHECK( chkSurrealS4( v3, 4, 10, 20, 30, 40 ) );
  v3 -= v1*v3;
  BOOST_CHECK( chkSurrealS4( v3, 0, -4, -8, -12, -16 ) );

  v2 = 2*(v1*2);
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  4, 4, 8, 12, 16 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = 4*v1;
  v5 = 3*(v1 + v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v5, 23, 23, 46, 69, 92 ) );
  v5 = 3*(v1 + v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5,  7, 7, 14, 21, 28 ) );
  v5 = 3*(v1 + v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -5, -5, -10, -15, -20 ) );
  v5 = 3*(v1 + v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 11, 11, 22, 33, 44 ) );
  v5 = 3*(v1 - v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 11, 11, 22, 33, 44 ) );
  v5 = 3*(v1 - v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -5, -5, -10, -15, -20 ) );
  v5 = 3*(v1 - v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -17, -17, -34, -51, -68 ) );
  v5 = 3*(v1 - v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -1, -1, -2, -3, -4 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = 4*v1;
  v5 = 5;
  v5 += 3*(v1 + v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v5, 28, 23, 46, 69, 92 ) );
  v5 += 3*(v1 + v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 35, 30, 60, 90, 120 ) );
  v5 += 3*(v1 + v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 30, 25, 50, 75, 100 ) );
  v5 += 3*(v1 + v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 41, 36, 72, 108, 144 ) );
  v5 += 3*(v1 - v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 52, 47, 94, 141, 188 ) );
  v5 += 3*(v1 - v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 47, 42, 84, 126, 168 ) );
  v5 += 3*(v1 - v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 30, 25, 50, 75, 100 ) );
  v5 += 3*(v1 - v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 29, 24, 48, 72, 96 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = 4*v1;
  v5 = 5;
  v5 -= 3*(v1 + v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v5, -18, -23, -46, -69, -92 ) );
  v5 -= 3*(v1 + v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -25, -30, -60, -90, -120 ) );
  v5 -= 3*(v1 + v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -20, -25, -50, -75, -100 ) );
  v5 -= 3*(v1 + v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -31, -36, -72, -108, -144 ) );
  v5 -= 3*(v1 - v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -42, -47, -94, -141, -188 ) );
  v5 -= 3*(v1 - v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -37, -42, -84, -126, -168 ) );
  v5 -= 3*(v1 - v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -20, -25, -50, -75, -100 ) );
  v5 -= 3*(v1 - v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -19, -24, -48, -72, -96 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16 ) );

  v3 = 3*(v1 + v2)*2;
  BOOST_CHECK( chkSurrealS4( v3, 18, 18, 36, 54, 72 ) );
  v3 = 3*2*(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v3, 18, 18, 36, 54, 72 ) );
  v3 = (v1 + v2)*3*2;
  BOOST_CHECK( chkSurrealS4( v3, 18, 18, 36, 54, 72 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );

  v2 = +3*v1;
  BOOST_CHECK( chkSurrealS4( v2,  3,  3,  6,  9,  12 ) );
  v2 = -3*v1;
  BOOST_CHECK( chkSurrealS4( v2, -3, -3, -6, -9, -12 ) );
  v2 = +v1*3;
  BOOST_CHECK( chkSurrealS4( v2,  3,  3,  6,  9,  12 ) );
  v2 = -v1*3;
  BOOST_CHECK( chkSurrealS4( v2, -3, -3, -6, -9, -12 ) );
  v2 = +(3*v1);
  BOOST_CHECK( chkSurrealS4( v2,  3,  3,  6,  9,  12 ) );
  v2 = -(3*v1);
  BOOST_CHECK( chkSurrealS4( v2, -3, -3, -6, -9, -12 ) );
  v2 = +(v1*3);
  BOOST_CHECK( chkSurrealS4( v2,  3,  3,  6,  9,  12 ) );
  v2 = -(v1*3);
  BOOST_CHECK( chkSurrealS4( v2, -3, -3, -6, -9, -12 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = v1*v2*v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4,  6, 18, 36, 54, 72 ) );
  v4 = 2*v1*v2*v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4, 12, 36, 72, 108, 144 ) );

  v2 = 2*v1;
  v3 = 4*v1;
  v4 = (v1 + v2)*v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4, 4, 8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v4, 12, 24, 48, 72, 96 ) );
  v4 += (v1 + v2)*v3;
  BOOST_CHECK( chkSurrealS4( v4, 24, 48, 96, 144, 192 ) );
  v4 = v3*(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v4, 12, 24, 48, 72, 96 ) );
  v4 += v3*(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v4, 24, 48, 96, 144, 192 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4, 4, 8, 12, 16 ) );

  v2 = 2*v1;
  v3 = (v1 + v2)*(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  9, 18, 36, 54, 72 ) );
  v2 = 2*v1;
  v3 = 3*v1;
  v4 = (v1 + v2)*(v2 + v3);
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
  BOOST_CHECK( chkSurrealS4( v4, 15, 30, 60, 90, 120 ) );
  v4 += (v1 + v2)*(v2 + v3);
  BOOST_CHECK( chkSurrealS4( v4, 30, 60, 120, 180, 240 ) );
  v4 = 2*(v1 + v2)*(v2 + v3);
  BOOST_CHECK( chkSurrealS4( v4, 30, 60, 120, 180, 240 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12 ) );
}


//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( divide )
{
  Real d[4] = {2, 4, 6, 8};
  SurrealS4 v1(2, d, 4);
  SurrealS4 v2(v1), v3(v1), v4(v1), v5(v1);

  BOOST_CHECK( chkSurrealS4( v1,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v4,  2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v5,  2, 2, 4, 6, 8 ) );

  // binary / operators

  v2 = 4/v1;
  v3 = v2/2;
  BOOST_CHECK( chkSurrealS4( v1,  2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, -2, -4, -6, -8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, -1, -2, -3, -4 ) );

  v2 = Real(4)/v1;
  v3 = v2/Real(2);
  BOOST_CHECK( chkSurrealS4( v1,  2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, -2, -4, -6, -8 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, -1, -2, -3, -4 ) );

  v2 += 4/v1;
  v3 += v2/2;
  BOOST_CHECK( chkSurrealS4( v1, 2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2, 4, -4, -8, -12, -16 ) );
  BOOST_CHECK( chkSurrealS4( v3, 3, -3, -6, -9, -12 ) );

  v2 -= 4/v1;
  v3 -= v2/2;
  BOOST_CHECK( chkSurrealS4( v1, 2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, -2, -4, -6, -8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, -2, -4, -6, -8 ) );

  v2 = 2*v1;
  v3 = v2/v1;
  BOOST_CHECK( chkSurrealS4( v1, 2, 2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2, 4, 4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 0,  0,  0,  0 ) );

  v3 += v2/v1;
  BOOST_CHECK( chkSurrealS4( v1, 2, 2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2, 4, 4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3, 4, 0,  0,  0,  0 ) );

  v3 -= v2/v1;
  BOOST_CHECK( chkSurrealS4( v1, 2, 2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2, 4, 4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 0,  0,  0,  0 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = (v2+v1)/v3;
  BOOST_CHECK( chkSurrealS4( v1, 2, 2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2, 4, 4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3, 6, 6, 12, 18, 24 ) );
  BOOST_CHECK( chkSurrealS4( v4, 1, 0,  0,  0,  0 ) );
  v4 += (v2+v1)/v3;
  BOOST_CHECK( chkSurrealS4( v4, 2, 0,  0,  0,  0 ) );
  v4 = v3/(v2+v1);
  BOOST_CHECK( chkSurrealS4( v4, 1, 0,  0,  0,  0 ) );
  v4 += v3/(v2+v1);
  BOOST_CHECK( chkSurrealS4( v4, 2, 0,  0,  0,  0 ) );
  BOOST_CHECK( chkSurrealS4( v1, 2, 2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2, 4, 4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3, 6, 6, 12, 18, 24 ) );

  v2 = 2*v1;
  v3 = 4*v1;
  v4 = 6*v1;
  v5 = 12/(v1 + v2) + (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v1,   2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,   4,  4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3,   8,  8, 16, 24, 32 ) );
  BOOST_CHECK( chkSurrealS4( v4,  12, 12, 24, 36, 48 ) );
  BOOST_CHECK( chkSurrealS4( v5,  12,  8, 16, 24, 32 ) );
  v5 = 12/(v1 + v2) + (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,   0,  -4,  -8, -12, -16 ) );
  v5 = 12/(v1 + v2) - (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  -8, -12, -24, -36, -48 ) );
  v5 = 12/(v1 + v2) - (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,   4,   0,   0,   0,   0) );
  v5 = 12/(v1 - v2) + (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,   4,  16,  32,  48,  64 ) );
  v5 = 12/(v1 - v2) + (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  -8,   4,   8,  12,  16 ) );
  v5 = 12/(v1 - v2) - (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5, -16,  -4,  -8, -12, -16 ) );
  v5 = 12/(v1 - v2) - (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  -4,   8,  16,  24,  32 ) );
  BOOST_CHECK( chkSurrealS4( v1,   2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,   4,  4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3,   8,  8, 16, 24, 32 ) );
  BOOST_CHECK( chkSurrealS4( v4,  12, 12, 24, 36, 48 ) );

  v2 = 2*v1;
  v3 = 4*v1;
  v4 = 6*v1;
  v5 = 1;
  v5 += 12/(v1 + v2) + (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v1,   2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,   4,  4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3,   8,  8, 16, 24, 32 ) );
  BOOST_CHECK( chkSurrealS4( v4,  12, 12, 24, 36, 48 ) );
  BOOST_CHECK( chkSurrealS4( v5,  13,  8, 16, 24, 32 ) );
  v5 += 12/(v1 + v2) + (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  13,  4,  8, 12, 16 ) );
  v5 += 12/(v1 + v2) - (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,   5, -8, -16, -24, -32 ) );
  v5 += 12/(v1 + v2) - (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,   9, -8, -16, -24, -32 ) );
  v5 += 12/(v1 - v2) + (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  13,  8,  16,  24,  32 ) );
  v5 += 12/(v1 - v2) + (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,   5, 12,  24,  36,  48 ) );
  v5 += 12/(v1 - v2) - (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5, -11,  8,  16,  24,  32 ) );
  v5 += 12/(v1 - v2) - (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5, -15, 16,  32,  48,  64 ) );
  BOOST_CHECK( chkSurrealS4( v1,   2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,   4,  4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3,   8,  8, 16, 24, 32 ) );
  BOOST_CHECK( chkSurrealS4( v4,  12, 12, 24, 36, 48 ) );

  v2 = 2*v1;
  v3 = 4*v1;
  v4 = 6*v1;
  v5 = 1;
  v5 -= 12/(v1 + v2) + (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v1,   2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,   4,  4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3,   8,  8, 16, 24, 32 ) );
  BOOST_CHECK( chkSurrealS4( v4,  12, 12, 24, 36, 48 ) );
  BOOST_CHECK( chkSurrealS4( v5, -11, -8, -16, -24, -32 ) );
  v5 -= 12/(v1 + v2) + (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5, -11, -4, -8, -12, -16 ) );
  v5 -= 12/(v1 + v2) - (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  -3,  8, 16, 24, 32 ) );
  v5 -= 12/(v1 + v2) - (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  -7,  8, 16, 24, 32 ) );
  v5 -= 12/(v1 - v2) + (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5, -11, -8, -16, -24, -32 ) );
  v5 -= 12/(v1 - v2) + (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  -3, -12, -24, -36, -48 ) );
  v5 -= 12/(v1 - v2) - (v3 + v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  13,  -8, -16, -24, -32 ) );
  v5 -= 12/(v1 - v2) - (v3 - v4)/2;
  BOOST_CHECK( chkSurrealS4( v5,  17, -16, -32, -48, -64 ) );
  BOOST_CHECK( chkSurrealS4( v1,   2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,   4,  4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3,   8,  8, 16, 24, 32 ) );
  BOOST_CHECK( chkSurrealS4( v4,  12, 12, 24, 36, 48 ) );

  v5 = 12/(v1 + v2)/2;
  BOOST_CHECK( chkSurrealS4( v5,  1, -1, -2, -3, -4 ) );
  v5 = 12/2/(v1 - v2);
  BOOST_CHECK( chkSurrealS4( v5, -3,  3,  6,  9, 12 ) );
  v5 = (v1 + v2)/3/2;
  BOOST_CHECK( chkSurrealS4( v5,  1,  1,  2,  3,  4 ) );
  BOOST_CHECK( chkSurrealS4( v1,  2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,  4,  4,  8, 12, 16 ) );

  // cppcheck-suppress duplicateExpression
  v5 = (v1 + v2)/(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v5,  1, 0, 0, 0, 0 ) );
  v5 = 2*(v1 + v2)/(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v5,  2, 0, 0, 0, 0 ) );
  v5 += 2*(v1 + v2)/(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v5,  4, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,  4,  4,  8, 12, 16 ) );

  v2 = 2*v1;
  v3 = 4*v1;
  v5 = (v2 + v3)/(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v5,  2, 0, 0, 0, 0 ) );
  v5 = 2*(v2 + v3)/(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v5,  4, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  2,  2,  4,  6,  8 ) );
  BOOST_CHECK( chkSurrealS4( v2,  4,  4,  8, 12, 16 ) );
  BOOST_CHECK( chkSurrealS4( v3,  8,  8, 16, 24, 32 ) );
}


//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( relational )
{
  SurrealS4 v1(1, 3);
  SurrealS4 v2(1, 3);
  SurrealS4 v3(2, 3);

  BOOST_CHECK( chkSurrealS4( v1,  1, 3, 3, 3, 3 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 3, 3, 3, 3 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2, 3, 3, 3, 3 ) );

  BOOST_CHECK(   v2 == v1  );
  BOOST_CHECK( !(v3 == v1) );
  BOOST_CHECK(   v2 == 1   );
  BOOST_CHECK( !(v3 == 1)  );
  BOOST_CHECK(   1 == v2   );
  BOOST_CHECK( !(1 == v3)  );

  BOOST_CHECK( v2 == Real(1) );
  BOOST_CHECK( Real(1) == v2 );

  BOOST_CHECK( !(v2 != v1) );
  BOOST_CHECK(   v3 != v1  );
  BOOST_CHECK( !(v2 != 1)  );
  BOOST_CHECK(   v3 != 1   );
  BOOST_CHECK( !(1 != v2)  );
  BOOST_CHECK(   1 != v3   );

  BOOST_CHECK( !(v2 > v1) );
  BOOST_CHECK(   v3 > v1  );
  BOOST_CHECK( !(v2 > 1)  );
  BOOST_CHECK(   v3 > 1   );
  BOOST_CHECK( !(1 > v2)  );
  BOOST_CHECK( !(1 > v3)  );

  BOOST_CHECK( !(v2 < v1) );
  BOOST_CHECK( !(v3 < v1) );
  BOOST_CHECK( !(v2 < 1)  );
  BOOST_CHECK( !(v3 < 1)  );
  BOOST_CHECK( !( 1 < v2) );
  BOOST_CHECK(    1 < v3  );

  BOOST_CHECK(  v2 >= v1  );
  BOOST_CHECK(  v3 >= v1  );
  BOOST_CHECK(  v2 >= 1   );
  BOOST_CHECK(  v3 >= 1   );
  BOOST_CHECK(   1 >= v2  );
  BOOST_CHECK( !(1 >= v3) );

  BOOST_CHECK(  v2 <= v1 );
  BOOST_CHECK( !(v3 <= v1) );
  BOOST_CHECK(  v2 <= 1 );
  BOOST_CHECK( !(v3 <= 1) );
  BOOST_CHECK(  1 <= v2 );
  BOOST_CHECK(  1 <= v3 );
}


//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( cmath )
{
  const double tol = 1.e-13;
  Real d[4] = {1, 2, 3, 4};
  SurrealS4 v1(1, d, 4);
  SurrealS4 v2(v1), v3(v1), v4(v1), v5(v1);
  Real d0;

  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v4, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v5, 1, 1, 2, 3, 4 ) );

  // trig functions <cmath>

  v2 = cos(v1);  d0 = -sin(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, cos(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += cos(v1);  d0 = -2*sin(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*cos(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 = sin(v1);  d0 = cos(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, sin(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += sin(v1);  d0 = 2*cos(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*sin(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 = tan(v1);  d0 = 1/(cos(1.)*cos(1.));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, tan(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += tan(v1);  d0 = 2/(cos(1.)*cos(1.));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*tan(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );

  v2 = acos(cos(v1));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4, tol ) );
  v2 += acos(cos(v1));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8, tol ) );
  v2 = asin(sin(v1));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4, tol ) );
  v2 += asin(sin(v1));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8, tol ) );
  v2 = atan(tan(v1));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4, tol ) );
  v2 += atan(tan(v1));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8, tol ) );

  v2 = v1;
  v3 = v1;
  v4 = atan2(v2, v3);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v4, atan2(1., 1.), 0, 0, 0, 0, tol ) );
  v4 += atan2(v2, v3);
  BOOST_CHECK( chkSurrealS4( v4, 2*atan2(1., 1.), 0, 0, 0, 0, tol ) );

  // hyperbolic functions <cmath>

  v2 = cosh(v1);  d0 = sinh(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, cosh(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += cosh(v1);  d0 = 2*sinh(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*cosh(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 = sinh(v1);  d0 = cosh(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, sinh(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += sinh(v1);  d0 = 2*cosh(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*sinh(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 = tanh(v1);  d0 = 1/(cosh(1.)*cosh(1.));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, tanh(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += tanh(v1);  d0 = 2/(cosh(1.)*cosh(1.));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*tanh(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );

  // exp and log functions <cmath>

  v2 = exp(v1);  d0 = exp(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, exp(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += exp(v1);  d0 = 2*exp(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*exp(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );

  v2 = expm1(v1);  d0 = exp(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, expm1(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += expm1(v1);  d0 = 2*exp(1.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*expm1(1.), d0, 2*d0, 3*d0, 4*d0, tol ) );

  v2 = log(v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 0, 1, 2, 3, 4, tol ) );
  v2 += log(v1);  d0 = 2;
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 0, d0, 2*d0, 3*d0, 4*d0, tol ) );

  v2 = log10(v1);  d0 = 1/log(10.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 0, d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += log10(v1);  d0 = 2/log(10.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 0, d0, 2*d0, 3*d0, 4*d0, tol ) );

  v2 = log1p(v1);  d0 = 1./2.;
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, log(2.), d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += log1p(v1);  d0 = 2./2.;
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2*log(2.), d0, 2*d0, 3*d0, 4*d0, tol ) );

  // error-functions <cmath>

  v2 = 1.5*v1;
  v3 = erf(v2);
  BOOST_CHECK( chkSurrealS4( v2, 1.5, 1.5, 3, 4.5, 6 ) );
  Real erf_x =  2./sqrt(M_PI)*exp(-(v2.value()*v2.value()));
  BOOST_CHECK( chkSurrealS4( v3, erf(v2.value()), v2.deriv(0)*erf_x, v2.deriv(1)*erf_x, v2.deriv(2)*erf_x, v2.deriv(3)*erf_x) );
  v3 = erfc(v2);
  BOOST_CHECK( chkSurrealS4( v2, 1.5, 1.5, 3, 4.5, 6 ) );
  Real erfc_x = -2./sqrt(M_PI)*exp(-(v2.value()*v2.value()));
  BOOST_CHECK( chkSurrealS4( v3, erfc(v2.value()), v2.deriv(0)*erfc_x, v2.deriv(1)*erfc_x, v2.deriv(2)*erfc_x, v2.deriv(3)*erfc_x) );

  // power functions <cmath>

  v2 = v1;
  v3 = pow(v2, v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 1, 2, 3, 4, tol ) );
  v3 += pow(v2, v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 2, 4, 6, 8, tol ) );
  v2 = pow(v1, 2);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 2, 4, 6, 8, tol ) );
  v2 = pow(v1, Real(2));
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 2, 4, 6, 8, tol ) );
  v2 += pow(v1, 2);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 4, 8, 12, 16, tol ) );
  v2 = pow(2, v1);  d0 = 2*log(2.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 = pow(Real(2), v1);  d0 = 2*log(2.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 += pow(2, v1);  d0 = 4*log(2.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 4, d0, 2*d0, 3*d0, 4*d0, tol ) );
  v2 = v1;
  v3 = pow(v1+v2, v1+v2);  d0 = 13.54517744447956;
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 4, d0, 2*d0, 3*d0, 4*d0, tol ) );
  v3 += pow(v1+v2, v1+v2);  d0 = 2*13.54517744447956;
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 8, d0, 2*d0, 3*d0, 4*d0, tol ) );

  v2 = v1;
  v3 = pow(4*v1/v2, 0.5 );
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 0, 0, 0, 0, tol ) );
  v3 += pow(4*v1/v2, 0.5 );
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 4, 0, 0, 0, 0, tol ) );

  v2 = pow(v1, 0);
  BOOST_CHECK( chkSurrealS4( v2, 1, 0, 0, 0, 0 ) );
  v2 = pow(0, v1);
  BOOST_CHECK( chkSurrealS4( v2, 0, 0, 0, 0, 0 ) );
  v2 = SurrealS4(0, d, 4);
  v3 = pow(v2, 0);
  BOOST_CHECK( chkSurrealS4( v2, 0, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 0, 0, 0, 0 ) );
  v3 = pow(v2, 1);
  BOOST_CHECK( chkSurrealS4( v2, 0, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 0, 1, 2, 3, 4 ) );
  Real d3[4] = {4, 3, 2, 1};
  v3 = SurrealS4(0, d3, 4);
  v4 = pow(v2, v3);
  BOOST_CHECK( chkSurrealS4( v2, 0, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 0, 4, 3, 2, 1 ) );
  BOOST_CHECK( chkSurrealS4( v4, 1, 0, 0, 0, 0 ) );


  v2 = sqrt(v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 0.5, 1, 1.5, 2, tol ) );
  v2 += sqrt(v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 1, 2, 3, 4, tol ) );
  v2 = 0;
  v3 = sqrt(v2);
  BOOST_CHECK( chkSurrealS4( v2, 0, 0, 0, 0, 0 ) );
  BOOST_CHECK( chkSurrealS4( v3, 0, 0, 0, 0, 0, tol ) );
  v3 = sqrt(4*v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 1, 2, 3, 4, tol ) );
  v3 += sqrt(4*v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v3, 4, 2, 4, 6, 8, tol ) );

  // rounding functions <cmath>

  v2 = 1.5*v1;
  v3 = ceil(v2);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1.5, 1.5, 3, 4.5, 6 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 0, 0, 0, 0, tol ) );
  v3 = floor(v2);
  BOOST_CHECK( chkSurrealS4( v2, 1.5, 1.5, 3, 4.5, 6 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 0, 0, 0, 0, tol ) );

  // misc functions <cmath>

  v2 = abs(v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );
  v2 = fabs(v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 1, 1, 2, 3, 4 ) );

  v2 = 2*v1;
  v3 = max(v1, v2);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 2, 4, 6, 8 ) );
  v3 = min(v1, v2);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 1, 2, 3, 4 ) );

  v3 = max(v1, 2.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 0, 0, 0, 0 ) );
  v3 = min(v1, 2.);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 1, 2, 3, 4 ) );

  v3 = max(2., v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 0, 0, 0, 0 ) );
  v3 = min(2., v1);
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, 2, 2, 4, 6, 8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 1, 2, 3, 4 ) );

  v2 = -2*v1;
  v3 = max( fabs(v1), fabs(v2) );
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -2, -2, -4, -6, -8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 2, 2, 4, 6, 8 ) );
  v3 = min( fabs(v1), fabs(v2) );
  BOOST_CHECK( chkSurrealS4( v1, 1, 1, 2, 3, 4 ) );
  BOOST_CHECK( chkSurrealS4( v2, -2, -2, -4, -6, -8 ) );
  BOOST_CHECK( chkSurrealS4( v3, 1, 1, 2, 3, 4 ) );
}


//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( multiply_deriv2 )
{
  Real d[4] = {1, 2, 3, 4};
  SurrealS<4, SurrealS4> v1(1, d, 4);
  SurrealS<4, SurrealS4> v2(v1), v3(v1), v4(v1), v5(v1);

  vector<Real> four0(4,0);
  vector<Real> four4(4,4);
  vector<Real> four6(4,6);
  vector<Real> four8(4,8);
  vector<Real> four12(4,12);
  vector<Real> four16(4,16);
  vector<Real> four18(4,18);
  vector<Real> four24(4,24);
  vector<Real> four30(4,30);
  vector<Real> four32(4,32);
  vector<Real> four36(4,36);
  vector<Real> four48(4,48);
  vector<Real> four54(4,54);
  vector<Real> four60(4,60);
  vector<Real> four64(4,64);
  vector<Real> four72(4,72);
  vector<Real> four90(4,90);
  vector<Real> four96(4,96);
  vector<Real> four108(4,108);
  vector<Real> four120(4,120);
  vector<Real> four144(4,144);
  vector<Real> four180(4,180);
  vector<Real> four192(4,192);
  vector<Real> four216(4,216);
  vector<Real> four240(4,240);
  vector<Real> four288(4,288);

  vector<Real> fourn20(4,-20);
  vector<Real> fourn40(4,-40);
  vector<Real> fourn60(4,-60);
  vector<Real> fourn80(4,-80);

  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v5,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );

  v1.value().deriv(0) = 1;
  v1.value().deriv(1) = 1;
  v1.value().deriv(2) = 1;
  v1.value().deriv(3) = 1;

  // binary * operators

  v2 = 3*v1;
  v3 = v2*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  6, 6, 12, 18, 24, four0, four0, four0, four0 ) );

  v2 += 3*v1;
  v3 += v2*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  6, 6, 12, 18, 24, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3, 18, 18, 36, 54, 72, four0, four0, four0, four0 ) );

  v2 -= 3*v1;
  v3 -= v2*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3, 12, 12, 24, 36, 48, four0, four0, four0, four0 ) );

  v2 = 3/v1;
  v3 = v2/1;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  3, -3, -6, -9, -12, four6, four12, four18, four24 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, -3, -6, -9, -12, four6, four12, four18, four24 ) );

  v2 = 2*v1;
  v3 = v1*v2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  2, 4, 8, 12, 16, four4, four8, four12, four16 ) );
  v3 += v1*v2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4, 8, 16, 24, 32, four8, four16, four24, four32 ) );

  v3 = 2*v1;
  v3 = v1*v3; //Test when v3 is both on left and right
  BOOST_CHECK( chkSurrealS4( v3, 2, 4, 8, 12, 16, four4, four8, four12, four16 ) );
  v3 += v1*v3;
  BOOST_CHECK( chkSurrealS4( v3, 4, 10, 20, 30, 40, four16, four32, four48, four64 ) );
  v3 -= v1*v3;
  BOOST_CHECK( chkSurrealS4( v3, 0, -4, -8, -12, -16, fourn20, fourn40, fourn60, fourn80 ) );

  v2 = 2*(v1*2);
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = 4*v1;
  v5 = 3*(v1 + v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v5, 23, 23, 46, 69, 92, four0, four0, four0, four0 ) );
  v5 = 3*(v1 + v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5,  7, 7, 14, 21, 28, four0, four0, four0, four0 ) );
  v5 = 3*(v1 + v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -5, -5, -10, -15, -20, four0, four0, four0, four0 ) );
  v5 = 3*(v1 + v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 11, 11, 22, 33, 44, four0, four0, four0, four0 ) );
  v5 = 3*(v1 - v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 11, 11, 22, 33, 44, four0, four0, four0, four0 ) );
  v5 = 3*(v1 - v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -5, -5, -10, -15, -20, four0, four0, four0, four0 ) );
  v5 = 3*(v1 - v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -17, -17, -34, -51, -68, four0, four0, four0, four0 ) );
  v5 = 3*(v1 - v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -1, -1, -2, -3, -4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = 4*v1;
  v5 = 5;
  v5 += 3*(v1 + v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v5, 28, 23, 46, 69, 92, four0, four0, four0, four0 ) );
  v5 += 3*(v1 + v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 35, 30, 60, 90, 120, four0, four0, four0, four0 ) );
  v5 += 3*(v1 + v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 30, 25, 50, 75, 100, four0, four0, four0, four0 ) );
  v5 += 3*(v1 + v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 41, 36, 72, 108, 144, four0, four0, four0, four0 ) );
  v5 += 3*(v1 - v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 52, 47, 94, 141, 188, four0, four0, four0, four0 ) );
  v5 += 3*(v1 - v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 47, 42, 84, 126, 168, four0, four0, four0, four0 ) );
  v5 += 3*(v1 - v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 30, 25, 50, 75, 100, four0, four0, four0, four0 ) );
  v5 += 3*(v1 - v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, 29, 24, 48, 72, 96, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = 4*v1;
  v5 = 5;
  v5 -= 3*(v1 + v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v5, -18, -23, -46, -69, -92, four0, four0, four0, four0 ) );
  v5 -= 3*(v1 + v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -25, -30, -60, -90, -120, four0, four0, four0, four0 ) );
  v5 -= 3*(v1 + v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -20, -25, -50, -75, -100, four0, four0, four0, four0 ) );
  v5 -= 3*(v1 + v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -31, -36, -72, -108, -144, four0, four0, four0, four0 ) );
  v5 -= 3*(v1 - v2) + (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -42, -47, -94, -141, -188, four0, four0, four0, four0 ) );
  v5 -= 3*(v1 - v2) + (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -37, -42, -84, -126, -168, four0, four0, four0, four0 ) );
  v5 -= 3*(v1 - v2) - (v3 + v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -20, -25, -50, -75, -100, four0, four0, four0, four0 ) );
  v5 -= 3*(v1 - v2) - (v3 - v4)*2;
  BOOST_CHECK( chkSurrealS4( v5, -19, -24, -48, -72, -96, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );

  v3 = 3*(v1 + v2)*2;
  BOOST_CHECK( chkSurrealS4( v3, 18, 18, 36, 54, 72, four0, four0, four0, four0 ) );
  v3 = 3*2*(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v3, 18, 18, 36, 54, 72, four0, four0, four0, four0 ) );
  v3 = (v1 + v2)*3*2;
  BOOST_CHECK( chkSurrealS4( v3, 18, 18, 36, 54, 72, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );

  v2 = +3*v1;
  BOOST_CHECK( chkSurrealS4( v2,  3,  3,  6,  9,  12, four0, four0, four0, four0 ) );
  v2 = -3*v1;
  BOOST_CHECK( chkSurrealS4( v2, -3, -3, -6, -9, -12, four0, four0, four0, four0 ) );
  v2 = +v1*3;
  BOOST_CHECK( chkSurrealS4( v2,  3,  3,  6,  9,  12, four0, four0, four0, four0 ) );
  v2 = -v1*3;
  BOOST_CHECK( chkSurrealS4( v2, -3, -3, -6, -9, -12, four0, four0, four0, four0 ) );
  v2 = +(3*v1);
  BOOST_CHECK( chkSurrealS4( v2,  3,  3,  6,  9,  12, four0, four0, four0, four0 ) );
  v2 = -(3*v1);
  BOOST_CHECK( chkSurrealS4( v2, -3, -3, -6, -9, -12, four0, four0, four0, four0 ) );
  v2 = +(v1*3);
  BOOST_CHECK( chkSurrealS4( v2,  3,  3,  6,  9,  12, four0, four0, four0, four0 ) );
  v2 = -(v1*3);
  BOOST_CHECK( chkSurrealS4( v2, -3, -3, -6, -9, -12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );

  v2 = 2*v1;
  v3 = 3*v1;
  v4 = v1*v2*v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4,  6, 18, 36, 54, 72, four36, four72, four108, four144 ) );
  v4 = 2*v1*v2*v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4, 12, 36, 72, 108, 144, four72, four144, four216, four288 ) );

  v2 = 2*v1;
  v3 = 4*v1;
  v4 = (v1 + v2)*v3;
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4, 12, 24, 48, 72, 96, four24, four48, four72, four96 ) );
  v4 += (v1 + v2)*v3;
  BOOST_CHECK( chkSurrealS4( v4, 24, 48, 96, 144, 192, four48, four96, four144, four192 ) );
  v4 = v3*(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v4, 12, 24, 48, 72, 96, four24, four48, four72, four96 ) );
  v4 += v3*(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v4, 24, 48, 96, 144, 192, four48, four96, four144, four192 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  4, 4, 8, 12, 16, four0, four0, four0, four0 ) );

  v2 = 2*v1;
  v3 = (v1 + v2)*(v1 + v2);
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  9, 18, 36, 54, 72, four18, four36, four54, four72 ) );
  v2 = 2*v1;
  v3 = 3*v1;
  v4 = (v1 + v2)*(v2 + v3);
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v4, 15, 30, 60, 90, 120, four30, four60, four90, four120 ) );
  v4 += (v1 + v2)*(v2 + v3);
  BOOST_CHECK( chkSurrealS4( v4, 30, 60, 120, 180, 240, four60, four120, four180, four240 ) );
  v4 = 2*(v1 + v2)*(v2 + v3);
  BOOST_CHECK( chkSurrealS4( v4, 30, 60, 120, 180, 240, four60, four120, four180, four240 ) );
  BOOST_CHECK( chkSurrealS4( v1,  1, 1, 2, 3, 4, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v2,  2, 2, 4, 6, 8, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( v3,  3, 3, 6, 9, 12, four0, four0, four0, four0 ) );
}


//----------------------------------------------------------------------------//
BOOST_AUTO_TEST_CASE( deriv2 )
{
  const Real tol = 1e-14;
  SurrealS<4, SurrealS4> x = 2, y = 3, z = 4, t = 5;
  SurrealS<4, SurrealS4> sln;

  vector<Real> four0(4,0);
  vector<Real> dd0(4), dd1(4), dd2(4), dd3(4);

  x.deriv(0) = 1;
  y.deriv(1) = 1;
  z.deriv(2) = 1;
  t.deriv(3) = 1;

  x.value().deriv(0) = 1;
  y.value().deriv(1) = 1;
  z.value().deriv(2) = 1;
  t.value().deriv(3) = 1;

  BOOST_CHECK( chkSurrealS4( x,  2, 1, 0, 0, 0, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( y,  3, 0, 1, 0, 0, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( z,  4, 0, 0, 1, 0, four0, four0, four0, four0 ) );
  BOOST_CHECK( chkSurrealS4( t,  5, 0, 0, 0, 1, four0, four0, four0, four0 ) );

  sln = x*y*z*t;

  dd0[0] =  0; dd0[1] = 20; dd0[2] = 15; dd0[3] = 12;
  dd1[0] = 20; dd1[1] =  0; dd1[2] = 10; dd1[3] =  8;
  dd2[0] = 15; dd2[1] = 10; dd2[2] =  0; dd2[3] =  6;
  dd3[0] = 12; dd3[1] =  8; dd3[2] =  6; dd3[3] =  0;

  BOOST_CHECK( chkSurrealS4( sln, 120, 60, 40, 30, 24, dd0, dd1, dd2, dd3 ) );

  sln = x*x*y*z*t;

  dd0[0] = 120; dd0[1] = 80; dd0[2] = 60; dd0[3] = 48;
  dd1[0] =  80; dd1[1] =  0; dd1[2] = 20; dd1[3] = 16;
  dd2[0] =  60; dd2[1] = 20; dd2[2] =  0; dd2[3] = 12;
  dd3[0] =  48; dd3[1] = 16; dd3[2] = 12; dd3[3] =  0;

  BOOST_CHECK( chkSurrealS4( sln, 240, 240, 80, 60, 48, dd0, dd1, dd2, dd3 ) );

  sln = x*y*y*z*t;

  dd0[0] =   0; dd0[1] = 120; dd0[2] = 45; dd0[3] = 36;
  dd1[0] = 120; dd1[1] =  80; dd1[2] = 60; dd1[3] = 48;
  dd2[0] =  45; dd2[1] =  60; dd2[2] =  0; dd2[3] = 18;
  dd3[0] =  36; dd3[1] =  48; dd3[2] = 18; dd3[3] =  0;

  BOOST_CHECK( chkSurrealS4( sln, 360, 180, 240, 90, 72, dd0, dd1, dd2, dd3 ) );

  sln = x*y*z*z*t;

  dd0[0] =   0; dd0[1] =  80; dd0[2] = 120; dd0[3] = 48;
  dd1[0] =  80; dd1[1] =   0; dd1[2] =  80; dd1[3] = 32;
  dd2[0] = 120; dd2[1] =  80; dd2[2] =  60; dd2[3] = 48;
  dd3[0] =  48; dd3[1] =  32; dd3[2] =  48; dd3[3] =  0;

  BOOST_CHECK( chkSurrealS4( sln, 480, 240, 160, 240, 96, dd0, dd1, dd2, dd3 ) );

  sln = x*y*z*t*t;

  dd0[0] =   0; dd0[1] = 100; dd0[2] =  75; dd0[3] = 120;
  dd1[0] = 100; dd1[1] =   0; dd1[2] =  50; dd1[3] =  80;
  dd2[0] =  75; dd2[1] =  50; dd2[2] =   0; dd2[3] =  60;
  dd3[0] = 120; dd3[1] =  80; dd3[2] =  60; dd3[3] =  48;

  BOOST_CHECK( chkSurrealS4( sln, 600, 300, 200, 150, 240, dd0, dd1, dd2, dd3 ) );

  sln = sin(7.*x)*sin(6.*y)*sin(5.*z)*sin(4.*t);

  dd0[0] = -49*sin(14.)*sin(18.)*sin(20.)*sin(20.); dd0[1] =  42*cos(14.)*cos(18.)*sin(20.)*sin(20.); dd0[2] =  35*cos(14.)*cos(20.)*sin(18.)*sin(20.); dd0[3] =  28*cos(14.)*cos(20.)*sin(18.)*sin(20.);
  dd1[0] =  42*cos(14.)*cos(18.)*sin(20.)*sin(20.); dd1[1] = -36*sin(14.)*sin(18.)*sin(20.)*sin(20.); dd1[2] =  30*cos(18.)*cos(20.)*sin(14.)*sin(20.); dd1[3] =  24*cos(18.)*cos(20.)*sin(14.)*sin(20.);
  dd2[0] =  35*cos(14.)*cos(20.)*sin(18.)*sin(20.); dd2[1] =  30*cos(18.)*cos(20.)*sin(14.)*sin(20.); dd2[2] = -25*sin(14.)*sin(18.)*sin(20.)*sin(20.); dd2[3] =  20*cos(20.)*cos(20.)*sin(14.)*sin(18.);
  dd3[0] =  28*cos(14.)*cos(20.)*sin(18.)*sin(20.); dd3[1] =  24*cos(18.)*cos(20.)*sin(14.)*sin(20.); dd3[2] =  20*cos(20.)*cos(20.)*sin(14.)*sin(18.); dd3[3] = -16*sin(14.)*sin(18.)*sin(20.)*sin(20.);

  BOOST_CHECK( chkSurrealS4( sln, sin(14.)*sin(18.)*sin(20.)*sin(20.),
      7*cos(14.)*sin(18.)*sin(20.)*sin(20.),  6*cos(18.)*sin(14.)*sin(20.)*sin(20.),  5*cos(20.)*sin(14.)*sin(18.)*sin(20.),  4*cos(20.)*sin(14.)*sin(18.)*sin(20.),
      dd0, dd1, dd2, dd3,
      tol ) );
}

//----------------------------------------------------------------------------//
/*
BOOST_AUTO_TEST_CASE( IO )
{
  //Set the 2nd argument to false to regenerate the pattern file
  output_test_stream output( "IO/Surreal/SurrealS4_pattern.txt", true );

  Real d[4] = {1, 2, 3, 4};
  SurrealS4 v1(1, d, 4);
  SurrealS4 v2(v1);

  output << v1 << std::endl;
  BOOST_CHECK( output.match_pattern() );
  //v1.dump( 2, output );
  //BOOST_CHECK( output.match_pattern() );

  output << (v1 + v2) << std::endl;
  BOOST_CHECK( output.match_pattern() );

}
*/
//############################################################################//
// BOOST_AUTO_TEST_SUITE_END()
int main(int argc, char *argv[])
{
  ctors_access();
  assign_unary_accum();
  addsubtract();
  multiply();
  divide();
  relational();
  cmath();
#if defined(_MSC_VER) && _MSC_VER < 1800
#else
  multiply_deriv2();
  deriv2();
#endif
//  IO();
  std::cout << std::endl;
  std::cout << "SurrealS4_test_suite Complete!" << std::endl;
  std::cout << std::endl;
  return 0;
}
