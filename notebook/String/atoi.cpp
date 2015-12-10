int atoi(string str) {
  unsigned int rv = 0;
  int i = 0;
  int sign = 1;
  if (str=="")return 0;
  // Step 1
  // Discarding whitespace characters
  while (i<str.length()&&isspace(str[i])){
    i++;
  }
  // Step 2
  // only has white spaces
  if(i==str.length())return 0;
  // Check if the first character is a valid character
  if (!(('0' <= str[i] && str[i] <= '9') || (str[i] == '+') || (str[i] == '-'))){
    return 0;
  }
  // Step 3
  // Check if there is a plus or a minus sign
  if (str[i] == '+' || str[i] == '-'){
    if (str[i] == '-'){
      sign = -1;
    }
    i++;
  }
  // Step 4
  // Convert as many base-10 digits as possible, and stop when it's not a digit
  int len=0;
  for (; i<str.length(); i++){
    if ('0' <= str[i] && str[i] <= '9'){
      rv = rv * 10 + (unsigned int) (str[i] - '0');
      len++;
      // length>10 we are sure we get overflow or underflow
      if(len>10)return sign>0?INT_MAX:INT_MIN;
      if(rv>2147483647&&sign==1)return INT_MAX;
      if(rv>2147483648&&sign==-1)return INT_MIN;
    }
    else
      break;
  }
  return rv*(int)sign;
}
