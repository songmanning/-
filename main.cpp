#include <iostream>
using namespace std;
void dfs(int &count, int last, int curp, int curq, int curr, int np, int nq, int nr){
    if (curp > np || curq > nq || curr > nr)
        return;
    if (curp == np && curq == nq && curr == nr){
        ++count;
        return;
    }
    if (last == 0){
        last = 1;
        dfs(count, last, curp, curq + 1, curr, np, nq, nr);
        last = 2;
        dfs(count, last, curp, curq, curr + 1, np, nq, nr);
    }
    else if (last == 1){
        last = 0;
        dfs(count, last, curp + 1, curq, curr, np, nq, nr);
        last = 2;
        dfs(count, last, curp, curq, curr + 1, np, nq, nr);
    }
    else if (last == 2){
        last = 0;
        dfs(count, last, curp + 1, curq, curr, np, nq, nr);
        last = 1;
        dfs(count, last, curp, curq + 1, curr, np, nq, nr);
    }
    else{
        last = 0;
        dfs(count, last, curp + 1, curq, curr, np, nq, nr);
        last = 1;
        dfs(count, last, curp, curq + 1, curr, np, nq, nr);
        last = 2;
        dfs(count, last, curp, curq, curr + 1, np, nq, nr);
    }
}
int main(int argc, const char * argv[]) {
    int np,nq,nr;
    cin >> np >> nq >> nr;
    int count = 0;
    dfs(count, -1, 0, 0, 0, np, nq, nr);
    cout << count << endl;
    return 0;
}
