// Proof: http://blog.m-s-t.org/2015/12/07/floyds-cycle-finding-algorithm-correctness-proof/
// Linked List Example

template<typename T>
T f(T v){
   return v?v->next:v;
}
    
template<typename T>
bool ending(T v){
   return v==NULL;
}

/*
  Returns the staring point value and cycle length
*/    
template<typename T>
pair<T,int> floydCycleFinding(T x0){
   T slow=x0,fast=x0;
   do{
      slow=f(slow);
      fast=f(fast);
      // No cycle
      if(ending(fast))return make_pair(x0,0);
      fast=f(fast);
      // No cycle
      if(ending(fast))return make_pair(x0,0);
   }while(slow!=fast);
   slow=x0;
   while(slow!=fast){
      slow=f(slow);
      fast=f(fast);
   }
   int lambda=1;
   do{
      lambda++;
      fast=f(fast);
   }while(fast!=slow);
   return make_pair(slow,lambda);
}

/*
  Returns the staring point and cycle length (mu (zero-based) and lambda)
*/   
pair<int,int> floydCycleFinding(T x0){
   T slow=x0,fast=x0;
   do{
      slow=f(slow);
      fast=f(fast);
      // No cycle
      if(ending(fast))return make_pair(0,0);
      fast=f(fast);
      // No cycle
      if(ending(fast))return make_pair(0,0);
   }while(slow!=fast);
   slow=x0;
   int mu=0;
   while(slow!=fast){
      slow=f(slow);
      fast=f(fast);
      mu++;
   }
   int lambda=1;
   do{
      lambda++;
      fast=f(fast);
   }while(fast!=slow);
   return make_pair(mu,lambda);
}
