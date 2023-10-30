#include <iostream>
using namespace std;

template <typename t>
class stack_array{
   t *arr;
   int capacity;
   int nextindex;

   public:
        stack_array(){
            arr=new t[4];
            capacity=4;
            nextindex=0;       
        }

   
       void push(t element){
           if (nextindex==capacity){
             t* newarr=new t[2*capacity];
             for (int i=0;i<capacity;i++){
                newarr[i]=arr[i];
             }
             capacity=(2*capacity);
             delete[] arr; 
            arr = newarr; // Update the pointer to the new array

           }
           arr[nextindex]=element;
           nextindex++;
       }

       t pop(){
         if (size()==0){
            cout<<"no elem. can be deleted from a empty stack"<<endl;
            return 0;
         }
         nextindex--;
         t ans=arr[nextindex];
         return ans;
       }
       
       t top(){
          if (size()==0){
            cout<<"empty stack"<<endl;
            return 0;
          }
          return arr[nextindex-1];
       }

       bool isempty(){
           return nextindex==0;
       }

       int size(){
          return nextindex;
       }
};

int main(){
    stack_array<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"deleted element from stack is : "<<s.pop()<<endl;
    cout<<"topmost element from stack is : "<<s.top()<<endl;
    cout<<"deleted element from stack is : "<<s.pop()<<endl;
    cout << "Stack size: " << s.size() << endl;
    cout << "Is stack empty? " ;
    if (s.isempty() ==0){
        cout<<"False"<<endl;
    }else{
        cout<<"True"<<endl;
    }
    cout<<"topmost element from stack is : "<<s.top()<<endl;
    return 0;
}
