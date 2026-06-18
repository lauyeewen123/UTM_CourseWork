// Student Class
import java.util.*;
import javax.swing.*;

public class Student extends User implements Registerable {
    String matricNo, faculty;
    ArrayList<Registration> registrations = new ArrayList<>();

    public Student(String userID, String name, String email, String password, String matricNo, String faculty) {
        super(userID, name, email, password);
        this.matricNo = matricNo;
        this.faculty = faculty;
    }

    @Override
    boolean login(String userID, String password) {
        return this.userID.equals(userID) && this.password.equals(password);
    }

    @Override
    public boolean registerEvent(Event event) throws EventFullException {
        // Check if student is already registered for this event
        for (Registration reg : registrations) {
            if (reg.event.eventID.equals(event.eventID)) {
                JOptionPane.showMessageDialog(null, "You are already registered for this event: " + event.name, "Registration Failed", JOptionPane.WARNING_MESSAGE);
                return false;
            }
        }
        
        event.addParticipant(this);
        Registration registration = new Registration(UUID.randomUUID().toString(), this, event, new Date().toString());
        registrations.add(registration);
        registration.confirmRegistration();
        return true;
    }

    @Override
    public void viewRegisteredEvents() {
        if (registrations.isEmpty()) {
            JOptionPane.showMessageDialog(null, "No events registered.", "Registered Events", JOptionPane.INFORMATION_MESSAGE);
            return;
        }
        
        StringBuilder eventsList = new StringBuilder("Events registered by " + name + ":\n");
        for (Registration reg : registrations) {
            eventsList.append("- ").append(reg.event.name).append(" on ").append(reg.timestamp).append("\n");
        }
        JOptionPane.showMessageDialog(null, eventsList.toString(), "Registered Events", JOptionPane.INFORMATION_MESSAGE);
    }

    @Override
    void viewProfile() {
        JOptionPane.showMessageDialog(null, "Name: " + name + "\nEmail: " + email + "\nMatric No: " + matricNo + "\nFaculty: " + faculty, 
                "Student Profile", JOptionPane.INFORMATION_MESSAGE);
    }

    public void cancelRegistration(String eventID) {
        boolean cancelled = registrations.removeIf(reg -> {
            if (reg.event.eventID.equals(eventID)) {
                reg.event.removeParticipant(this);
                return true;
            }
            return false;
        });
        
        if (cancelled) {
            JOptionPane.showMessageDialog(null, "Cancelled registration for event ID: " + eventID, "Cancellation Success", JOptionPane.INFORMATION_MESSAGE);
        } else {
            JOptionPane.showMessageDialog(null, "Event not found or not registered.", "Cancellation Failed", JOptionPane.WARNING_MESSAGE);
        }
    }
} 