# t9Dictionary
t9Dictionary using trie and file data structure.                                                                                           
T9 is a technology used on many mobile phones to make typing text messages easier.                                                         
• The idea is simple - each number of the phones keypad corresponds to 3-4 letters of the alphabet.
• Many phones will notice when you type in a word that is not in its dictionary, and will add that word. Others keep track of the           frequency of certain words and favor those words over other words that have the same sequence of keypresses.                             
                                                                                                                                           
How does a T9 dictionary work?                                                                                                             
• It can be implemented in several ways, one of them is Trie. The route is represented by the digits and the nodes point to collection of   words.
• T9 works by filtering the possibilities down sequentially starting with the first possible letters.
