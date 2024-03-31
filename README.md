# Roman-Numerals
Coding Challenge for BYU OIT AppEng. Converts user input from decimal to Roman numerals, and vice versa.

Compiled using C++17. 

Difficulties in development:
  At first, when I tried to write the "to_decimal" function, I was complicating it quite a lot. I tried using stacks because I thought it would make it easier to identify cases where one numeral would be repeated more than three times. I realized that I could program it a lot easier if I just didn't worry about that, as the website https://numeralsconverter.com/ didn't either. Instead of stacks, I was just able to add each value to the final return value, which made it so I only needed to worry about subtractive cases. 
  That was the hardest part of the to_decimal function it took me a while to write out "if (number * 10 < previous || previous - number == number || (previous - number) % 100 == number)" because I wanted to make sure that I was correctly raising errors for every case and it was tough exploring each case and what I could do to combat each one.
  The "to_roman" was initially easier for me. One thing I tried was using a map instead of two vectors, so I wrote out the whole thing before realizing I wouldn't be able to access the ith index of the map and had to go back to what I had originally. 
  Overall, the most time-consuming portion of the challenge was making sure that my program worked correctly. I would test a few things, fix my code, and think it is finished, but then think of something else that could break my code and have to fix it. At first, I also wanted to implement file reading, so that it would be able to read files full of numbers, like what would be on the tablets. Once it had already taken me long enough, I didn't feel like it was as important but it is definitely easily implementable.

  The challenge took me a total of ~2.5 hours.
