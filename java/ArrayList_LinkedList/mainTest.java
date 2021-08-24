
public class mainTest {
    public static void main(String[] arg) {
        LList<Integer> someList = new LList<Integer>();
        someList.append(10);
        someList.append(20);
        someList.moveToStart();
        someList.insert(30);
        someList.moveToPos(2);
        someList.insert(40);
        someList.remove();
        someList.print();
    }
}
