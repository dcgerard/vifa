// we only include RcppArmadillo.h which pulls Rcpp.h in for us
#include <RcppArmadillo.h>
#include <cassert>
using namespace Rcpp;

// via the depends attribute we tell Rcpp to create hooks for
// RcppArmadillo so that the build process will know what to do
//
// [[Rcpp::depends(RcppArmadillo)]]

//' EM Algorithm for FLASH.
//'
//' @param Y The data matrix.
//' @param expA A matrix whose \eqn{(i, l)}th entry is the initial value for the variational mean
//'     of \eqn{a_{il}}.
//' @param expB A matrix whose \eqn{(j, l)}th entry is the initial value for the variational mean
//'     of \eqn{b_{jl}}.
//' @param expA2 A matrix whose \eqn{(i, l)}th entry is the initial value for the variational mean
//'     of \eqn{a_{il}^2}.
//' @param expB2 A matrix whose \eqn{(j, l)}th entry is the initial value for the variational mean
//'     of \eqn{b_{jl}^2}.
//' @param piMat The initial values of the mixing proportions of the A's. The rows index the
//'     factors and the columns index the mixing distributions. Thus, \code{piMat.nrow()}
//'     should equal \code{expA.ncol()}.
//' @param phiMat The initial values of hte mixing proportions of the B's. The rows index
//'     the factors and the columns index the mixing distribution. Thus, \code{phiMat.nrow()}
//'     should equal \code{expB.ncol()}.
//' @param sig2Vec A vector of the initial values of the column-specific variances.
//'
//' @author David Gerard
//'
// [[Rcpp::export]]
void flash(const NumericMatrix& Y,
           NumericMatrix& expA, NumericMatrix& expB,
           NumericMatrix& expA2, NumericMatrix& expB2,
           NumericMatrix& piMat, NumericMatrix& phiMat,
           NumericVector& sig2Vec) {

  // Check input
  assert(expA.ncol() == expA2.ncol());
  assert(expA.nrow() == expA2.nrow());
  assert(expB.ncol() == expB2.ncol());
  assert(expB.nrow() == expB2.nrow());
  assert(expA.ncol() == piMat.nrow());
  assert(expB.ncol() == phiMat.nrow());
  assert(sig2Vec.size() == 1 || sig2Vec.size() == Y.ncol());



}
