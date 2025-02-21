#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <json/json.h>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to convert a number string from a given base to decimal
long long convertToDecimal(const string &value, int base) {
    long long result = 0;
    for (char digit : value) {
        result = result * base + (isdigit(digit) ? (digit - '0') : (digit - 'a' + 10));
    }
    return result;
}

// Function to perform Lagrange interpolation to find f(0)
long long lagrangeInterpolation(const vector<pair<int, long long>> &points) {
    int k = points.size();
    double secret = 0;

    for (int i = 0; i < k; ++i) {
        double term = points[i].second;
        for (int j = 0; j < k; ++j) {
            if (i != j) {
                term *= (0 - points[j].first) / double(points[i].first - points[j].first);
            }
        }
        secret += term;
    }
    return round(secret);
}

int main() {
    vector<string> filenames = {"testcase1.json", "testcase2.json"};
    for (const auto &filename : filenames) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return 1;
        }

        Json::Value root;
        file >> root;
        file.close();

        int n = root["keys"]["n"].asInt();
        int k = root["keys"]["k"].asInt();

        vector<pair<int, long long>> points;
        for (auto it = root.begin(); it != root.end(); ++it) {
            if (it.key().asString() == "keys") continue;
            int x = stoi(it.key().asString());
            int base = stoi((*it)["base"].asString());
            string value = (*it)["value"].asString();
            long long y = convertToDecimal(value, base);
            points.push_back({x, y});
        }

        // Sort by x-values
        sort(points.begin(), points.end());

        // Only use the first k points for interpolation
        points.resize(k);

        // Compute the secret
        long long secret = lagrangeInterpolation(points);
        cout << "Secret for " << filename << ": " << secret << endl;
    }
    return 0;
}
