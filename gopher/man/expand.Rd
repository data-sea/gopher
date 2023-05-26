\name{expand}
\alias{expand}
\docType{package}
\title{
Simple function using Rcpp
}
\description{
expand()- takes any number of input vectors (of type character, numeric, or integer and outputs all possible vector combinations as a data frame.
}
\usage{
expand(inputVectors)
}
\examples{
\dontrun{
 ## expand() takes any character, numeric, or integer vectors as list or dataframe.
     expand(list(1:5, c(6,7), "a", "b", "c"))

     possible_names<- data.frame("first_name"=c("Tom","Jim"),
                         "last_name"=c("Jones", "Timms"))
     expand(possible_names)
}
}
