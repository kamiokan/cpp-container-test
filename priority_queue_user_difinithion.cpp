#include <iostream>
#include <string>
#include <queue>

using namespace std;

// ユーザー定義した型で値を追加し、ユーザー定義関数で比較した
// @see http://alctail.sakura.ne.jp/tip/cplus_kannrenn/cplusplus/stl.shtml#stl2-9
class Stl9 {
public:
    Stl9() {
        // デフォルト値を設定する
        setMyName("default");
        setPriority(9999999);
    }

    Stl9(std::string myName, int priority) {
        setMyName(myName);
        setPriority(priority);
    }

    bool operator<(const Stl9 &stl9) const {
        return getPriority() > stl9.getPriority();
    }

    void setMyName(std::string myName) { this->myName = myName; }

    std::string getMyName() const { return myName; }

    void setPriority(int priority) { this->priority = priority; }

    int getPriority() const { return priority; }

private:
    int priority;
    std::string myName;
};

int main() {
    std::priority_queue <Stl9> queue;

    // ■queueに要素を追加する
    queue.push(Stl9("その5", 5));
    queue.push(Stl9("その4", 4));
    queue.push(Stl9("その3", 3));
    queue.push(Stl9("その2", 2));
    queue.push(Stl9("その1", 1));

    // ■queueの要素を取得する
    while (!queue.empty()) {
        std::cout << queue.top().getMyName() << "\n";
        queue.pop();
    }

    std::cout << "\nstl9関数が終了しました\n";
}
