import java.util.List;
import java.util.ArrayList;

public class MyTask {
    private final int start;
    private final int end;
    private List<Integer> answers;
    
    public MyTask(int start, int end) {
        this.start = start;
        this.end = end;
        this.answers = new ArrayList<>();
    }
    
    public int getStart() {
        return start;
    }
    
    public int getEnd() {
        return end;
    }
    
    public List<Integer> getAnswers() {
        return answers;
    }
    
    public void setAnswers(List<Integer> answers) {
        this.answers = answers;
    }
}

