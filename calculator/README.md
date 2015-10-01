# String Calculator

1. Create a simple String calculator with a method int Add(string numbers) :ballot_box_with_check:
  1. The method can take 0, 1 or 2 numbers, and will return their sum (for an empty string it will return 0) for example `“”` or `“1”` or `“1,2”` :ballot_box_with_check:
  2. Start with the simplest test case of an empty string and move to 1 and two numbers :ballot_box_with_check:
  3. Remember to solve things as simply as possible so that you force yourself to write tests you did not think about :ballot_box_with_check:
  4. Remember to refactor after each passing test :ballot_box_with_check:
2. Allow the Add method to handle an unknown amount of numbers :ballot_box_with_check:
3. Allow the Add method to handle new lines between numbers (instead of commas). :ballot_box_with_check:
  1. the following input is ok:  `“1\n2,3”`  (will equal 6) :ballot_box_with_check:
  2. the following input is NOT ok:  `“1,\n”` (not need to prove it - just clarifying) :ballot_box_with_check:
4. Support different delimiters
  1. to change a delimiter, the beginning of the string will contain a separate line that looks like this:   `“//[delimiter]\n[numbers…]”` for example `“//;\n1;2”` should return three where the default delimiter is ‘;’ . :ballot_box_with_check:
  2. the first line is optional. all existing scenarios should still be supported :ballot_box_with_check:
5. Calling Add with a negative number will throw an exception “negatives not allowed” - and the negative that was passed. If there are multiple negatives, show all of them in the exception message :ballot_box_with_check:
6. Numbers bigger than 1000 should be ignored, so adding 2 + 1001  = 2 :ballot_box_with_check:
7. Delimiters can be of any length with the following format: ` “//[delimiter]\n”` for example: `“//[***]\n1***2***3”` should return 6 :ballot_box_with_check:
8. Allow multiple delimiters like this:  `“//[delim1][delim2]\n”` for example `“//[*][%]\n1*2%3”` should return 6. :ballot_box_with_check:
9. Make sure you can also handle multiple delimiters with length longer than one char :ballot_box_with_check:
