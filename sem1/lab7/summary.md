# 1.c

This one was very straightforward. Same as the one  showed in the demo, only difference was replacing + with * and renaming the functions, changing verbage, etc.

# 2.c

This one took more time, as I tried to reuse the code from `1.c`. It would've been better to just write the code from scratch, as I struggled for a minute with the return types, and also to where to place the `printf` statements, and where to put the `base case`

# 3.c

This one was very confusing. The function itself was very easy to implement, took only 1 minute for the `nCr` function. I didn't want to define factorial functions and deal with 3 factorials in the recursive part of the function, so I reduced the nCr to its other, simpler form with only 2 terms:

```
nCr = n/r * (n - 1)/(r - 1) * (n - 2)/(r - 2) * (n - 3)/(r - 3) * ... * (n - r -1) / 1
```

But there was a very weird problem happening with `5C2`, as the answer was coming out to be 8, whereas it should've been 10. So I took some help from you, and found out the problem was in the (n/r) step. n was int, r was int, so the division wouldn't be a float, and 5/2 would become 2, rather than 2.5. SO I just multiplied 1.0 to `n`. That helped.