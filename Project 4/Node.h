// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rkapadia
#ifndef NODE_H
#define NODE_H
class Node{
	public:
		Node(int data);
		~Node() {}
		int getValue();
		void setValue(int data);
	private:
		int data_;
	
	
	protected:
		Node(){}
		
	
};
#endif