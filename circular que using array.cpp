#include<iostream>
using namespace std;
const int size = 100;

class Que{
	private:
		int que[size];
		int front;
		int rear;
		
		public:
			Que(){
				front = -1;
				rear = -1;
			}
			
			void enque(int item){
				if (isfull()){
					cout<<"Que Overflow! Cannot endter item."<<endl;
					return;
				}
				
				if (isempty()){
					front = 0;
				}
					rear = (rear + 1) % size;
					que[rear] = item;
					cout<<"Enqued item: "<<item<<endl;
				
			}
				int deque(){
					if (isempty()){
						cout<<"Que underflow! Cannot deque item.\n";
						return -1;
					}
					
					int dequedItem = que[front];
					if (front == rear){
						front = -1;
						rear = -1;
					}
					else{
						front = (front + 1) % size;
						cout<<"Deque item: "<<dequedItem<<endl;
						return dequedItem;
					}
				}
				
				bool isfull(){
					return (front == (rear + 1) % size);
			}
				
				bool isempty(){
					return (rear == -1 && front == -1);
				}
				
							void display(){
				if (isempty()){
					cout<<"Underflow! Que is empty"<<endl;
					return;
				}
				
				cout<<"Que is:"<<endl;
				for (int i = front; i<= rear; i++){
					cout<<que[i]<<" ";
				}
				cout<<endl;
			}
		};
			int main(){
				Que myque;
				myque.enque(10);
				myque.enque(20);
				myque.enque(30);
				
				myque.display();
				
				myque.deque();
				myque.deque();
				myque.display();
	
				myque.deque();
				myque.display();

			return 0;
			}
