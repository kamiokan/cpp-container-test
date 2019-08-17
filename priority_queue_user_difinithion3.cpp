#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 不完全、ギブアップ 2019/08/17 16:00

// ユーザー定義した型で値を追加し、ユーザー定義関数で比較した
// 入力(N:件数, M:期限日数, A:入金までの日数, B:バイト代)
// N M
// A1 B1
// A2 B2
// ...
// Ai Bi
// days: 支払いまでの日数, pay: バイト代
class SummerVacation {
public:
    SummerVacation() {
        // デフォルト値を設定する
        setDays(0);
        setPay(0);
    }

    SummerVacation(int days, int pay) {
        setDays(days);
        setPay(pay);
    }

    bool operator<(const SummerVacation &SummerVacation) const {

        if (getDays() == SummerVacation.getDays()) {
            return getPay() < SummerVacation.getPay();
        } else {
            return getDays() > SummerVacation.getDays();
        }
    }

    void setDays(int days) { this->days = days; }

    int getDays() const { return days; }

    void setPay(int pay) { this->pay = pay; }

    int getPay() const { return pay; }

private:
    int pay;
    int days;
};

int main() {
    int N, M;
    cin >> N >> M;

    priority_queue <SummerVacation> queue;
    int result = 0;

    int A, B;
    int i = 0;
    while (i < N) {
        cin >> A >> B;
        queue.push(SummerVacation(A, B));

        i++;
    }

    i = 0;
    while(i < M) {
        i++;
        // ■queueの要素を取得する
        while (!queue.empty()) {
            // cout << queue.top().getDays() << " days after, paid: " << queue.top().getPay() << "\n"; // debug

            // A<=1, A<=2 ... Ai<=j のとき報酬が最大になるBjをピックアップする
            if (queue.top().getDays() <= i) {
                result += queue.top().getPay();
                queue.pop();
                break;
            } else {
                break;
            }
        }
    }

    cout << result << endl;
}
