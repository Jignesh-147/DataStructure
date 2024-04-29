

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

class stack{
 
   int* arr;
   int top;
   int size;
   public:

   stack(int size){
    this -> size = size;
    arr = new int[size];
    top = -1;
   }
   void push(int element){
    if(top<size-1){ 
     top++;
     arr[top] = element;
    }
    else{
        cout<<"stack overflow"<<endl;
    }
     
   }
   
   void pop(){
    if(top > -1){
        top--;
    }
    else{
        cout<<"stack underflow"<<endl;
    }

   }

   int peak(){
    if(top>-1){
        return arr[top];
    }
    
    return -1;

   }

   bool is_empty(){
       if(top == -1){
        return true;
       }

       return false;
   }
   


};

int main(){

    stack st(3);
    cout<<st.is_empty()<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.peak()<<endl;
    st.pop();
    cout<<st.peak()<<endl;

return 0;
}
