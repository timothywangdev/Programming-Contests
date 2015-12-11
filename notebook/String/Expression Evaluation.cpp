// operators?
bool op(string token){
  return (token=="("||token==")"||token=="+"||token=="-"||token=="*"||token=="/"||token=="%");
}
// numbers?
bool operand(string token){
  return !op(token);
}
int priority(string token){
  if(token=="*"||token=="/"||token=="%")return 2;
  if(token=="+"||token=="-")return 1;
  return 0;
}
vector<string> infix2postfix(vector<string> tokens){
  stack<string> s;
  vector<string> postfix;
  for(int i=0;i<tokens.size();i++){
    if(operand(tokens[i])){
      postfix.push_back(tokens[i]);
    }
    else if(tokens[i]=="("){
      postfix.push_back(tokens[i]);
    }
    else if(tokens[i]==")"){
      while(!s.empty()&&s.top()!="("){
	postfix.push_back(s.top());
	s.pop();
      }
      // remove "("
      s.pop();
    }
    else{
      // operator
      if(s.empty()||s.top()=="("){
	s.push(tokens[i]);
      }
      else{
	while(!s.empty()&&s.top()!="("&&
	      priority(s.top())>=priority(tokens[i])){
	  postfix.push_back(s.top());
	  s.pop();
	}
	s.push(tokens[i]);
      }
    }
  }
  while(!s.empty()){
    postfix.push_back(s.top());
    s.pop();
  }
  return postfix;
}

int evaOperation(int l, int r, string op){
  if(op=="+"){
    return l+r;
  }
  if(op=="-"){
    return l-r;
  }
  if(op=="*"){
    return l*r;
  }
  if(op=="/"){
    return l/r;
  }
  if(op=="%"){
    return l%r;
  }
}
int evaluate(vector<string> postfix){
  stack<int> s;
  int rv=0;
  for(int i=0;i<postfix.size();i++){
    if(operand(postfix[i])){
      s.push(atoi(postfix[i].c_str()));
    }
    else{
      int right=s.top();
      s.pop();
      int left=s.top();
      s.pop();
      s.push(evaOperation(left,right,postfix[i]));
    }
  }
  return s.top();;
}

vector<string> tokenizer(string s){
  vector<string> tokens;
  for(int i=0;i<s.length();i++){
    if('0'<=s[i]&&s[i]<='9'){
      string num;
      while('0'<=s[i]&&s[i]<='9'){
	num+=s[i];
	i++;
      }
      i--;
      tokens.push_back(num);
    }
    else if(op(string(1,s[i]))){
      tokens.push_back(string(1,s[i]));
    }
  }
  return tokens;
}
int main(){
  cout<<endl<<evaluate(infix2postfix(tokenizer("4*3/5")))<<endl;
   return 0;
}


