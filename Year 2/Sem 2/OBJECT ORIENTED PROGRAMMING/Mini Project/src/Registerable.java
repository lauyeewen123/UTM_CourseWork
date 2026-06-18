// Registerable Interface

public interface Registerable {
    boolean registerEvent(Event event) throws EventFullException;
    void viewRegisteredEvents();
} 