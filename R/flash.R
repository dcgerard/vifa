
#' Factor/Loading Adaptive SHrinkage
#'
#' This contains a variational Bayesian implementation of Factor/Loading Adaptive Shrinkage
#' (FLASH). The key idea in FLASH is that the factors and/or loadings may be modeled using
#' the adaptive shrinkage framework of Stephens (2016).
#'
#' The model is
#' \dqn{Y = AB + E,}
#' where \eqn{A} are the loadings and \eqn{B} are the factors. The error term, \eqn{E}, is
#' assumed to be independent Gaussian with either homoscedastic or column-specific heteroscedastic
#' noise. FLASH performs mean-field variational inference on to derive an approximation to
#' the posterior of \eqn{A} and \eqn{B} when either using normal or flexible mixture priors.
#' When using the mixture priors, the mixing proportions are jointly estimated with the
#' variational densities of \eqn{A} and \eqn{B}.
#'
#' Because empirical Bayes method (when estimating the mixing proportions) induces group sparsity
#' in the factors, FLASH provides a natural way to estimate the rank of the underlying mean
#' matrix. If the observed factors turn out to be completely dense, this should tell you that
#' you should try a larger value \code{maxrank}.
#'
#' @param Y The observed data matrix.
#' @param maxrank The maximum allowable rank.
#' @param loadings Should we apply the ASH prior to the loadings (\code{"sparse"}),
#'     or an equivariant normal prior (\code{"equivariant"})?
#' @param errors What should the error model be? Should it be homoscedastic
#'     (\code{"homoscedastic"}) or heteroscedastic columns (\code{"heteroscedastic"})?
#'
#' @author David Gerard
#'
#' @export
#'
#' @references Stephens, M. (2016). False discovery rates: a new deal. Biostatistics, kxw041.
#'
flash <- function(Y, maxrank, loadings = c("sparse", "equivariant"),
                  factors = c("sparse", "equivariant"),
                  errors = c("homoscedastic", "heteroscedastic")) {

}