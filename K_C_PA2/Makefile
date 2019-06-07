buildBinaryTree: main.o BinaryTree.o BinaryTreeNode.o Hash.o hashNode.o
	g++ main.o BinaryTree.o BinaryTreeNode.o Hash.o hashNode.o -o buildBinaryTree
main.o: main.cpp BinaryTree.h
	g++ -c main.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp
BinaryTreeNode.o: BinaryTreeNode.cpp BinaryTreeNode.h
	g++ -c BinaryTreeNode.cpp
Hash.o: Hash.cpp Hash.h
	g++ -c Hash.cpp
hashNode.o: hashNode.cpp hashNode.h
	g++ -c hashNode.cpp
clean:
	rm *.o
	rm buildBinaryTree
 
