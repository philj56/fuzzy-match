# Simple fuzzy matcher in under 100 lines of C

This is an extremely simple, improved implementation of v0.2.0 of
[`fts_fuzzy_match`](https://github.com/tajmone/fuzzy-search), originally
written by [Forrest Smith](https://github.com/forrestthewoods) and discussed in
[Reverse Engineering Sublime Text’s Fuzzy
Match](https://www.forrestthewoods.com/blog/reverse_engineering_sublime_texts_fuzzy_match/).

Improvements over the original version:

- Simpler and easier to understand code (and much less of it).
- No need for a forced recursion limit, so this version will always find the
  optimal match (although you may run out of stack space if you try to match a
  5000+ character long search pattern).
- Performance is possibly ever so slightly better (anecdotally, matching "LLL"
  against a list of 355,000 English words takes 26-33ms, versus 33-35ms for the
  original version).
- [C, glorious C](https://www.youtube.com/watch?v=tas0O586t80).

If you want to learn more, there's much more documentation and a collection of
ports of the algorithm (including this one) to different languages at
https://github.com/tajmone/fuzzy-search.

## Testing

The file [`main.c`](main.c) contains a simple utility to read newline-separated
entries from `stdin`, match them against a pattern passed as an argument, and
print the matches and their scores (higher is better) to `stdout`:

```sh
make

echo "
llamas
carella
LogList
crumpets
aVeryLongNameThatContainsTwoLs.c
" | ./fuzzy_match ll
```

Output:
```
126|llamas
95|carella
140|LogList
115|aVeryLongNameThatContainsTwoLs.cs
```
