#ifndef NODE_H
#define NODE_H

template<typename E>
class Node
{
    public:
        E element;
        Node<E> *next;
        //Constructor de la clase
        Node(E element, Node<E> *next=NULL){
            this->element=element;
            this->next=next;
        }
        //Segundo constructor; constructor especial
        Node(Node<E>*next=NULL) {
            this->next=next;
        }
};

#endif // NODE_H
