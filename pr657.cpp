// The R1 company has recently bought a high rise building in the centre of Moscow for its main office. It's time to decorate the new
// office, and the first thing to do is to write the company's slogan above the main entrance to the building.

// The slogan of the company consists of n characters, so the decorators hung a large banner, n meters wide and 1 meter high, divided into
// n equal squares. The first character of the slogan must be in the first square (the leftmost) of the poster, the second character must be
// in the second square, and so on.

// Of course, the R1 programmers want to write the slogan on the poster themselves. To do this, they have a large (and a very heavy) ladder
// which was put exactly opposite the k-th square of the poster. To draw the i-th character of the slogan on the poster, you need to climb
// the ladder, standing in front of the i-th square of the poster. This action (along with climbing up and down the ladder) takes one hour
// for a painter. The painter is not allowed to draw characters in the adjacent squares when the ladder is in front of the i-th square
// because the uncomfortable position of the ladder may make the characters untidy. Besides, the programmers can move the ladder. In one
// hour, they can move the ladder either a meter to the right or a meter to the left.

// Drawing characters and moving the ladder is very tiring, so the programmers want to finish the job in as little time as possible.
// Develop for them an optimal poster painting plan!

// Input
// The first line contains two integers, n and k (1 ≤ k ≤ n ≤ 100) — the number of characters in the slogan and the initial position
// of the ladder, correspondingly. The next line contains the slogan as n characters written without spaces. Each character of the
// slogan is either a large English letter, or digit, or one of the characters: '.', '!', ',', '?'.

// Output
// In t lines, print the actions the programmers need to make. In the i-th line print:

// "LEFT" (without the quotes), if the i-th action was "move the ladder to the left";
// "RIGHT" (without the quotes), if the i-th action was "move the ladder to the right";
// "PRINT x" (without the quotes), if the i-th action was to "go up the ladder, paint character x, go down the ladder".
// The painting time (variable t) must be minimum possible. If there are multiple optimal painting plans, you can print any of them.

// Examples
// inputCopy
// 2 2
// R1
// outputCopy
// PRINT 1
// LEFT
// PRINT R
// inputCopy
// 2 1
// R1
// outputCopy
// PRINT R
// RIGHT
// PRINT 1
// inputCopy
// 6 4
// GO?GO!
// outputCopy
// RIGHT
// RIGHT
// PRINT !
// LEFT
// PRINT O
// LEFT
// PRINT G
// LEFT
// PRINT ?
// LEFT
// PRINT O
// LEFT
// PRINT G

/*████████████████████████████████████████████████████████████████████████████████████
██████████████████████████████████████████████████████████████████████████████████████
███████████████████████████▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓▓▓╬╬╬╬╬╬▓███████████████████████
███████████████████████████▓███████▓▓╬╬╬╬╬╬╬╬╬╬╬╬▓███▓▓▓▓█▓╬╬╬▓███████████████████████
███████████████████████████████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓███████████████████████
████████████████████████████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬███████████████████████
███████████████████████████▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
████████████████████████████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
███████████████████████████▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓███████████████████████
████████████████████████████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬███████████████████████
███████████████████████████▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
████████████████████████████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
███████████████████████████▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
█████████████████████████████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
█████████████████████████████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
█████████████████████████████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
████████████████████████████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
████████████████████████████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓████████████████████████
█████████████████████████████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓████████████████████████
█████████████████████████████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬█████████████████████████
██████████████████████████████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓█████████████████████████
███████████████████████████████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬██████████████████████████
███████████████████████████████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓██████████████████████████
████████████████████████████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████████
█████████████████████████████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓████████████████████████████
██████████████████████████████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓█████████████████████████████
███████████████████████████████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓██████████████████████████████
██████████████████████████████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬████████████████████████████████
███████████████████████████████████████▓▓▓██▓▓╬╬╬╬╬╬▓█████████████████████████████████
██████████████████████████████████████████████████████████████████████████████████████
 */
/*



 __    __                         __ __                          __                    ______   ______  _______   ______       __
|  \  |  \                       |  \  \                        |  \                  /      \ /      \|       \ /      \     |  \
| ▓▓  | ▓▓ ______   ______   ____| ▓▓\▓▓_______   ______       _| ▓▓_    ______      |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\ ▓▓▓▓▓▓▓\  ▓▓▓▓▓▓\     \▓▓ _______  ______
| ▓▓__| ▓▓/      \ |      \ /      ▓▓  \       \ /      \     |   ▓▓ \  /      \     | ▓▓__| ▓▓ ▓▓   \▓▓ ▓▓__/ ▓▓ ▓▓   \▓▓    |  \/       \|      \
| ▓▓    ▓▓  ▓▓▓▓▓▓\ \▓▓▓▓▓▓\  ▓▓▓▓▓▓▓ ▓▓ ▓▓▓▓▓▓▓\  ▓▓▓▓▓▓\     \▓▓▓▓▓▓ |  ▓▓▓▓▓▓\    | ▓▓    ▓▓ ▓▓     | ▓▓    ▓▓ ▓▓          | ▓▓  ▓▓▓▓▓▓▓ \▓▓▓▓▓▓\
| ▓▓▓▓▓▓▓▓ ▓▓    ▓▓/      ▓▓ ▓▓  | ▓▓ ▓▓ ▓▓  | ▓▓ ▓▓  | ▓▓      | ▓▓ __| ▓▓  | ▓▓    | ▓▓▓▓▓▓▓▓ ▓▓   __| ▓▓▓▓▓▓▓| ▓▓   __     | ▓▓\▓▓    \ /      ▓▓
| ▓▓  | ▓▓ ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓ ▓▓__| ▓▓ ▓▓ ▓▓  | ▓▓ ▓▓__| ▓▓      | ▓▓|  \ ▓▓__/ ▓▓    | ▓▓  | ▓▓ ▓▓__/  \ ▓▓     | ▓▓__/  \    | ▓▓_\▓▓▓▓▓▓\  ▓▓▓▓▓▓▓
| ▓▓  | ▓▓\▓▓     \\▓▓    ▓▓\▓▓    ▓▓ ▓▓ ▓▓  | ▓▓\▓▓    ▓▓       \▓▓  ▓▓\▓▓    ▓▓    | ▓▓  | ▓▓\▓▓    ▓▓ ▓▓      \▓▓    ▓▓    | ▓▓       ▓▓\▓▓    ▓▓
 \▓▓   \▓▓ \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓\▓▓\▓▓   \▓▓_\▓▓▓▓▓▓▓        \▓▓▓▓  \▓▓▓▓▓▓      \▓▓   \▓▓ \▓▓▓▓▓▓ \▓▓       \▓▓▓▓▓▓      \▓▓\▓▓▓▓▓▓▓  \▓▓▓▓▓▓▓
                                                |  \__| ▓▓
                                                 \▓▓    ▓▓
             */

#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstdint>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <random>
#include <deque>
#include <functional>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <numeric>
#include <immintrin.h>
#include <cassert>
#include <array>

using namespace std;

#ifdef LOCAL
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
#else
#define CURTIME() ;
#endif
double __begin;
#define DTIME(ccc)     \
    __begin = clock(); \
    ccc;               \
    cerr << "Time of work = " << (clock() - __begin) / CLOCKS_PER_SEC << endl;

#define mp make_pair
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef int itn;

template <class T1, class T2, class T3>
struct triple
{
    T1 a;
    T2 b;
    T3 c;
    triple() : a(T1()), b(T2()), c(T3()){};
    triple(T1 _a, T2 _b, T3 _c) : a(_a), b(_b), c(_c) {}
};
template <class T1, class T2, class T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2)
{
    if (t1.a != t2.a)
        return t1.a < t2.a;
    else if (t1.b != t2.b)
        return t1.b < t2.b;
    else
        return t1.c < t2.c;
}
template <class T1, class T2, class T3>
bool operator>(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2)
{
    if (t1.a != t2.a)
        return t1.a > t2.a;
    else if (t1.b != t2.b)
        return t1.b > t2.b;
    else
        return t1.c > t2.c;
}
#define tri triple<int, int, int>
#define trll triple<ll, ll, ll>

#define FI(n) for (int i = 0; i < (n); ++i)
#define FJ(n) for (int j = 0; j < (n); ++j)
#define FK(n) for (int k = 0; k < (n); ++k)
#define FL(n) for (int l = 0; l < (n); ++l)
#define FQ(n) for (int q = 0; q < (n); ++q)
#define FOR(i, a, b) for (int i = (a), __e = (int)(b); i < __e; ++i)
#define all(a) std::begin(a), std::end(a)
#define reunique(v) v.resize(unique(v.begin(), v.end()) - v.begin())

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    k -= 1;
    if (k == 0)
    {
        for (int i = 0; i < s.length(); i++)
        {
            cout << "PRINT" << ' ' << s[i] << "\n";
            if (i < s.length() - 1)
                cout << "RIGHT\n";
        }
    }
    else if (k == s.length() - 1)
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            cout << "PRINT" << ' ' << s[i] << "\n";
            if (i > 0)
                cout << "LEFT\n";
        }
    }
    else
    {
        if (k <= (s.length() - 1) / 2)
        {
            while ((k--) >= 1)
            {
                cout << "LEFT\n";
            }
            for (int i = 0; i < s.length(); i++)
            {
                cout << "PRINT" << ' ' << s[i] << "\n";
                if (i < s.length() - 1)
                    cout << "RIGHT\n";
            }
        }
        else
        {
            while ((k++) < s.length() - 1)
            {
                cout << "RIGHT\n";
            }
            for (int i = s.length() - 1; i >= 0; i--)
            {
                cout << "PRINT" << ' ' << s[i] << "\n";
                if (i > 0)
                    cout << "LEFT\n";
            }
        }
    }
    return 0;
}