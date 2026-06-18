// Custom exception for when an event's quota is full
public class EventFullException extends Exception {
    public EventFullException(String message) {
        super(message);
    }
} 