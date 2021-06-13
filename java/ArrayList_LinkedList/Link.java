//Singly linked list node
public class Link<E> {
    // Basic Field of a Node
    private E element;
    private Link<E> next;

    // Implementation of Default Constructor
    public Link() {
        next = null;
    }

    // Implementation of parameters constructor
    public Link(E data, Link<E> nextval) {
        element = data;
        next = nextval;
    }

    public Link(Link<E> nextval) {
        next = nextval;
    }

    public Link<E> next() {
        return this.next;
    }

    public Link<E> setNext(Link<E> nextval) {
        return next = nextval;
    }

    E element() {
        return element;
    } // Set element field

    E setElement(E it) {
        return element = it;
    }
}