#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    priority_queue <string> q;

    q.push("百田夏菜子");
    q.push("玉井詩織");
    q.push("佐々木彩夏");
    q.push("高城れに");

    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}
