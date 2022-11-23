# gopher
R package with helper function `expand_vector()` for finding all combinations of vector values. 
- Output is a tibble.
- Tibble has column(s) equal to the number of input vectors.
- Vectors can be any length.
- Uses `rep()` to build the the combinations of vectors.
- Similar to `tidyr::expand_grid()`, but used the same column naming convention as `base::expand.grid()`.


```r
#simple example
a <- 1:3
b <- 4:5
> expand_vector(a,b)
# A tibble: 6 x 2
   var1  var2
  <int> <int>
1     1     4
2     1     5
3     2     4
4     2     5
5     3     4
6     3     5

