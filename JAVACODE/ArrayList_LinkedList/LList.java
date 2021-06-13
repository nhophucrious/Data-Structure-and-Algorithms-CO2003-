public class LList<E> implements List<E> {
    private Link<E> head;
    private Link<E> curr;
    private Link<E> tail;
    private int size;

    // Constructor
    public LList(int size) {
        this();
    }

    public LList() {
        head = curr = tail = new Link<E>(null);
        size = 0;
    }

    // Remove
    @Override
    public void clear() {
        head.setNext(null);
        head = tail = curr = new Link<E>(null);
        size = 0;
    }

    // Insert an element in current location
    @Override
    public void insert(E item) {
        curr.setNext(new Link<E>(item, curr.next())); // Insert at a current location
        if (curr == tail)
            tail = curr.next(); // Insert at end
        size++;
    }

    // Append an element to the list
    @Override
    public void append(E item) {
        tail = tail.setNext(new Link<E>(item, null));
    }

    // Remove an element at curr location
    @Override
    public E remove() {
        if (curr.next() == null) // Nothing to remove
            return null;
        E item = curr.element(); // Store the return value
        if (tail == curr.next()) // return at last;
            tail = curr;
        curr.setNext(curr.next().next()); // delete at specific
        size--;
        return item;
    }

    @Override
    public void moveToStart() {
        curr = head;
    }

    @Override
    public void moveToEnd()
    {
        curr = tail;
    }

    @Override
    public void moveToPos(int pos)
    {
        assert (pos >= 0) && (pos <= size) : "Position out of range";
        curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next();
        }
    }
    @Override
    public int currPos()
    {
        Link<E> temp = head;
        int pos = 0;
        while (temp != curr) {
            temp = temp.next();
            pos++;
        }
        return pos;
    }
    @Override
    public E getValue()
    {
        if(curr.next() == null)
        {
            return null;
        }
        return curr.element();
    }
    @Override
    public void next()
    {
        if(curr!=tail)
            curr.next();
    }
    @Override
    public int length()
    {
        return size;
    }
    @Override
    public void prev()
    {   
        if(curr == head)
        {
            return;
        }
        Link<E> temp = head;
        while (temp.next() != curr)
        {
            temp = temp.next();
        }
        curr = temp;
    }
}