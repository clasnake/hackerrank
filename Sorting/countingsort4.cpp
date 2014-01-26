#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

typedef struct node
{
	int num;
	string str;
}c_node;

int main()
{
	int n;
	cin >> n;
	c_node *a = new c_node[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].num >> a[i].str;
	}
	map< int, list<string> > int_list_map;
	for (int i = 0; i < n; i++) {
		if (i < n / 2) {
			a[i].str = "-";
		}
		map< int, list<string> >::iterator iter = int_list_map.find(a[i].num);
		if (iter == int_list_map.end()) {
			list<string> str_list;
			str_list.push_back(a[i].str);
			int_list_map.insert(pair< int, list<string> > (a[i].num, str_list));
		}
		else {
			iter->second.push_back(a[i].str);
		}
	}
	for (map< int, list<string> >::iterator i = int_list_map.begin(); i != int_list_map.end(); i++) {
		while (!i->second.empty()) {
			cout << i->second.front() << " ";
			i->second.pop_front();
		}
	}
	delete [] a;
	return 0;
}