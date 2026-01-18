#include <stdio.h>
#include <string.h> 

char str[50], pat[20], rep[20], res[50];
int c = 0, m = 0, i = 0, j = 0, k, flag = 0;

void stringmatch()
{
    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;
            // If we reached the end of the pattern string (Match Found)
            if (pat[i] == '\0')
            {
                flag = 1;
                // Copy replacement string into result
                for (k = 0; rep[k] != '\0'; k++, j++)
                {
                    res[j] = rep[k];
                }
                i = 0;
                c = m; // Update current position to skip the matched pattern
            }
        }
        else
        {
            // Mismatch: Copy current char from main string to result
            res[j] = str[c];
            j++;
            c++;
            m = c; // Reset matching pointer
            i = 0; // Reset pattern pointer
        }
    }
    res[j] = '\0'; // Null terminate the result string
}

void main()
{
    printf("Enter the main string:");
    gets(str);
    
    printf("\nEnter the pat string:");
    gets(pat);
    
    printf("\nEnter the replace string:");
    gets(rep);
    
    printf("\nThe string before pattern match is:\n %s", str);
    
    stringmatch();
    
    if (flag == 1)
        printf("\nThe string after pattern match and replace is: \n %s ", res);
    else
        printf("\nPattern string is not found");
}
