#include <bits/stdc++.h>

#define st string
#define pb push_back
#define vec vector
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define int long long

using namespace std;
using vl = vec<int>;
using vi = vec<int>;
using vvi = vec<vi>;
using pi = pair<int, int>;
using vpi = vec<pi>;
using vvvi = vec<vvi>;
using vvpi = vec<vec<pi>>;
using vvvpi = vec<vvpi>;
using vvvvi = vec<vvvi>;
using vppi = vec<pair<pair<int, int>, pair<int, int>>>;

bool comp(int a, int b) {
    return a > b;
}

struct Compare {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

pair<st, st> convert(st s, int x) {
    vec<st> words;
    st now;
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 3 && s[i] == ' ' && s[i + 1] == ' ' && s[i + 2] == ' ' && s[i + 3] == ' ') {
            words.pb(now);
            now = "";
            i += 3;
        }
        else {
            now += s[i];
        }
    }
    //cout << now << endl;
    words.pb(now);
    st ans;
    for (auto u : words) {
        //cout << u.size() << endl;
        if (u.size() > x) {
            for (int i = 0; i < x - 3; i++) {
                ans += u[i];
            }
            ans += "...";
        }
        else {
            ans += u;
            for (int i = 0; i < x - u.size(); i++) {
                ans += ' ';
            }
        }
        ans += "|";
        //cout << ans << endl;
    }
    return {ans, words[words.size() - 1]};
}

void change(){
std::ofstream toclear;
std::ofstream ofs;
toclear.open("out.txt",std::ofstream::out);
ofs.open("input.txt",std::ofstream::out);
cout<<"how much questions do you need?"<<endl;
int x; cin>>x;
st s;
getline(cin,s);
for (int i=0; i<x;i++){
	cout<<"Enter ur"<<(i+1)<<" question: "<<endl;
	getline(cin,s);
	ofs<<s<<endl;
}
ofs.close()
}


void print(int x) { // x - Ã¸Ã¨Ã°Ã¨Ã­Ã  Ã¿Ã·Ã¥Ã©ÃªÃ¨
    st s;
    ifstream in("output.txt");
    ifstream inn("input.txt");
    st toconv;
    while (getline(inn, s)) {
        toconv += s + "    ";
    }
    toconv.pop_back();
    cout << convert(toconv, x).ff << endl;
    int cnt = 0;
    map<st, int> mp;
    while(getline(in, s)) {
        auto now = convert(s, x);
        if (cnt) {
            mp[now.ss]++;
        }
        cnt++;
        cout << now.ff << endl;
    }

    st ans;
    int cntt = 0;
    for (auto u : mp) {
        if (cntt <= u.ss) {
            ans = u.ff;
            cntt = u.ss;
        }
    }

    cout << cnt << endl;
    cout << ans << endl;
}

void solve() {
  cout<<"If you need change questions write 1, otherwise write 2"<< endl;
  int ok; cin>>ok;
  if(!(ok-1)){
  change();
  return;
}



  cout << "Fill out a survey or display a story? If you complete the survey, then enter 1, otherwise enter 2" << endl;
  int xx; cin >> xx;
  if (xx - 1) {
    cout << "Enter width " << endl;
    int wid; cin >> wid;
    print(wid);
    return;
  }
  ifstream inn("input.txt");
  st s;
  st x;
  vec<st> a;
  vec<st> ss;
  while (getline(inn, s)) {
    cout << s << endl;
    ss.pb(s);
    cin >> x;
    a.pb(x);
  }
  std::ofstream fout;
  fout.open("output.txt", std::ios::app);
  for (int i = 0; i < a.size(); i++) {
    if (i == a.size() - 1) {
        fout << a[i];
        continue;
    }
    fout << a[i] << "    ";
  }
  fout << endl;
  fout.close();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
