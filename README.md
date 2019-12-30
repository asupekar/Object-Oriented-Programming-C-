All the character comparisons are case sensitive.
So cat is not a subsequence of Catty but Cat is.

Sequence:
If a word is less than 3 characters long, we do not initialize the word in the Sequence constructor.
States is defined as an enum with ACTIVE and INACTIVE members. Initially all the objects created are treated as ACTIVE

Extractor:
If no subsequence is provided, we return "No subsequence provided" message from the emit() call.
If the subsequence length is greater than word length or if subsequence is not a part of the word then we return
"subsequence is not a part of word" message from emit() call.
If the subsequence equals encapsulated word, we return "Both subsequence and word are equal" message from the emit()
call.

Class Requirements:
The object should be in ACTIVE state to invert.
Index i should be encapsulated randomly with the index being the range 0..word.length()-2 during object creation
Inversion functionality will live in Sequence class as all the child classes for Sequence will be calling invert()
State can be checked by the application programmer by calling getState()

Is your solution fully working or not? Briefly describe design decisions and class structure.
Sequence class is an abstract class which is inherited by Extractor, Repeater and Variator classes. Sequence class
includes inverter.h and invert is defined in the Sequence class which will be called by each child classes in the run
time.

Did you work on the extra credit problem? Briefly describe any issues or explain any assumptions made.
Yes.

How much time did you spend on the assignment?
2 weeks




