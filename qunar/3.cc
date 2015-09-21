#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;


struct Process {
	int id;
	vector<int> hasLocks;
	int waitLock;
};

vector<int> getHasLocks(const string &line) {
	vector<int> ret;
	if (line == " ")
		return ret;
	int last = 0;
	int pos = line.find(',', last);
	while (pos > 0) {
		ret.push_back(atoi(line.substr(last, pos - last).c_str()));
		last = pos + 1;
		pos = line.find(',', last);
	}
	ret.push_back(atoi(line.substr(last, -1).c_str()));
	return ret;
}

int getWaitLock(const string &line) {
	if (line == " ")
		return -1;
	return atoi(line.c_str());
}

Process readLine(const string &line) {
	Process ret;
	int last = 0;
	int pos = line.find('\t', last);
	ret.id = atoi(line.substr(last, pos - last).c_str());
	last = pos + 1;
	pos = line.find('\t', last);
	ret.hasLocks = getHasLocks(line.substr(last, pos - last));
	last = pos + 1;
	ret.waitLock = getWaitLock(line.substr(last, -1));
	return ret;
}

vector<int> graph;
vector<int> released;
map<int, int> resources;

void read() {
	string line;
	getline(cin, line);
	istringstream ss(line);
	int n;
	ss >> n;
	graph.resize(n, -1);
	released.resize(n, 0);
	vector<Process> processes;
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		Process tmp = readLine(line);
		processes.push_back(tmp);
		for (int j = 0; j < tmp.hasLocks.size(); j++)
			resources[tmp.hasLocks[j]] = i;
	}
	for (int i = 0; i < n; i++) {
		int waitLock = processes[i].waitLock;
		if (waitLock >= 0 && resources.find(waitLock) != resources.end())
			graph[i] = resources[waitLock];
	}
}

void loose() {
	while (1) {
		bool flag = false;
		for (int i = 0; i < graph.size(); i++) {
			if (graph[i] < 0 && !released[i]) {
				released[i] = 1;
				flag = true;
				for (int j = 0; j < graph.size(); j++) {
					if (graph[j] == i)
						graph[j] = -1;
				}
				break;
			}
		}
		if (!flag)
			break;
	}
}

int check() {
	int ret = -1;
	for (int i = 0; i < graph.size(); i++) {
		if (graph[i] >= 0) {
			ret = i;
			break;
		}
	}
	return ret;
}

set<int> visited;

int dfs(int i) {
	if (graph[i] < 0)
		return -1;
	visited.insert(i);
	if (visited.find(graph[i]) != visited.end())
		return graph[i];
	return dfs(graph[i]);
}

int main() {
	int num = 0;	
	read();
	while (1) {
		loose();
		int i = check();
		if (i >= 0) {
			num++;
			visited.clear();
			int j = dfs(i);	
			graph[j] = -1;
		} else {
			break;
		}
	}
	cout << num;
	return 0;
}
