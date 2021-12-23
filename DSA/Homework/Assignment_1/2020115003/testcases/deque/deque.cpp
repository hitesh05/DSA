#include <iostream>
#include <stack>
using namespace std;

int main() {
	deque<pair<int, int>> st;
	while (true) {
		string type; cin >> type;
		if (type == "push") {
			pair<int, int> p;
			cin >> p.first >> p.second;
			st.push_front(p);
		} else if (type == "pop") {
			pair<int, int> x = st.front();
			if (st.empty()) {
				cout << "The deque is empty" << endl;
			} else {
				pair<int, int> x = st.front();
				st.pop_front();
				cout << "{" << x.first << ", " << x.second << "}" << endl;
			}
		} else if (type == "inject") {
            pair<int, int> p;
			cin >> p.first >> p.second;
            st.push_back(p);
        } else if (type == "eject") {
            if (st.empty()) {
				cout << "The deque is empty" << endl;
			} else {
				pair<int, int> x = st.back();
				st.pop_back();
				cout << "{" << x.first << ", " << x.second << "}" << endl;
			}
		} else if (type == "exit") {
			break;
		}
	}
}
