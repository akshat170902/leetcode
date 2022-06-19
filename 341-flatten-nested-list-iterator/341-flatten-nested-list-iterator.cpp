/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int>dp;
    int p=0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int i=0;
        while(i<nestedList.size()){
           if(nestedList[i].isInteger()){
               dp.push_back(nestedList[i].getInteger());
               
           }
            else{
                NestedIterator im(nestedList[i].getList());
 while (im.hasNext()){
     dp.push_back(im.next());
 }
            }
            i++;
        }
    }
    
    int next() {
        return dp[p++];
    }
    
    bool hasNext() {
        return p!=dp.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */