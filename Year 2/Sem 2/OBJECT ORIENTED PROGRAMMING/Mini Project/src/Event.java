// Event Class

import java.util.*;

public class Event {
    String eventID, name, date, description;
    int quota;
    ArrayList<Student> participants = new ArrayList<>();

    public Event(String eventID, String name, String date, int quota, String description) {
        this.eventID = eventID;
        this.name = name;
        this.date = date;
        this.quota = quota;
        this.description = description;
    }

    boolean isFull() {
        return participants.size() >= quota;
    }

    void addParticipant(Student student) throws EventFullException {
        if (isFull()) {
            throw new EventFullException("The event '" + this.name + "' is already full.");
        }
        participants.add(student);
    }

    void removeParticipant(Student student) {
        participants.remove(student);
    }
} 