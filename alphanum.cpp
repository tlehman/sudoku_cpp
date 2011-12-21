    
const int UPPER_MIN = 65;
const int UPPER_MAX = 90;
const int LOWER_MIN = 97;
const int LOWER_MAX = 122;
const int LOWER_UPPER_DIFF = 32;
const int ALPHA_RANGE = 26;

bool isupper(char c)
{
    if(c >= UPPER_MIN && c <= UPPER_MAX) return true;
    else return false;
}

bool islower(char c)
{
    if(c >= LOWER_MIN && c <= LOWER_MAX) return true;
    else return false;
}

char tolower(char c)
{
    if(isupper(c))
    {
       c += LOWER_UPPER_DIFF;
       return c;
    }
    else return c;
}
char toupper(char c)
{
    if(islower(c))
    {
        c -= LOWER_UPPER_DIFF;
        return c;
    }
    else return c;
}

bool isnumber(char n)
{
    if(n >= 48 && n <= 57) return true;
    else return false;
}
