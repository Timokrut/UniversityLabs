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

public SortedIntegerList intersect(SortedIntegerList list2) {
    if (allowDuplicates != list2.allowDuplicates) {
        throw new RuntimeException("Can't intersect between lists of different allowDuplicates parameter");
    }

    SortedIntegerList result = new SortedIntegerList(allowDuplicates);
    ListIterator<Integer> it1 = list.listIterator();
    ListIterator<Integer> it2 = list2.list.listIterator();

    Integer val1 = it1.hasNext() ? it1.next() : null;
    Integer val2 = it2.hasNext() ? it2.next() : null;

    while (val1 != null && val2 != null) {
        if (val1.equals(val2)) {
            result.add(val1);
            val1 = it1.hasNext() ? it1.next() : null;
            val2 = it2.hasNext() ? it2.next() : null;
        } else if (val1 < val2) {
            val1 = it1.hasNext() ? it1.next() : null;
        } else {
            val2 = it2.hasNext() ? it2.next() : null;
        }
    }

    return result;
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
