#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int x=1e3+10;
const int y=12e3+10;

int t,d,g[x],n,f[x][y];
vector<int>vt,vtp;

int main()
{
    //quan tâm đến hiệu trên dưới của con domino
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> d;
        g[i] = (t - d);
    }
    //mảng f dùng để tái tạo lại trục số (j) tương ứng với mỗi con cờ(i) mới thêm vào f[i][j] là số con cờ phải lật ít nhất để xuất hiện ra giá trị j khi con cờ i được thêm vào
    //vì có thể âm nên thay vì xuất phát từ 0 xuất phát từ 6000
    //ban đầu khi chưa có con domino nào thì dãy sẽ có giá trị là 6000
    f[0][6000] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 12e3; j++)
            if (f[i - 1][j] > 0)//?? rê nó ??n f[1][6000] và những nhánh phát triển từ f[0][6000]
            {//trường hợp ko lật
                if (f[i][j + g[i]])//nếu nó !=0
                    f[i][j + g[i]] = min(f[i - 1][j], f[i][j + g[i]]);
                else
                    f[i][j + g[i]] = f[i - 1][j];

                if (f[i][j - g[i]])//trường hợp lật
                    f[i][j - g[i]] = min(f[i - 1][j] + 1, f[i][j - g[i]]);
                else
                    f[i][j - g[i]] = f[i - 1][j] + 1;
            }


    int mark = 0;
    //mark là khoảng cách nhỏ nhất có thể có giữa hàng trên và dưới
    while (f[n][mark] == 0)mark++;

    for (int j = 0; j <= 12e3; j++)
        if (f[n][j] != 0)
            if (abs(mark - 6e3) > abs(j - 6e3))mark = j;


    vt.pb(mark);

    cout << f[n][mark] - 1 << "\n";
    
    for (int i = n - 1; i > 0; i--)
        if (f[i][vt.back() - g[i + 1]] == f[i + 1][vt.back()])
            vt.pb(vt.back() - g[i + 1]);
        else if (f[i][vt.back() + g[i + 1]] == f[i + 1][vt.back()] - 1)
        {
            vt.pb(vt.back() + g[i + 1]);//giá trị trên trục số (j) hiện tại
            vtp.pb(i + 1);// mảng những con domino lật
        }
    //in ngược từ dưới lên
    for (auto it = vtp.rbegin(); it != vtp.rend(); it++)cout << *it << " ";

}
