#include "clock.h"
#include <iostream>
using namespace std;
int main() {
	clock clock0(23, 59, 59);
	cout << "After postincrement operatorClock0 " << clock0++;
	cout << "Now Clock0 " << clock0;
	cout << "After preincrement operator Clock0 " << ++clock0;

	clock clock1(5, 2, 4);
	cout << "After preincrement operator Clock1 " << ++clock1;
	cout << "Inputting clock 1\n";
	cin >> clock1;
	cout << clock1;

	cout << "clock0 == clock1 = " << (clock0 == clock1) << endl;
	cout << "clock0 != clock1 = " << (clock0 != clock1) << endl;
	cout << "clock0 > clock1 = " << (clock0 > clock1) << endl;
	cout << "clock0 < clock1 = " << (clock0 < clock1) << endl;
	cout << "clock0 >= clock1 = " << (clock0 >= clock1) << endl;
	cout << "clock0 <= clock1 = " << (clock0 <= clock1) << endl;
	return 0;
}
/*Output
After postincrement operatorClock0 Time = 23:59:59
Now Clock0 Time = 00:00:00
After preincrement operator Clock0 Time = 00:00:01
After preincrement operator Clock1 Time = 05:02:05
Inputting clock 1
Please enter hour, minutes seconds separated by space 0 0 1
Time = 00:00:01
clock0 == clock1 = 1
clock0 != clock1 = 0
clock0 > clock1 = 0
clock0 < clock1 = 0
clock0 >= clock1 = 1
clock0 <= clock1 = 1
Press any key to continue . . .
*/