public class DLink<E> {
    private E element;
    private DLink<E> next;
    private DLink<E> prev;

    public DLink(E item, DLink<E> next, DLink<E> prev)
    {
        element = item;
        this.next = next;
        this.prev = prev;
    }

    public DLink(DLink<E> next, DLink<E> prev)
    {
        this.next = next;
        this.prev = prev;
    }

    // Methods to get properties
    public void setElement(E item)
    {
        this.element = item;
    }

    public E getElement()
    {
        return this.element;
    }

    public DLink<E> next()
    {
        return this.next;
    }

    public DLink<E> prev()
    {
        return this.prev;
    }

    public void setNext(DLink<E> nextval)
    {
        this.next = nextval;
    }

    public void setPrev(DLink<E> prevval)
    {
        this.prev = prevval;
    }
}
