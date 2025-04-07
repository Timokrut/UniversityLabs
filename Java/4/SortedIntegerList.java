import java.util.LinkedList;
import java.util.ListIterator;

public class SortedIntegerList {
    private final LinkedList<Integer> list;
    private final boolean allowDuplicates;

    public SortedIntegerList(boolean allowDuplicates) {
        this.list = new LinkedList<>();
        this.allowDuplicates = allowDuplicates;
    }

    public void add(int value) {
        ListIterator<Integer> it = list.listIterator();
        
        while (it.hasNext()) {
            int current = it.next();
            if (current > value) {
                it.previous(); 
                it.add(value);
                return;
            }
            if (!allowDuplicates && current == value) {
                return;
            }
        }
        it.add(value);
    }

    public void remove(int value) {
        ListIterator<Integer> it = list.listIterator();
        while (it.hasNext()) {
            if (it.next() == value) {
                it.remove(); 
                return;
            }
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        SortedIntegerList other = (SortedIntegerList) obj;

        return list.equals(other.list) && allowDuplicates == other.allowDuplicates;
    }

    @Override
    public String toString() {
        return list.toString();
    }
}
