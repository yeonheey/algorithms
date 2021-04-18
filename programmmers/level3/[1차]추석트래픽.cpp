#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
	int max_count = 0;
	vector<pair<double, double>> traffic_time; //start, end time

	//change date to second
	for (string line : lines)
	{
		double complete = stod(line.substr(11, 2)) * 3600; //hour
		complete += stod(line.substr(14, 2)) * 60; //minute
		complete += stod(line.substr(17, 2)) + (stod(line.substr(20, 3)) / 1000.0); //second

		string t = line.substr(24);
		double start = complete - stod(t.substr(0, t.size() - 1)) + 0.001;

		traffic_time.push_back({ start, complete });
	}

	//check traffic times
	for (int i = 0; i < traffic_time.size(); i++)
	{
		double start = traffic_time[i].first;
		double complete = traffic_time[i].second;
		int count = 1;

		for (int j = i + 1; j < traffic_time.size(); j++)
			if (start + 1 >= traffic_time[j].first || complete + 1 > traffic_time[j].first)
				count++;

		max_count = max(max_count, count);
	}

	return max_count;
}
