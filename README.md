# wordle-solver
"Wordle" game solver/cheater, but works on word of any length.

This project solves word games like "Wordle", but work on any word length.
Example: given a 5-letter word (desired result: "hello"), know the letter “h" and its position, know the letter "o" and its position, know the letter "e" and "l" but don't know their position. Example input:" ./wordle-driver h---o e ". The unknown letters are inputed as "-", known position letters are inputed directly, know letters without positions are inputed following the word.
Then the program gives all possible words fitting the requirement.

The runtime is tested and very ideal.
