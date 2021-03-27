# 1.c

This one was simple enough at first look, but soon turned out to be a tricky one. The problem was figuring out what to put in the for loop. I finally figured it out, but I don't like it really. Too ugly, too much duplication there. But it works.

# 2.c

This one was similar to the first one, in the sense it took me some time to figure out how to do it. I thought of many ways of how to figure it out, got even close to the current approach I used finally, but it took some time(2 hours precisely 🤓). BUt I figured it out in the end. The solution wasn't very straightforward.  One other part that took some time was to set the condition to `start < end` or `start <= end`. So I tested with both conditions, and 1st one seemed to work

# 3.c

This one was officially hard, partly because my thought process wasn't clear enough. I instantly thought of binary search, but got sidetracked on figuring out a way to get the middle value as coordinates in the matrix. That's where most of my time was wasted. So I finally had to look up internet for binary search Algo on Google for some clarity about the process(For clarification, I looked at articles which used JavaScript, and a single-dimension array. Looking at direct C code would have taken the fun out of it.). Reading the article through, I got the idea that I had been doing it wrong. I was using pointers, which made the matrix a single dimension array(kind of), only where the programmer had to enforce practises to maintain its integrity, the program wouldn't do it. So I rewrote the whole code, and voila! It became binary search over a linear array in the end. And the complexity of it, I believe is `O(logn)`, so hurrah!