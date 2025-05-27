import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MyTask {
    private final int start;
    private final int end;
    private final List<Integer> answers = new ArrayList<>();

    public MyTask(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public int getStart() {
        return start;
    }

    public int getEnd() {
        return end;
    }

    public List<Integer> getAnswers() {
        return Collections.unmodifiableList(answers);
    }

    public void addAnswers(List<Integer> primes) {
        answers.addAll(primes);
    }
}
