## Recursion And Master Theorem

Usually the expression for a recursion rinning time is something like

```
T(n) <= a * T(n / b) + O(n ^ d)
```

It means that we a doing a recursive calls, shrinking problem size by 1/ b and combine step for each subproblems takes O(n ^ d).

To analyze this we try first to evaluate amount of work on a recursiion tree level `j`.

It turns out that on level `j` we have `a ^ j` number of subproblems each of which does `(n / b ^ j) ^ d` amount of work. So it's

```
a ^ j * (n / b ^ j) ^ d = n ^ d * (a / b ^ d) ^ j
```

Amount of work per tree level. As we have `log(b, n)` level in the tree to get total work we sum 

```
total = n ^ d * sum([(a / b ^ d) * j for j in (0, log(b, n))])
```

So the key is a / b ^ d relation.

If a == b ^ d, the amount of work is the same on all levels of the tree.

If a > b ^ d, the amount of work increases with each level of the tree and total work is dominated by amount of work at the leaves. `O(#leaves)`

`a ^ log(b, n)` - that basically the number of leaves in the tree. (we assume that at each leaf we do a constant amount of work).

if a < b ^ d, the amount of work is decreasing with each level down the tree. So total work is dominated by top level, where we do `O(n ^ d)` work.