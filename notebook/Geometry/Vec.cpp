template <typename T>
struct Vec{
 T x,y;
 Vec(T x,T y):x(x),y(y){}
 Vec(P<T> A,P<T> B){
    x=B.x-A.x;
    y=B.y-A.y;
 }
 // cross product
 T operator*(Vec<T> &other){
    return x*other.y-y*other.x;
 }
 // dot product
 T operator+(Vec<T> &other){
    return x*other.x+y*other.y;
 }
 Vec<T> scale(T s){
   return Vec<T>(x*s,y*s);
 }
 P<T> translate(P<T> p){
   return P<T>(p.x+x,p.y+y);
 }
 double mag(){
   return sqrt(v.x*v.x+v.y*v.y);
 }
 T mag_sq(){
   return v.x*v.x+v.y*v.y;
 }
};
