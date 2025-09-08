#include <bits/stdc++.h>
using namespace std;

void fastio(bool read = false) 
{
    if(read) 
    {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif  
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

#define TweetData pair<int, pair<int, int>>

class Twitter {
    unordered_map<int, vector<pair<int, int>>> TweetInfo;
    unordered_map<int, set<int>> followersInfo;
    int timeStamp;
public:
    Twitter() 
    {
        this->timeStamp = 0;
        this->TweetInfo.clear();
        this->followersInfo.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        this->TweetInfo[userId].push_back({++timeStamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        priority_queue<TweetData> TweetsData;
        this->followersInfo[userId].insert(userId);
        for(auto followee: this->followersInfo[userId])
        {
            if(TweetInfo[followee].size() != 0)
            {
                int LastTweet = TweetInfo[followee].size()-1;
                TweetsData.push(
                    {
                        TweetInfo[followee][LastTweet].first, // timeStamp.
                        {
                            followee,
                            LastTweet
                        }
                    }
                );
            }
        }
        vector<int> tweetIds;
        while(!TweetsData.empty() && tweetIds.size() < 10)
        {
            TweetData cur = TweetsData.top();
            TweetsData.pop();
            tweetIds.push_back(TweetInfo[cur.second.first][cur.second.second].second);
            if(cur.second.second-1 >= 0)
            {
                TweetsData.push(
                    {
                        TweetInfo[cur.second.first][cur.second.second-1].first, 
                        {
                            cur.second.first,
                            cur.second.second-1
                        }
                    }
                );
            }
        }   
        this->followersInfo[userId].erase(userId);
        return tweetIds;
    }
    
    void follow(int followerId, int followeeId) 
    {
        this->followersInfo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        this->followersInfo[followerId].erase(followeeId);
    }

    void print(vector<int> feed)
    {
        cout << "[ ";
        for(int feedItem: feed)
        {
            cout << feedItem << " ";
        }
        cout << "]\n";
    }

    void solve()
    {
        int actionCnt;
        cin >> actionCnt;
        int followerId, followeeId, userId, tweetId;
        while(actionCnt--)
        {
            int ac;
            cin >> ac;
            switch(ac)
            {
                case 1:
                    cin >> followerId >> followeeId;
                    follow(followerId, followeeId);
                    break;
                case 2:
                    cin >> followerId >> followeeId;
                    unfollow(followerId, followeeId);
                    break;
                case 3:
                    cin >> userId >> tweetId;
                    postTweet(userId, tweetId);
                    break;
                case 4:
                    cin >> userId;
                    print(getNewsFeed(userId));
                    break;
            }
        }
        return;
    }
};

int main() 
{
    fastio();
    int tc;
    cin >> tc;
    while (tc--) 
    {    
        Twitter *s = new Twitter();
        s->solve();        
    }
    return 0;
}

/*

Sample Input:

1
7
3 1 5
4 1
1 1 2
3 2 6
4 1
2 1 2
4 1

Sample Output:

[ 5 ]
[ 6 5 ]
[ 5 ]

*/
