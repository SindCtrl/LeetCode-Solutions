/* Problem: Process String with Special Operations

Approach:
1. Maintain the length of the resulting string after each operation.
2. Traverse the input string and store cumulative lengths.
3. If k is outside the final length, return '.'.
4. Traverse backwards:
   - Letters contribute one character.
   - '#' doubles the string.
   - '%' reverses the string.
   - Map k back through each operation until the original character is found.
5. Return the character at position k.

Time Complexity: O(n)
Space Complexity: O(n) */

char processStr(char* s, long long k) {
    int n = strlen(s);

    long long len[n + 1];
    len[0] = 0;

    for (int i = 0; i < n; i++) {
        long long L = len[i];

        if (s[i] >= 'a' && s[i] <= 'z') {
            len[i + 1] = L + 1;
        }
        else if (s[i] == '*') {
            len[i + 1] = (L > 0) ? L - 1 : 0;
        }
        else if (s[i] == '#') {
            len[i + 1] = L * 2;
            if (len[i + 1] > 1000000000000000LL)
                len[i + 1] = 1000000000000000LL;
        }
        else { // '%'
            len[i + 1] = L;
        }
    }

    if (k >= len[n])
        return '.';

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (k == len[i])
                return s[i];
        }
        else if (s[i] == '#') {
            if (len[i] > 0)
                k %= len[i];
        }
        else if (s[i] == '%') {
            if (len[i] > 0)
                k = len[i] - 1 - k;
        }
    }

    return '.';
}

}
