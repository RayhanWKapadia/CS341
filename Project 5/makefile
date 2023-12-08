# Honor Pledge:
#
# I pledge that I have neither given nor
# received any help on this assignment.
#
# rkapadia
Tree.exe: driver.o BST.o TreeNode.o Node.o RedBlackTree.o
	g++ driver.o BST.o TreeNode.o Node.o RedBlackTree.o -o Tree.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

BST.o: BinaryTree.cpp
	g++ -c BinaryTree.cpp -o BST.o

TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o

clean:
	rm *.o Tree.exe
	
run: Tree.exe
	./Tree.exe