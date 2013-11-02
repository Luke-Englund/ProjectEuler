Project Euler Solutions
=======================

>\#35 Circular Primes

A little warm-up problem that finds all of the circular primes under 1,000,000.

>\#121 Disk Game Prize Fund

A fun little combinatorial problem in the form of a carnival game.

>\#208 Robot Walks

This one was posed to me by a co-worker.  I had already solved two Euler problems that he suggested that day and felt pretty confident going into this one.  It took allot more thought but I eventually came up with an algorithm that solved the cases up to 25 steps.  I thought I had it beat so I ran the 70 step case.  It never finished!  Haha!  It ran in exponential time; correct but impractical.

The next step is to bin the valid paths.  Depending upon its symmetry a path can be one of 70 identical paths with different starting points.  I should be able to only count these groups and multiply each one by its corresponding symmetry.  This only cuts it by a factor of N though making O(2^N/N) or something close.  That won't cut it either so we'll see what the next step after that is.
