# gopher
R package with helper function `expand()` for finding all combinations of vector values. 
- Output should be a list of vectors or a data frame.
- Vectors can be any length.
- Similar to `tidyr::expand_grid()`, but uses the same column naming convention as `base::expand.grid()`.


```r
#simple example
l<-list (a = 1:5,
      b = c(6,7,8),
      c = c("d", "e"))
> expand(l)
```

