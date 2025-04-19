class BSTiterator{
 
    stack<TreeNode*> st ;
   
    bool rev = true ;
    
    
    public:
   
    BSTiterator(TreeNode* root , bool isrev){
        rev = isrev ;
        f(root) ; 
    }
    bool hasNext(){
        return !st.empty() ; 
    }
    int next(){
        TreeNode* tmp = st.top();
        st.pop();
        if(rev==false) f(tmp->right) ;
        else f(tmp->left);
        return tmp->val ; 
    }
    private:
    void f(TreeNode* root){
        for(;root!=NULL;){
            st.push(root);
            if(rev==true){
                root = root->right ; 
            }
            else {
                root = root->left ; 
            }
        }
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false ;
      
        
        BSTiterator l(root, false) ;
       
        BSTiterator r(root , true) ;
        
        int lp = l.next() ;
        int rp = r.next() ; 
        
       
        while(lp<rp){
            if(lp+rp==k) return true ;
            else if(lp+rp<k) lp=l.next() ;
            else rp = r.next() ;
        }
        return false ; 
        
    }
};