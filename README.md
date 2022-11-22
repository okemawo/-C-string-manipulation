# -C-string-manipulation

<br/>

## Name : C string Manipulation With Different Functions
## Author : Okemawo Aniyikaiye Obaodfin (OAO)
## Date : 19th November 2022
#### Description : 
#### The file '-C-string-manipulation' contains five functions that manipulate strings and characters in differnts ways, comments can be viewed in the c file for description of each function. 

#### Build Instructions : After copying the C file to your terminal, use the command "gcc -Wall -Werror C_String_Manipulation.c" to compile the c program and generate an 'a.out' executable file. Run this executable to test the string with some in-built test cases. 

<br/>


#### 1. Reverse in place: Reverses a null-terminated string in place, converting it to all lower case in the process.
  
   Examples:
  
    "Carnegie Mellon" "nollem eigenrac"
    "Four"            "ruof"
    " One"            "eno "
  

<br/>


#### 2. Reverse by word: Individually reverses each word of a null-terminated string in place. Whitespace characters (as identified by the C isspace() function) are passed through unchanged.
 
   Examples:
   
     Carnegie␣Mellon            eigenraC␣nolleM
     \tCarnegie␣␣Mellon         \teigenraC␣␣nolleM
     Four                       ruoF
     ␣One                       ␣enO
     My␣heart␣is␣in␣␣the␣work   yM␣traeh␣si␣ni␣␣eht␣krow

<br/>  

#### 3. Is prefix: Returns true if str begins with prefix, and false otherwise. Both prefix and str are null-terminated strings. Note the empty string “” is a valid prefix for all strings.
 
 
  Examples:
  
    prefix           str                 Returns
    C                Carnegie␣Mellon     true
    Carnegie         Carnegie␣Mellon     true
    Carnegie␣Mellon  Carnegie␣Mellon     true
    Cab              Carnegie␣Mellon     false
  

<br/>  


#### 4. Remove Last Substring: Removes the last occurrence of substr from str, modifying the result in place. Returns the character position where the removal occurred, or -1 if substr was not found in str. Note that substr need not be a full word.
 
 
   Examples:
  
    str                  substr              Result              Returns
    Carnegie␣Mellon      Carnegie␣           Mellon              0
    Carnegie␣Mellon      Kiltie              Carnegie␣Mellon     -1
    Carnegie␣Mellon      “”                  Carnegie␣Mellon     14
    one␣two␣one␣three    one␣                one␣two␣three       8
    one␣two␣one␣three    hr                  one␣two␣one␣tee     13
  

<br/>  

 

#### 5. First Word: Returns the first word from input, removing leading whitespace. We will built upon this function in a subsequent assignment as we write our own Linux shell. When called, word points to a buffer of word_len length. After skipping leading whitespace, the first_word function copies the first word from input into the word buffer and returns the number of characters that were processed from input. In the case where input holds more than one word, it is possible to read the next word by calling first_word again with the pointer input+return_value. In the case that the word buffer is not long enough, first_word places the error message “Word too long” into the buffer and returns -1.
 
 
   Examples:
  
    input                    Result (in word)                    Returns
    ␣␣␣echo␣                 echo                                7
    grep                     grep                                4
    \techo␣one␣two␣three     echo                                5
    (empty string)           (empty string)                      0

<br/>  
