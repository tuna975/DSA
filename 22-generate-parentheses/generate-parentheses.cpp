class Solution {
private:
    void generate(int n, string& s, vector<string>& res, int o, int c) {
    if (o+c==2*n) {
        res.push_back(s);
        return;
    }
    if (o<n) {
        s.push_back('(');
        generate(n, s, res, o+1, c);
        s.pop_back(); 
    }
    if (c<o) {
        s.push_back(')');
        generate(n, s, res, o, c+1);
        s.pop_back(); 
    }
 }
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>res;
        generate(n,s,res,0,0);
        return res;
    }
};     