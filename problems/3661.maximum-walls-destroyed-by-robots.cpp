// @leetcode id=3661 questionId=3982 slug=maximum-walls-destroyed-by-robots lang=cpp site=leetcode.com title="Maximum Walls Destroyed by Robots"
class Solution {
    public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    int n = robots.size();
    vector<pair<long long,long long>> rb(n);
    for(int i=0;i<n;i++) rb[i]={robots[i],distance[i]};
    sort(rb.begin(),rb.end());
    sort(walls.begin(),walls.end());
    auto cnt=[&](long long lo, long long hi)->int{
    if(lo>hi) return 0;
    int L=(int)(lower_bound(walls.begin(),walls.end(),lo)-walls.begin());
    int R=(int)(upper_bound(walls.begin(),walls.end(),hi)-walls.begin());
    return R-L;
    };
    vector<array<int,2>> dp(n,{0,0});
    long long r0=rb[0].first,d0=rb[0].second;
    dp[0][0]=cnt(r0-d0,r0);
    long long right0=(n>1)?min(r0+d0,rb[1].first-1):r0+d0;
    dp[0][1]=cnt(r0,right0);
    for(int i=1;i<n;i++){
    long long ri=rb[i].first,di=rb[i].second;
    long long ri1=rb[i-1].first,di1=rb[i-1].second;
    long long rR=(i+1<n)?min(ri+di,rb[i+1].first-1):ri+di;
    int wr=cnt(ri,rR);
    long long bL=max(ri-di,ri1+1);
    int B=cnt(bL,ri);
    long long aR=min(ri1+di1,ri-1);
    int AB=cnt(bL,aR);
    dp[i][1]=max(dp[i-1][0],dp[i-1][1])+wr;
    dp[i][0]=max(dp[i-1][0]+B,dp[i-1][1]+B-AB);
    }
    return max(dp[n-1][0],dp[n-1][1]);
    }
    };
