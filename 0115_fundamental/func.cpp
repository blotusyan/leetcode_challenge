#include <iostream>
using namespace std;

class Solution {
public:
	void getNum(){
		cout << "enter";
		cin >> num1;
		cout << "enter2";
		cin >> num2;
	}
	//Solution(int a, int b): num1(a), num2(b){}
	int compare(){
		return num1<=num2 ? num2 : num1;
	}
private:
	int num1 =0;
	int num2=0;
};

int main(){
	Solution sln;
	sln.getNum();
	int bigger = sln.compare();
	cout << "bigger: " << bigger << endl;
}