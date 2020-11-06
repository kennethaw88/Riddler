# How Many More Palindrome Dates Will You See? (7 February 2020)

https://fivethirtyeight.com/features/how-many-more-palindrome-dates-will-you-see

## Express

This past Sunday was Groundhog Day.
Also, there was a football game.
But to top it all off, the date, 02/02/2020, was palindromic, meaning it reads the same forwards and backwards (if you ignore the slashes).

If we write out dates in the American format of MM/DD/YYYY (i.e., the two digits of the month, followed by the two digits of the day, followed by the four digits of the year), how many more palindromic dates will there be this century?

## Classic

Also on Super Bowl Sunday, math professor Jim Propp made a rather interesting observation:

>I told my kid (who’d asked about absolute value signs) “They’re just like parentheses so there’s never any ambiguity,” but then I realized that things are more complicated; for instance |-1|-2|-3| could be 5 or -5. Has anyone encountered ambiguities like this in the wild?
>
>— James Propp (@JimPropp) February 3, 2020

At first glance, this might look like one of those annoying memes about order of operations that goes viral every few years — but it’s not.

When you write lengthy mathematical expressions using parentheses, it’s always clear which “open” parenthesis corresponds to which “close” parenthesis.
For example, in the expression (1+2(3−4)+5), the closing parenthesis after the 4 pairs with the opening parenthesis before the 3, and not with the opening parenthesis before the 1.

But pairings of other mathematical symbols can be more ambiguous.
Take the absolute value symbols in Jim’s example, which are vertical bars, regardless of whether they mark the opening or closing of the absolute value.
As Jim points out, |−1|−2|−3| has *two* possible interpretations:

* The two left bars are a pair and the two right bars are a pair. In this case, we have 1−2·3 = 1−6 = −5.
* The two outer bars are a pair and the two inner bars are a pair. In this case, we have |−1·2−3| = |−2−3| = |−5| = 5.

Of course, if we gave each pair of bars a different height (as is done in mathematical typesetting), this wouldn’t be an issue.
But for the purposes of this problem, assume the bars are indistinguishable.

How many different values can the expression |−1|−2|−3|−4|−5|−6|−7|−8|−9| have?
