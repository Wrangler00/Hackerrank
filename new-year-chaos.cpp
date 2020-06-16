//https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&isFullScreen=false&playlist_slugs%5B%5D%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D%5B%5D=arrays

//cpp my solution
void minimumBribes(vector<int> q) {
    int sz = q.size(),i,j,ans=0;
    vector<int> cp(sz,2);
    
    for(i=0;i<sz-1;i++){
        for(j=i;j<sz-1;j++){
            if(q[j] == i+1){
                break;
            }
            --cp[q[j]-1];
            if(cp[q[j]-1]<0){
                cout<<"Too chaotic\n";
                return;
            }
        }

        while(j>q[j]-1){
            swap(q[j-1],q[j]);
            ++ans;
            --j;
        }
    }
    cout<<ans<<endl;
}


//cpp others solution O(n)

void calc(vector<int> q)
{
    int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i]) ans++;
    }
    cout << ans << endl;
}
