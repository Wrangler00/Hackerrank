//https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&isFullScreen=false&playlist_slugs%5B%5D%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D%5B%5D=arrays

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void swap(int &a,int &b){
    int tmp = a;
    a=b;
    b=tmp;
    return;
}

void print(vector<int> &v){
    int sz=v.size();
    cout<<"Print: ";
    for(int i=0;i<sz;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return;
}
// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    int sz = q.size(),i,j,ans=0;
    vector<int> cp(sz,2);
    
    for(i=0;i<sz-1;i++){
        for(j=i;j<sz-1;j++){
            if(q[j] == i+1){
                // cout<<"match :: "<<j<<endl;
                break;
            }
            // cout<<"not catch : "<<j<<" "<<i<<" "<<q[j]<<" "<<cp[q[j]-1]<<endl;
            --cp[q[j]-1];
            if(cp[q[j]-1]<0){
                cout<<"Too chaotic\n";
                return;
            }
        }

        // cout<<"before while :: "<<j<<" "<<q[j]<<endl;
        while(j>q[j]-1){
            swap(q[j-1],q[j]);
            ++ans;
            --j;
        }

        // print(q);
    }

    int sum = 0;
    for(int i=0;i<sz-1;i++){
        sum+=cp[i];
    }
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
