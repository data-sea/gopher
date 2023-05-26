\name{gopher-package}
\alias{gopher-package}
\alias{gopher}
\docType{package}
\title{
  A data utility package
}
\description{
  This package included the `expand()` function.
}
\details{
  expand() - takes any number of input vectors (of type character, numeric, or integer and outputs all possible vector combinations as a data frame.)
}
\author{
David Christensen, david.christensen@spl.org


}

\keyword{ package }
\seealso{
  expand.grid()
}
\examples{
  \dontrun{
     ## expand() takes any character, numeric, or integer vectors
     expand(list(1:5, c(6,7), "a", "b", "c"))
  }
}
