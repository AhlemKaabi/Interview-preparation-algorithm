#include <stdbool.h>
#include <stdio.h>

// The main function that checks if two given strings
// match. The first string may contain wildcard characters
int wildcmp(char *s1, char *s2)
{
	// If we reach at the end of both strings, we are done

	// Make sure that the characters after '*' are present
	// in second string. This function assumes that the
	// first string will not contain two consecutive '*'


	// If there is *, then there are two possibilities
	// a) We consider current character of second string
	// b) We ignore current character of second string.
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}