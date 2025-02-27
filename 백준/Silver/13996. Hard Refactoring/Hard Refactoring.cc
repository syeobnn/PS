#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#define MAX (50000 + 32767)
#define MIN (50000 - 32768)
#define log2 18
#define divisor 1000000000
#define multiplier 31

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ddx[] = {1, -1, 0, 0};
const int ddy[] = {0, 0, -1, 1};
const int INF = 0x3f3f3f3f;
const ll LINF = 3123372036854775807;

inline void fastIo()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> check_validate;

int main()
{
    fastIo();

    vector<string> tokens[1010];
    string line;
    int mid = 50000;
    int cnt = 0, ccnt = 0;

    check_validate.resize(100000);

    while (true)
    {

        vector<string> tokenarr;

        if (!getline(cin, line))
            break;

        if (line.empty())
            break;
        ;

        istringstream iss(line);
        string token;

        while (iss >> token)
            tokenarr.push_back(token);

        tokens[cnt] = tokenarr;
        cnt++;
    }

    // validate_check에 만드는 거 ㅇㅇ
    while (ccnt < cnt)
    {
        if (tokens[ccnt].size() == 4 || tokens[ccnt].size() == 3)
        {
            int n1 = stoi(tokens[ccnt][2]);
            string uneq = tokens[ccnt][1];

            if (uneq == ">=")
            {
                for (int i = mid + n1; i <= MAX; i++)
                    check_validate[i] = 1;
            }
            else if (uneq == "<=")
            {
                for (int i = mid + n1; i >= MIN; i--)
                    check_validate[i] = 1;
            }
        }
        else if (tokens[ccnt].size() == 8 || tokens[ccnt].size() == 7)
        {
            int n1 = stoi(tokens[ccnt][2]), n2 = stoi(tokens[ccnt][6]);

            for (int i = mid + n1; i <= mid + n2; i++)
                check_validate[i] = 1;
        }
        ccnt++;
    }

    int start = INF, end = INF;
    vector<pair<int, int>> arr;

    // 부등호 처리
    for (int i = MIN; i <= MAX + 1; i++)
    {
        if (check_validate[i])
        {
            start = i;
            for (int j = i; j <= MAX + 1; j++)
            {
                if (!check_validate[j])
                {
                    end = j - 1;
                    arr.emplace_back(start - mid, end - mid);

                    i = j;
                    break;
                }
            }
        }
    }

    if (start == MIN && end == MAX)
    {
        cout << "true\n";
        return 0;
    }
    if (start == INF && end == INF)
    {
        cout << "false\n";
        return 0;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        auto [L, R] = arr[i];

        if (L == -32768)
        {
            cout << "x <= " << R;
        }
        else if (R == 32767)
        {
            cout << "x >= " << L;
        }
        else
        {
            cout << "x >= " << L << " && x <= " << R;
        }

        if (i + 1 < arr.size())
            cout << " ||\n";
        else
            cout << "\n";
    }

    return 0;
}
