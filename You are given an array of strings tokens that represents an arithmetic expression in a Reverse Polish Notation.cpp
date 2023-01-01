class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int>st;
         for(int i=0;i<tokens.size();i++){
             if(tokens[i]!="+"&& tokens[i]!="-"&& tokens[i]!="/" && tokens[i]!="*"){
                 st.push(stoi(tokens[i]));
             }
             else{
                 int num1=st.top();
                 st.pop();
                 int num2=st.top();
                 st.pop();
                 if(tokens[i]=="+"){
                     st.push(num1+num2);
                 }
                 else if(tokens[i]=="-"){
                     st.push(num2-num1);
                 }
                 else if(tokens[i]=="/"){
                     st.push(num2/num1);
                     cout<<num1;
                 }
                 else if(tokens[i]=="*"){
                     st.push(num1*num2);
                 }
             }

         }
         return st.top();

    }
};
