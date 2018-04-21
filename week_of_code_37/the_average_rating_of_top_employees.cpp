#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Complete the averageOfTopEmployees function below.
void averageOfTopEmployees(vector<int> rating) {
    float sum = 0;
    float total = 0;
    
    for(int i = 0; i < rating.size(); i++){
        if(rating[i] >= 90){
            sum += rating[i];
            total++;
        }
    }
    
    cout << fixed << setprecision(2) << sum/total + 0.001;

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> rating(n);

    for (int rating_itr = 0; rating_itr < n; rating_itr++) {
        int rating_item;
        cin >> rating_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        rating[rating_itr] = rating_item;
    }

    averageOfTopEmployees(rating);

    return 0;
}