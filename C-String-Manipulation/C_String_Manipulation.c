/////////////////////FUCTION ONE///////////////////////////////

/* 
 * An implementation of the reverse_in_place function
 *
 * Author: Okemawo Aniyikaiye Obadofin (OAO)
 * 
 * Date: 19th November 2022
 *  
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


/*
 * Reverses a null-terminated string in place, converting it to all
 * lower case in the process.
 *
 * Examples:
 *
 *  "Carnegie Mellon" "nollem eigenrac"
 *  "Four"            "ruof"
 *  " One"            "eno "
 *
 * Parameters:
 *   str   A null terminated string to reverse
 * 
 * Returns:
 *   void
 */

void reverse_in_place(char *str)
{
  int f = 0;
  int b = 0;
  char temp;
  for (b=0; str[b] != '\0'; ++b)
    str[b] = tolower(str[b]);
  --b;
  while (f < b) {
    temp = str[b];
    str[b--] = str[f];
    str[f++] = temp;
  }
}


/*
 * Tests the reverse_in_place function, once
 *
 * Parameters:
 *   input      The string to pass to reverse_in_place
 *   expected   The string expected out of reverse_in_place
 * 
 * Returns:
 *   true if the test passes, false otherwise
 */
bool test_reverse_in_place_once(char *input, char *expected)
{
  // create a variable to hold input
  char buffer[512];

  // copy input to buffer to avoid segmentation fault
  strcpy(buffer, input);
  reverse_in_place(buffer);
 
  // compares result from coparison to determine if the expected output is thesame 
  // as the mutated variable and return a bool (True or false)
  if (strcmp(buffer, expected) != 0) {
    printf("Test error: converting '%s', actual result '%s', expected '%s'\n",
        input, buffer, expected);
    return false;
  } else {
    return true;
  }
}


/*
 * Performs unit tests of the reverse_in_place functions
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */
bool test_reverse_in_place()
{ 
  // Test cases
  bool success = true;
  if (!test_reverse_in_place_once("Carnegie Mellon", "nollem eigenrac"))
      success = false;
  if (!test_reverse_in_place_once("Four", "ruof"))
      success = false;
  if (!test_reverse_in_place_once(" One", "eno "))
      success = false;
  if (!test_reverse_in_place_once("One", "eno"))
      success = false;
  if (!test_reverse_in_place_once("    ", "    "))
      success = false;
  if (!test_reverse_in_place_once(" ", " "))
      success = false;
  if (!test_reverse_in_place_once("", ""))
      success = false;
  if (!test_reverse_in_place_once(".", "."))
      success = false;
  if (!test_reverse_in_place_once("\0\0", "\0\0"))
      success = false;
  if (!test_reverse_in_place_once(" ONE ", " eno "))
      success = false;
  return success;
}






/////////////////////FUCTION TWO///////////////////////////////





/*
 * An implementation of reverse by word function
 *
 * Author: Okemawo Aniyikaiye Obadofin (OAO)
 *
 * Date: 19th November 2022
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


/*
 * Individually reverses each word of a null-terminated string in place. Whitespace characters (as
 * identified by the C isspace() function) are passed through unchanged.
 *
 *
 * Examples:
 *   str                        Returns
 *   Carnegie␣Mellon            eigenraC␣nolleM
 *   \tCarnegie␣␣Mellon         \teigenraC␣␣nolleM
 *   Four                       ruoF
 *   ␣One                       ␣enO
 *   My␣heart␣is␣in␣␣the␣work   yM␣traeh␣si␣ni␣␣eht␣krow
 *
 */

void reverse_by_word(char *str)
{
  // variable declaration
  int f = 0;
  int len_str = 0;
  int beg_word = 0;
  int end_word = 0;
  char temp;

  // Obtain the length of entire string
  for (len_str=0; str[len_str] != '\0'; ++len_str)
    ;

  // Loop from 0 untill the length of 'str'
  while (f <= len_str)
  {
    // checks if the string is a space or a null termination
    if ((isspace(str[f])) | (str[f] == '\0'))
    {
      // Decrement f and set it as end of end word
      end_word = --f;

      // loops from start of word to end
      while (beg_word < end_word)
      {
        // swaps variables to reverse word
        temp = tolower(str[end_word]);
        str[end_word] = (str[beg_word]);
        str[beg_word] = temp;
        end_word--;
        beg_word++;
      }
      // Increment loop variable f back to former location
      // where the space was found
      f++;

      // Set begining of new word to the next position after
      // where the space or '\0' was found and sets end of word to 0
      beg_word = f + 1;
      end_word = 0;
    }

    // increment loop variable to next position
    // of the char to check
    f++;
  }
}

/*
 * Tests the reverse_by_word function, once
 *
 * Parameters:
 *   input      The string to pass to reverse
 *   expected   The string expected out of reverse_by_word
 *
 * Returns:
 *   true if the test passes, false otherwise
 */

bool test_reverse_by_word_once(char *input, char *expected)
{
  char buffer[512];
  strcpy(buffer, input);
  reverse_by_word(buffer);
  if (strcmp(buffer, expected) != 0) {
    printf("Test error: converting '%s', actual result '%s', expected '%s'\n",
        input, buffer, expected);
    return false;
  } else {
    return true;
  }
}


/*
 * Performs unit tests of the reverse_by_word_once functions
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */

bool test_reverse_by_word()
{
  bool success = true;
  if (!test_reverse_by_word_once("Carnegie Mellon", "eigenraC nolleM"))
      success = false;
  if (!test_reverse_by_word_once("\tCarnegie  Mellon", "\teigenraC  nolleM"))
      success = false;
  if (!test_reverse_by_word_once("Four", "ruoF"))
      success = false;
  if (!test_reverse_by_word_once(" One", " enO"))
      success = false;
  if (!test_reverse_by_word_once("My heart is in the work", "yM traeh si ni eht krow"))
      success = false;
  if (!test_reverse_by_word_once("Linux  is  hard  but  c  is  harder", "xuniL  si  drah  tub  c  si  redrah"))
      success = false;
  if (!test_reverse_by_word_once("    Are    We    There    Yet", "    erA    eW    erehT    teY"))
      success = false;

  return success;
}





/////////////////////FUCTION THREE///////////////////////////////





/*
 * An implementation of is_prefix function
 *
 * Author: Okemawo Aniyikaiye Obadofin (OAO)
 *
 * Date: 19th November 2022
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>




/*
 * Returns true if str begins with prefix, and false otherwise. Both prefix and str are null-terminated
 * strings. Note the empty string “” is a valid prefix for all strings.
 *
 *
 * Examples:
 *
 * prefix           str                 Returns
 * C                Carnegie␣Mellon     true
 * Carnegie         Carnegie␣Mellon     true
 * Carnegie␣Mellon  Carnegie␣Mellon     true
 * Cab              Carnegie␣Mellon     false
 *
 */

bool is_prefix(const char *prefix, const char *str)
{
  // Declare variables
  int s = 0;
  bool status = true;

  // Loops from the begining of prefix to null termination
  for (s=0; prefix[s] != '\0'; ++s)
    {
     // Checks haracter for both prefix and string and compare
     if (prefix[s] == str[s]) {
       // Continue loop if the test passes
       continue;
    }else {
       // Set status to false if the test failed even once
       // then break
       status = false;
       break;
    }
  }
  // status is true if all characters of the prefix were matched
  return status;
}



/*
 * Tests the in_prefix function, once
 *
 * Parameters:
 *   prefix     The prefix to check for by is_prefix
 *   str        The string to check against by is_prefix
 *   expected   The boolean return value of true or false
 *
 * Returns:
 *   true if the test passes, false otherwise
 */

bool test_is_prefix_once(const char *prefix, const char *str, bool expected)
{
  bool result = is_prefix(prefix, str);
  bool status;
  char buffer2[512];
  char buffer1[512];

  strcpy(buffer1, prefix);
  strcpy(buffer2, str);

  if (result == expected)
  {
    status = true;
    return status;
  }
  else
  {
    printf("Test error: checking if '%s' is a valid prefix of '%s'. but got \n ", buffer1, buffer2);
    status = false;
    return status;
  }
}


/*
 * Performs unit tests of the reverse_in_place functions
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */

bool test_is_prefix()
{
  bool success = true;

  if (!test_is_prefix_once("Ca" ,"Carnegie  Mellon", true))
      success = false;
  if (!test_is_prefix_once("Carnegie" ,"Carnegie Mellon", true))
      success = false;
  if (!test_is_prefix_once("Carnegie " ,"Carnegie  Mellon", true))
      success = false;
  if (!test_is_prefix_once("Carnegie" ,"Carnegie  Mellon", true))
      success = false;
  if (!test_is_prefix_once("Mell" ,"Carnegie  Mellon", false))
      success = false;
  if (!test_is_prefix_once("  Car" ,"  Carnegie  Mellon", true))
      success = false;


  return success;
}





/////////////////////FUCTION FOUR///////////////////////////////





/*
 *
 * An implementation of remove_last_substr function
 *
 * Author: Okemawo Aniyikaiye Obadofin (OAO)
 *
 * Date: 19th November 2022
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>




/*
 *
 * Removes the last occurrence of substr from str, modifying the result in place. Returns the
 * character position where the removal occurred, or -1 if substr was not found in str. Note that
 * substr need not be a full word.
 *
 *
 * Examples:
 *
 * str                  substr              Result              Returns
 * Carnegie␣Mellon      Carnegie␣           Mellon              0
 * Carnegie␣Mellon      Kiltie              Carnegie␣Mellon     -1
 * Carnegie␣Mellon      “”                  Carnegie␣Mellon     14
 * one␣two␣one␣three    one␣                one␣two␣three       8
 * one␣two␣one␣three    hr                  one␣two␣one␣tee     13
 *
 *
 */


int remove_last_substr(char *str, const char *substr)
{
  // Declare variables
  char temp;
  int s = 0;
  int x = 0;
  int b = 0;
  int len = 0;
  int value = 0;
  bool set = false;
  bool status;

  // Get lenght of string
  for (b=0; str[b] != '\0'; ++b)
    ;

  // Get length of substring
  for (len=0; substr[len] != '\0'; ++len)
    ;

  --len;

  // Checks for match of substring for each iteration of loop
  for (x=0; x < b; x++)
  {

    status = true;
    // Loops runs for the length of the substring
    for (s=0; substr[s] != '\0'; ++s)
    {
      // compares the characters of substring to input string
      // Also, x is incremented with each iteration of the  external for loop in order
      // to shift preceeding character and check for pattern
      if (substr[s] == str[s+x]) {
        continue;
      }else {
        // sets status to false if a match is not found for the substring
        status = false;
      }
    }
    // End of for loop

    // Pattern was found if status remained true
    if (status == true)
    {
      // sets value to x to save location where pattern was found
      value = x;
      // sets set to true to confirm that a pattern was found atleast once
      set = true;
    }
  }
  // End of for loop

  // Check if set is true
  if (set == true)
  {

    int z = 0;
    // iterates through each character and skips the position where the substring was matched
    for (s=0; s < b; ++s)
    {
      // When the iteration variable matched the parameter for value, characters equivalent
      // to the length of the substring is skipped
      if (s == value)
      {
        s += len;
        continue;
      }
      else
      {
        // copies the values of the input string that does not match the substring
        temp = str[s];
        str[z] = temp;
        z++;
      }
    }
    // Add a null terminated value
    str[b-len-1] = '\0';

    // Return position where substring is found last
    return value;
  }
  // returns -1 when the substring is not matched
  return -1;
}



/*
 * Tests the remove_last_substr function once
 *
 * Parameters:
 *   substring  The substring to remove
 *   str        The string to be mutated
 *   expected   The output of the mutated string
 *
 * Returns:
 *   true if the test passes, false otherwise
 */

bool test_remove_last_substr_once(char *str, const char *substr, char *expected, int ret)
{
  char buffer1[512];
  char buffer2[512];
  int result;

  strcpy(buffer1, str);
  strcpy(buffer2, substr);
  result = remove_last_substr(buffer1, buffer2);

  // Checks correctness of string returned and return value
  if ((strcmp(buffer1, expected) == 0) && (result == ret))
    return true;
  else
  {
    printf("error removing %s from %s return is %d \n", buffer2, buffer1, result);

    return false;
  }
}



/*
 * Performs unit tests of the remove_last_substr_once function
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */

bool  test_remove_last_substr()
{
  bool success = true;
  if (!test_remove_last_substr_once("one two one three", "one ", "one two three", 8))
      success = false;
  if (!test_remove_last_substr_once("Carnegie Mellon", "Carnegie ", "Mellon", 0))
      success = false;
  if (!test_remove_last_substr_once("Carnegie Mellon", "Kiltie", "Carnegie Mellon", -1))
      success = false;
  if (!test_remove_last_substr_once("one two one three", "hr", "one two one tee", 13))
      success = false;

  return success;
}






/////////////////////FUCTION FIVE///////////////////////////////





/*
 *
 * An implementation of first word function
 *
 * Author: Okemawo Aniyikaiye Obadofin (OAO)
 *
 * Date: 19th November 2022
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
 *
 * Returns the first word from input, removing leading whitespace. We will built upon this function
 * in a subsequent assignment as we write our own Linux shell.
 * When called, word points to a buffer of word_len length. After skipping leading whitespace, the
 * first_word function copies the first word from input into the word buffer and returns the number
 * of characters that were processed from input. In the case where input holds more than one
 * word, it is possible to read the next word by calling first_word again with the pointer
 * input+return_value.
 *
 * In the case that the word buffer is not long enough, first_word places the error message “Word
 * too long” into the buffer and returns -1.
 *
 *
 * Examples:
 * input                    Result (in word)                    Returns
 * ␣␣␣echo␣                 echo                                7
 * grep                     grep                                4
 * \techo␣one␣two␣three     echo                                5
 * (empty string)           (empty string)                      0
 *
 */

int first_word(const char *input, char *word, int word_len)
{
  //Declare variable
  int b;
  bool set = false;
  int size = 0;

  // Loop to iterate through input and determine size of first word
  for (b=0; input[b] != '\0'; ++b)
  {
    // Checks if character is a space
    if (isspace(input[b]))
    {
      // set is true when a character was found, therefore if set is checked to be true
      // the loop breaks
      if (set == true)
        break;
      else
        continue;
    }
    else
    {
      // if character is not a white space, then it is a character. set is true here
      // we will increment size everytime we encounter a character
      set = true;
      ++size;
      //*word++ = input[b];
    }
  }

  // check if the size of word is greater than the word lenght available for word
  if (size > word_len)
  {
    word = "Word too long";
    return -1;
  }
  else
  {
    set = false;

    // Loop to iterate through input and copies the first word into word

    for (b=0; input[b] != '\0'; ++b)
    {
      if (isspace(input[b]))
      {
        if (set == true)
          break;
        else
          continue;
      }
      else
      {
        set = true;
        *word++ = input[b];
      }
    }
  // Adds a null termination to word
  *word = '\0';
  }
  // return the position last word ends
  return b;
}





/*
 *
 * Parameters:
 *   input      The string to get first word from
 *   word       The buffer to copy first word
 *   word_len   The size of word
 *   expected   The expected first word
 *   ret        The return value
 *
 * Returns:
 *   true if the test passes, false otherwise
 */

bool test_first_word_once(const char *input, char *word, int word_len, char *expected, int ret)
{
  char buffer[512];
  int result;
  strcpy(buffer, input);

  result = first_word(buffer, word, word_len);
  if ((result != ret) && (word != expected))
    return false;
  else
    return true;
}


/*
 * Performs unit tests of the first word function
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */

bool  test_first_word()
{
  bool success = true;

  char word[128];
  int word_len = sizeof(word);

  if (!test_first_word_once("   echo ", word, word_len, "echo", 7))
      success = false;
  if (!test_first_word_once("grep", word, word_len, "grep", 4))
      success = false;
  if (!test_first_word_once("\techo one two three", word, word_len, "echo", 5))
      success = false;
  if (!test_first_word_once("\"one two\" three ", word, word_len, "\"one", 4))
      success = false;
  if (!test_first_word_once("One Two Three", word, word_len, "One", 3))
      success = false;

  return success;
}




////////////////////////////MAIN FUNCTION///////////////////////////




int main(int argc, char *argv[])
{
  bool success = true;
  if (!test_first_word())
    success = false;
  if (!test_remove_last_substr())
    success = false;
  if (!test_is_prefix())
    success = false;
  if (!test_reverse_by_word())
    success = false;
  if (!test_reverse_in_place())
    success = false;



  if (success)
    printf("All tests succeeded\n");
  else
    printf("Test failures occurred\n");
}




