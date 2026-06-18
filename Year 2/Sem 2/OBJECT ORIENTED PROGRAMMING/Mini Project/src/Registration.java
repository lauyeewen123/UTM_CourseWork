// Registration Class
// Mini Project: Event Registration System

import javax.swing.*;

public class Registration {
    String registrationID;
    Student student;
    Event event;
    String timestamp;

    public Registration(String registrationID, Student student, Event event, String timestamp) {
        this.registrationID = registrationID;
        this.student = student;
        this.event = event;
        this.timestamp = timestamp;
    }

    void confirmRegistration() {
        JOptionPane.showMessageDialog(null, "Registration success for: " + event.name, "Registration Success", JOptionPane.INFORMATION_MESSAGE);
    }

    void cancelRegistration() {
        JOptionPane.showMessageDialog(null, "Registration cancelled for: " + event.name, "Cancellation", JOptionPane.INFORMATION_MESSAGE);
    }
} 