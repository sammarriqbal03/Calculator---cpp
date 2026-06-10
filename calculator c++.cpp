#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

// function to calculate factorial of a number
unsigned int fact(int n) {
    int res = 1;
    for (int j = n; j > 0; j--)
        res *= j;
    return res;
}

int main() {
    double x, y, ans, mem = 0;
    char sign, cmd[10];

    cout << "Operators available:\n";
    cout << " +  addition\n -  subtraction\n *  multiplication\n";
    cout << " /  division\n ^  power\n !  factorial\n\n";

    begin:                       /* program entry point */
    cin >> x;                    /* take the first value */

    again:                       /* jump back here when reusing */
    cin >> sign;                 /* read the operator symbol */

    /* perform the chosen operation */
    if (sign == '!') {
        ans = fact(x);
    } else {
        cin >> y;
        switch (sign) {
            case '+': ans = x + y; break;
            case '-': ans = x - y; break;
            case '*': ans = x * y; break;
            case '/': ans = x / y; break;
            case '^': ans = pow(x, y); break;
        }
    }

    cout << " = " << ans << endl;

    /* memory section */
    cout << "\nWrite 'mi' to save result in memory, 'mc' to erase memory: ";
    cin >> cmd;
    if (strcmp(cmd, "mi") == 0)
        mem = ans;
    else if (strcmp(cmd, "mc") == 0)
        mem = 0;
    else
        cout << "unknown input, continuing...\n";

    /* loop control */
    cout << "\nOptions:\n 'restart' -> new calculation\n";
    cout << " 'reuse'   -> continue with result\n";
    cout << " 'mr'      -> use memory value\n 'quit'    -> exit\n> ";
    cin >> cmd;

    if (strcmp(cmd, "restart") == 0) goto begin;
    if (strcmp(cmd, "reuse")   == 0) { x = ans; cout << x; goto again; }
    if (strcmp(cmd, "mr")      == 0) { x = mem; cout << x; goto again; }
    if (strcmp(cmd, "quit")    == 0) goto finish;

    getchar();
    finish:
    return 0;
}

