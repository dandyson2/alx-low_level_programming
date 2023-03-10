#include "main.h"

/**
 * _isalpha - check for alphabetical letters
 * @f : character to be checked
 * Return:0 or 1
 */

int _isalpha(int f)
{
return ((f >= 'a' && f <= 'z') || (f >= 'A' && f <= 'Z'));
}
