# Sum of odd cols, even rows

This one was fairly straightforward. Just a `if` within `for` within `for` was needed. Only thing to watch out for was remembering that indices are `-1` than regular matrix, so we had to apply different divisibility test than we'd do in regular maths.

# Variance

This one was straightforward too, but the footgun here was the fact that we always type everything `int` by default in C, so my code was giving out super weird answers. Then I realized my mistake and made evrything float(Not evrything, only where it was needed), and the issue was fixed.