#include<iostream>
#include<string>
#include<vector>
#include<map>

int main() 
{
    int i, j, k, n;
    std::cout << "Enter the message - ";

    std::string s, origin;
    std::getline(std::cin, origin);

    std::cout << "Enter the key - ";

    std::string key_word, key;
    std::cin >> key_word;

    for (char ch : origin)
    {
        if (ch != ' ')
        {
            if (islower(ch))
            {
                s += ch;
            } 
            else
            {
                s += ch + 32;
            }
            
        }
    }

    for (char ch : key_word)
    {
        if (ch != ' ')
        {
            if (islower(ch))
            {
                key += ch;
            }
            else
            {
                key += ch + 32;
            }

        }
    }

    std::vector<std::vector<char> > a(5, std::vector<char>(5, ' '));
    n = 5;
    std::map<char, int> mp;
    k = 0;
    int pi, pj;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            while (mp[key[k]] > 0 && k < key.size())
            {
                k++;
            }
            if (k < key.size())
            {

                a[i][j] = key[k];
                mp[key[k]]++;
                pi = i;
                pj = j;
            }
            if (k == key.size())
            {
                break;
            }
        }
        if (k == key.size())
        {
            break;
        }
    }
    k = 0;
    for (; i < n; i++) 
    {
        for (; j < n; j++) 
        {
            while (mp[char(k + 'a')] > 0 && k < 26) 
            {
                k++;
            }
            if (char(k + 'a') == 'j') 
            {
                j--;
                k++;
                continue;
            }
            if (k < 26) 
            {
                a[i][j] = char(k + 'a');
                mp[char(k + 'a')]++;
            }
        }
        j = 0;
    }

    std::string ans;
    if (s.size() % 2 == 1)
    {
        s += "x";
    }

    for (i = 0; i < s.size() - 1; i++) 
    {
        if (s[i] == s[i + 1])
        {
            s[i + 1] = 'x';
        }
    }

    std::map<char, std::pair<int, int> > mp2;

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            mp2[a[i][j]] = std::make_pair(i, j);
        }
    }

    for (i = 0; i < s.size() - 1; i += 2) 
    {
        int y1 = mp2[s[i]].first;
        int x1 = mp2[s[i]].second;
        int y2 = mp2[s[i + 1]].first;
        int x2 = mp2[s[i + 1]].second;

        if (y1 == y2) 
        {
            ans += a[y1][(x1 + 1) % 5];
            ans += a[y1][(x2 + 1) % 5];
        }
        else if (x1 == x2) 
        {
            ans += a[(y1 + 1) % 5][x1];
            ans += a[(y2 + 1) % 5][x2];
        }
        else 
        {
            ans += a[y1][x2];
            ans += a[y2][x1];
        }
    }
    std::cout << ans << '\n';
    return 0;
}