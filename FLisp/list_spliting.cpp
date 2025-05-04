#include "type.h"
#include <iostream>
#include <list>

// Split a string into a list of Flisp_Value. 
/* For example:
 * "(a b c)" -> [[a, b, c]]
 * "(a b (c d))" -> [[a, b, [c, d]]]
 */
Flisp_Value Flisp_List_Spliting(std::string s)
{
    std::list<Flisp_Value> l; // List to store the split values
    Flisp_Value v; // Variable to store the final result
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') { // If the current character is '(', start a new sublist
            int j = i;
            int count = 1; // Counter for matching parentheses
            while (count != 0) {
                if (j < s.length()) {
                    j++;
                    if (s[j] == '(') count++; // Increment counter for nested '('
                    if (s[j] == ')') count--; // Decrement counter for ')'
                }
            }
            // Recursively split the substring and add to the list
            l.push_back(Flisp_List_Spliting(s.substr(i + 1, j - i - 1)));
            i = j; // Move the index to the end of the processed substring
        }
        else if (s[i] == ' ') {
            continue; // Skip spaces
        }
        else {
            int j = i;
            // Find the end of the current token
            while (s[j] != ' ' && s[j] != ')' && j < s.length()) {
                j++;
            }
            Flisp_Value subs;
            // Set the token as a name and add to the list
            subs.set_value_as_a_name(s.substr(i, j - i));
            l.push_back(subs);
            i = j - 1; // Move the index to the end of the processed token
        }
    }
    v.set_value(l); // Set the list as the value of the result
    return v; // Return the result
} // The codes andcomments are offered by GitHub Copilot. 
