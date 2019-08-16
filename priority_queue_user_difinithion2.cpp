#include <iostream>
#include <string>
#include <queue>

using namespace std;

// ユーザー定義した型で値を追加し、ユーザー定義関数で比較した
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
    priority_queue <SummerVacation> queue;

    // ■queueに要素を追加する
    queue.push(SummerVacation(4, 3));
    queue.push(SummerVacation(4, 1));
    queue.push(SummerVacation(2, 2));
    queue.push(SummerVacation(10, 8));
    queue.push(SummerVacation(5, 4));
    queue.push(SummerVacation(2, 5));

    // ■queueの要素を取得する
    while (!queue.empty()) {
        cout << queue.top().getDays() << " days after, paid: " << queue.top().getPay() << "\n";
        queue.pop();
    }

    std::cout << "\nSummerVacation function is finished.\n";
}
