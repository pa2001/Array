class Solution {
public:
    bool caneat(vector<int>&piles,int n,int h)
    {
        int hours=0;
        for(int i=0;i<piles.size();i++)
        {
            hours+=piles[i]/n;
            if(piles[i]%n)
                hours++;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=1000000000;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(caneat(piles,mid,h))
                right=mid-1;
            else
                left=mid+1;
        }return left;
    }
};
tc:nlogn
sc:1
