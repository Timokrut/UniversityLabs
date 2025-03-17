import java.util.LinkedList;
import java.util.Iterator;

public class SortedIntegerList { 
    private LinkedList<Integer> list;
    private boolean allowDuplicates;

    public SortedIntegerList(boolean allowDuplicates) {
        this.list = new LinkedList<>();
        this.allowDuplicates = allowDuplicates;
    }

    public void add(int value) {
        Iterator<Integer> it = list.iterator();
        int index = 0;
        
        while (it.hasNext()) {
            int current = it.next();
            if (current > value) {
                break; 
            } 
            if (!allowDuplicates && current == value) {
                return;
            }
            index++;
        }

        list.add(index, value);
    }

    public void remove(int value) {
        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            int current = it.next();
            if (current == value) {
                it.remove();
                return;
            }
        }
    }

    @Override
    public final boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        SortedIntegerList other = (SortedIntegerList) obj;
        return this.list.equals(other.list) && this.allowDuplicates == other.allowDuplicates;
    }

    @Override
    public String toString() {
        return list.toString();
    }
}
