#ifndef NODE_H
#define NODE_H

class Node{
    int data;
    Node* next;

    public:
        // Constructors
        Node() : next(NULL) {}
        Node(int d) : data(d), next(NULL) {}
        Node(int d, Node* n) : data(d), next(n) {}

        // Setters
        void setData(int d) { data = d; }
        void setNext(Node* n) { next = n; }

        // Getters
        int getData() { return data; }
        Node* getNext() { return next; }

        // Append to tail
        void append(int d) {
            Node * n = new Node(d);

            if(next == NULL)
                next = n;
            else {

                Node * itr = next; 
                
                while(itr->getNext()){
                    itr = itr->getNext();
                }

                itr->setNext(n);

            }
        }
};

#endif
