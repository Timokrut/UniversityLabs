public class Main {
    public static void main(String[] args) {
        SortedIntegerList list1 = new SortedIntegerList(true);
        list1.add(5);
        list1.add(3);
        list1.add(8);
        list1.add(3);
        System.out.println("List1: " + list1); // [3, 3, 5, 8]

        SortedIntegerList list2 = new SortedIntegerList(false);
        list2.add(5);
        list2.add(3);
        list2.add(8);
        list2.add(3);
        System.out.println("List2: " + list2); // [3, 5, 8]

        list1.remove(3);
        System.out.println("List1 after remove 3: " + list1); // [3, 5, 8]

        System.out.println("List1 equals List2: " + list1.equals(list2)); // true

        list2.remove(8);
        System.out.println("List2 after remove 8: " + list2); // [3, 5]

        System.out.println("List1 equals List2: " + list1.equals(list2)); // false
    }
}
