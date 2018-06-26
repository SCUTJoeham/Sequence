#include "Sequence.h"
#include <algorithm>
#define MAXN 1500005
char c[MAXN], *a[MAXN];

int pstrcmp(const void *a, const void *b)
{
	return  strcmp(*(char * const*)a, *(char* const*)b);
}

Sequence::Sequence()
{
	sequence = "";
}

Sequence::Sequence(const char *filename)
{
	ifstream fin(filename, ios_base::in);
	string line;
	while (getline(fin, line))
		sequence += line;
}

int Sequence::length()
{
	return sequence.length();
}

int Sequence::numberOf(char base)
{
	int c1=0, c2=0, c3=0, c4=0;
	for (int i = 0; i < int(sequence.size()); i++)
	{
		if (sequence[i] == 'A')
			c1++;
		else if (sequence[i] == 'T')
			c2++;
		else if (sequence[i] == 'C')
			c3++;
		else if (sequence[i] == 'G')
			c4++;
	}

	switch(base)
	{
	case 'A': 
		return c1; break; 
	case 'T':
		return c2; break; 
	case 'C': 
		return c3; break; 
	case 'G':
	    return c4; break; 
	default: return -1;
	}
}

string Sequence::longestConsecutive() 
{
	string lg_con;
	int maxn = 1, tmp = 1;
	char m;
	int len = sequence.size();
	for (int i = len - 2; i > 0; i--)
	{
		if (sequence[i] == sequence[i + 1])
		{
			tmp++;
			maxn = max(maxn, tmp);
			if (maxn == tmp)
				m = sequence[i + 1];
		}
		else
		{
			maxn = max(maxn, tmp);
			tmp = 1;
		}
	}
	for (int i = 0; i < maxn; i++)
		lg_con += m;

	return lg_con;
}

string Sequence::longestRepeated() 
{
	string lg_rep;
	int len = sequence.size(), maxlen = -1, maxi = 0;

	memcpy(c, sequence.c_str(), sequence.size());
	for (int i = 0; i < len; i++)
		a[i] = &c[i];

	qsort(a, len, sizeof(char *), pstrcmp);

	for (int i = 0; i < len - 1; i++)
	{
		if (comlen(a[i], a[i + 1]) > maxlen)
		{
			maxlen = comlen(a[i], a[i + 1]);
			maxi = i;
		}
	}
        char tmp[500005];
	strncpy(tmp, a[maxi], maxlen);
	tmp[maxlen + 1] = '\0';
	lg_rep = tmp;
	return lg_rep;
}

int Sequence::comlen(const char *p, const char *q)
{
	int len = 0;
	while (*p && (*p++ == *q++))
	{
		len++;
	}
	return len;
}

