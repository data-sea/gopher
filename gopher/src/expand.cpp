#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List expand(List inputVectors) {
//number of input vectors 
    int num_vectors = inputVectors.length();
//length of each vector  
    IntegerVector vectorLengths(num_vectors);
//names of output colums
    CharacterVector col_names(num_vectors);
// Vector of vector length multiples
    IntegerVector mult_Vector(num_vectors);
//Output 
    List output(num_vectors);
 
//get the input vector lengths and running multiples
 int mult = 1;
 for (int i = 0; i < num_vectors; i++) {
   //column names
   col_names[i] = std::string("v") + std::to_string(i + 1);
   //vector lengths
   switch( TYPEOF(inputVectors[i]) ) { 
   case REALSXP: {
     vectorLengths[i] = ((NumericVector)inputVectors[i]).length();
     }
   case INTSXP: {
    vectorLengths[i] = ((IntegerVector)inputVectors[i]).length();
     }
   case STRSXP: {
     vectorLengths[i] = ((CharacterVector)inputVectors[i]).length();
     }
   }
   //running multiples
   mult_Vector[i]=  vectorLengths[i] * mult;
   mult = mult_Vector[i];
 }

//product of vector lengths  
int product = *(std::end(mult_Vector)-1);
 
//build the expanded combinations  
  int l=0;
  for( List::iterator it = inputVectors.begin(); it != inputVectors.end(); ++it ) {
    switch( TYPEOF(*it) ) {
    case VECSXP: {
      *it = expand(*it);
      break;
    }
    case REALSXP: {
      NumericVector tmp(product);
      
      int combinations = product / vectorLengths[l];
      int mult_length = product / mult_Vector[l];
      int n = 0;
      for (int m = 0; m < combinations; m++) {
        for (int k = 0; k < vectorLengths[l]; k++) {
          for (int j = 0; j < mult_length && n < product; j++) {
            tmp[n] = ((NumericVector)inputVectors[l])[k];
            n++;
          }
        }
      }
      output[l]= tmp;
      l++;
      break;
    }
    case INTSXP: {
      if( Rf_isFactor(*it) ) break; // factors have internal type INTSXP too
      IntegerVector tmp(product);
      
      int combinations = product / vectorLengths[l];
      int mult_length = product / mult_Vector[l];
      int n = 0;
      for (int m = 0; m < combinations; m++) {
        for (int k = 0; k < vectorLengths[l]; k++) {
          for (int j = 0; j < mult_length  && n < product; j++) {
            tmp[n] = ((IntegerVector)inputVectors[l])[k];
            n++;
          }
        }
      }
      
      output[l]= tmp;
      l++;
      break;
    }
    case STRSXP: {
      CharacterVector tmp(product);
      
      int combinations = product / vectorLengths[l];
      int mult_length = product / mult_Vector[l];
      int n = 0;
      for (int m = 0; m < combinations; m++) {
        for (int k = 0; k < vectorLengths[l]; k++) {
          for (int j = 0; j < mult_length && n < product; j++) {
            tmp[n] = ((CharacterVector)inputVectors[l])[k];
            n++;
          }
        }
      }
      
      output[l]= tmp;
      l++;
      break;
    }
    default: {
      stop("incompatible SEXP encountered; only accepts lists containing lists, REALSXPs, and INTSXPs");
    }
    }
  }
  output.attr("names") = col_names;
  DataFrame df(output);
  
  return df;
  
}