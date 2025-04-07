public class Main {
    public static void main(String[] args) {
        SortedIntegerList list1 = new SortedIntegerList(true);
        list1.add(5);
        list1.add(3);
        list1.add(8);
        list1.add(3);
        System.out.println("List1 (Dublicates allowed): " + list1); // [3, 3, 5, 8]

        SortedIntegerList list2 = new SortedIntegerList(false);
        list2.add(5);
        list2.add(3);
        list2.add(8);
        list2.add(3);
        System.out.println("List2 (Dublicates ar not allowed): " + list2); // [3, 5, 8]

        list1.remove(3);
        System.out.println("List1 after remove 3: " + list1); // [3, 5, 8]

        list2.remove(8);
        System.out.println("List2 after remove 8: " + list2); // [3, 5]

        list2.remove(8);
        System.out.println("List2 after second attempt to remove 8: " + list2); // [3, 5]
        
        System.out.println();
        System.out.println();
            
        SortedIntegerList list3 = new SortedIntegerList(true);
        SortedIntegerList list4 = new SortedIntegerList(false);

        list3.add(3);
        list3.add(5);
        list3.add(8);
        System.out.println("List3 (Dublicates allowed): " + list3);

        list4.add(5);
        list4.add(3);
        System.out.println("List4 (Dublicates are not allowed): " + list4);

        System.out.println("List1 equals List3: " + list1.equals(list3));
        System.out.println("List2 equals List4: " + list2.equals(list4));
        System.out.println("List3 equals List4: " + list3.equals(list4));
    }
}
