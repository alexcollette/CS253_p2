match -- simple pattern matcher


USAGE
--------
$make -all

$match [-i] pattern < file
ex.
$match foo < testdata.txt     #Case Sensitive
$match -i FOO < testdata.txt  #Case Insensitive




DESCRIPTION
-------------
The match utility reads lines of text from stdin and prints only those lines of text 
containing a string matching the speciﬁed pattern (similar to fgrep) to stdout. A 
line whose text includes a matching string is said to match the pattern. Lines that 
do not match are not printed. Lines containing one or more matches are are printed 
only once. A pattern is a simple string (akin to fgrep); regular expressions are not 
supported. Unlike fgrep, match always reads from stdin; there is no support for 
ﬁlenames as command-line arguments. By default, match is case-sensitive; the pattern 
“foo” will match lines containing the string “foo” but not lines containing “Foo” nor 
“FOO”. However, use of the -i option enables case-insensitive matching in which the 
patterns “foo” and “FOO” and “Foo” will all match a line containing the string “Foo”.

