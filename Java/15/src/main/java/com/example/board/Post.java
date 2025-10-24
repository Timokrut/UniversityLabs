package com.example.board;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Post {
    private final String title;
    private final String text;
    private final String author;
    private final String timestamp;

    public Post(String title, String text, String author) {
        this.title = title;
        this.text = text;
        this.author = author;
        this.timestamp = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm"));
    }

    public String getTitle() { 
        return title;
    }
    
    public String getText() { 
        return text; 
    }
    
    public String getAuthor() { 
        return author; 
    }
    
    public String getTimestamp() { 
        return timestamp; 
    }
}
