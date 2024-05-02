
int findMinimumCost(string str) {
  // Write your code here
  int closing_brace = 0;
   int count=0;
 stack<char> stack;
 for(int i=0;i<str.length();i++){
char ch = str[i];
if(ch == '{'){
  stack.push(ch);
} // if major
else if(ch == '}'  ){
  if(!stack.empty() && stack.top() == '{'){
    stack.pop();
  }
  else {
    stack.push('{');
    count++;
    
  }

} //else major 

 } //for here
 int final = 0;
 if(stack.empty()){
   return count;
 }
 else{
     while(!stack.empty()){
         stack.pop();
         final++;
     }
 }

 if(final%2 == 0){
   return final/2 + count;
 }
 return -1;

}