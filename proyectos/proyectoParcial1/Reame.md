1094. E-screen
Time limit: 0.25 second
Memory limit: 64 MB
A new one-line electronic screen (e-screen) especially designed for quick input and change of information was installed at a supermarket. All information is entered by an operator. Every time the operator presses a button corresponding to a symbol this symbol is shown on the e-screen at the position where the cursor is located at that moment (therefore the symbol that was shown at that position earlier is erased) and then the cursor moves one position to the right.
The keyboard contains letters a-z, A-Z, digits 0-9, punctuation signs (:;-!?.,), and the space button. There are also two keys that move the cursor one position to the right and to the left without erasing anything. The width of the screen is 80 symbols. When the cursor reaches left or right edge of the screen it is automatically placed at the first position to the left.
The new e-screen had worked perfectly when it was run by its seller, but when the seller had gone it was found that nobody could operate the e-screen properly. Besides, the e-screen was installed in such a place that the operator could not see it. Your task is to make a program emulation of the e-screen so that the operator could see the results of his or her actions.
Input
The single line of the input contains a sequence of the buttons pressed by the operator. The symbol '>' stands for the move of the cursor one position to the right and the symbol '<' stands for the move of the cursor one position to the left. There are no more than 10000 symbols at the input.
Output
The output should contain the line that would be shown on the e-screen after pressing the given sequence of the buttons. Assume that at the beginning the e-screen contains 80 spaces and the cursor is placed at the first position to the left.
Sample
input

>><<<Look for clothes at the <<<<<<<<<<<<<<<second flo
or. <<<<<<<Fresh pizza and <<<<<<<<<<<<<<<<hamburger a
t a shop right to <<<<<<<<<<<<<the entrance. Call <<<<
<<<<<< 123<-456<-8790 <<<<<<<<<<<<<<<<to order <<<<<<<
<<<<<<<<<<computers< and office<<<<<<< chairs.

output

Look for second hamburger at computer and chairs.790                            

Problem Author: Stanislav Vasilyev
Problem Source: USU Open Collegiate Programming Contest March'2001 Senior Session