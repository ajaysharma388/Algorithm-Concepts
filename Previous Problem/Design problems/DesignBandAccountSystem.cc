class Bank 
{
    #define ll long long int
    vector<ll> accData;
    int count;
    bool isValidAccount(int accountNumber)
    {
        return (accountNumber >= 1 && accountNumber <= this->count);
    }
public:
    Bank(vector<ll>& balance) 
    {
        int n = balance.size();
        this->count = n;
        accData.resize(this->count+1);
        for(int i = 0; i < n; ++i)
            accData[i+1] = balance[i];
    }
    
    bool transfer(int account1, int account2, long long money) 
    {
        if( isValidAccount(account1) &&
            isValidAccount(account2) && 
            accData[account1]-money >= 0 )
        { 
            accData[account1] -= money;
            accData[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) 
    {
        if( isValidAccount(account) ) 
        {
            accData[account] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) 
    {
        if( isValidAccount(account) && accData[account] >= money) 
        {
            accData[account] -= money;
            return true;
        }
        return false;
    }
};