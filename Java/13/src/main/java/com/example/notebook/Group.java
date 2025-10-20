package com.example.notebook;

public enum Group {
    ALL("все"),
    COLLEAGUES("коллеги"),
    FAMILY("семья"),
    FRIENDS("друзья");

    private final String displayName;

    Group(String displayName) {
        this.displayName = displayName;
    }

    public String getDisplayName() {
        return displayName;
    }

    public static Group fromParam(String param) {
        if (param == null) return ALL;
        switch (param.toLowerCase()) {
            case "colleagues": return COLLEAGUES;
            case "family": return FAMILY;
            case "friends": return FRIENDS;
            default: return ALL;
        }
    }
}
