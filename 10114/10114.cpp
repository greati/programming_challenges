#include <bits/stdc++.h>

using namespace std;

int main(void) {

    long double loanDuration, downPayment, loanAmount, n;

    while (true) {
        cin >> loanDuration;

        if (loanDuration < 0) break;

        cin >> downPayment >> loanAmount >> n;

        long double m[101];

        for (int i = 0; i <= loanDuration; ++i) {
            m[i] = -1; 
        }

        for (int i = 0; i < n; ++i) {
            int month;
            long double percentage;
            cin >> month >> percentage;
            m[month] = percentage;
        }

        int curMonth = 0;
        long double owes = loanAmount;
        long double car = (loanAmount + downPayment) * (1.00 - m[0]); 
        long double curPercentage = m[0];
        while (curMonth < loanDuration && owes >= car) {
            if (owes < car) break;
            curMonth++;
            if (m[curMonth] != -1) 
               curPercentage = m[curMonth]; 
            owes -= (loanAmount/loanDuration);
            car *= (1.00 - curPercentage); 
            if (owes < car) break;
        }
        
        if (curMonth == 1)
            cout << curMonth << " month" << endl;
        else 
            cout  << curMonth << " months" << endl;
    }

    return 0;
}
