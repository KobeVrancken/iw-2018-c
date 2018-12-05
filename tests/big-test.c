%%%%%%%%%% ABOUT THIS DOCUMENT AND DISCLAIMER %%%%%%%%%%
This is _not_ a comprehensive test suite, but rather serves to demonstrate some
edge cases to help you test your solution.

Merely producing the expected output for this file does _not_ guarantee your
project solution is correct. You are strongly advised to write your own
additional test files to thoroughly test your code.

That being said, lets go to the fun part and trigger some preprocessor
functionality!

%%%%%%%%%% LINE COMMENTS %%%%%%%%%%




Here comes a line comment at the end of a line: 
The following line comment 

You should also be able to handle tab characters

%%%%%%%%%% BLOCK COMMENTS %%%%%%%%%%

A block comment can start in the middle of a line and everthing is printed again


tab, but they are
not always followed by a space.


and this should be visible again

%%%%%%%%%% WARNING PREPROCESSOR DIRECTIVE %%%%%%%%%%


should always continue printing after omitting a warning

%%%%%%%%%% ERROR PREPROCESSOR DIRECTIVE %%%%%%%%%%


if the -e flag was given, the preprocessor should terminate and stop printing after omitting the error
this may should thus never be printed

%%%%%%%%%% DEFINE PREPROCESSOR DIRECTIVE %%%%%%%%%%

Lets try defining some stuff:

Note that value strings can be arbitrarily long and contain spaces:

Note that keys and values may be separated by arbitrarily many spaces and tabs

Note that it is also allowed to define keys with empty values
Occurences of should be stripped.

The following word should be replaced with my_value right here: my_value 
And it should also work for the following foo sentence: Lorem ipsum dolor sit amet, consectetur adipiscing elit 
Dont forget replacements may occur in the middle ( this is the value	for the	bar key ) of a sentence

The following define within a block comment should be ignored

...but block comment should have ended by now

The following line-commented define should also be ignored

...Hence, NOKEY1 and NOKEY2 should not be substituted.

Redefining keys with the same value should be fine
Redefining keys with a new value should produce a warning

%%%%%%%%%% UNDEF PREPROCESSOR DIRECTIVE %%%%%%%%%%

Undefining a non-existing key should be silently ignored, like this:

After undefining an existing key, subsequent occurences should not be replaced anymore:
The following word should not be replaced: FOO

And it should also still work for the following sentence: this is the value	for the	bar key 
...But now not anymore: ANOTHER_KEY_BAR 

Redefining an undefined key should be fine now
This should be properly replaced: another_value 
