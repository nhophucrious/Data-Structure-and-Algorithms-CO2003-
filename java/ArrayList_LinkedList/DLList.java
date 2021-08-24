public class DLList<E> implements List<E> {
    private DLink<E> head;
    private DLink<E> tail;
    protected DLink<E> curr;
    int size;

    public DLList() {
        head = curr = tail = new DLink<E>(null, null);
        size = 0;
    }

    public DLList(int size) {
        this();
    }

    @Override
    public void moveToStart() {
        curr = head;
    }

    @Override
    public void moveToEnd() {
        curr = tail;
    }

    @Override
    public void next() {
        if (curr != tail)
            curr = curr.next();
    }

    @Override
    public void prev() {
        if (curr != head)
            curr = curr.prev();
    }

    @Override
    public int length() {
        return size;
    }

    @Override
    public int currPos() {
        int pos = 0;
        DLink<E> temp = head;
        while (temp.next() != curr) {
            temp = temp.next();
            pos++;
        }
        return pos;
    }

    @Override
    public E getValue() {
        if (curr.next() == null) {
            return null;
        }
        return curr.getElement();
    }

    @Override
    public void append(E item) {

        tail.setPrev(new DLink<E>(item, tail.prev(), tail));
        tail.prev().prev().setNext(tail.prev());
        if (head == tail)
            head = head.prev();
        size++;
    }

    @Override
    public void insert(E item) {
        curr.setNext(new DLink<E>(item, curr, curr.next()));
        curr.next().next().setPrev(curr.next());
        if (tail == head)
            tail = tail.next();     
        size++;
    }

    @Override
    public void clear() {
        head = curr = tail = new DLink<>(null, null);
        size = 0;
    }

    @Override
    public void moveToPos(int pos) {
        assert (pos >= 0) && (pos <= size) : "Position out of range";
        curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next();
        }
    }

    @Override
    public E remove() {
        if (curr.next() == null) {
            return null;
        }
        E result = curr.next().getElement();
        curr.next().next().setPrev(curr);
        curr.setNext(curr.next().next());
        size--;
        return result;
    }

    public void print() {
        DLink<E> ptr = head.next();
        while (ptr.next() != null) {
            System.out.print(ptr.getElement() + ", ");
            ptr = ptr.next();
        }
    }
}
