// Admin Class
// Mini Project: Event Registration System

import javax.swing.*;

public class Admin extends User {

    public Admin(String userID, String name, String email, String password) {
        super(userID, name, email, password);
    }

    @Override
    boolean login(String userID, String password) {
        return this.userID.equals(userID) && this.password.equals(password);
    }

    void createEvent(Event event) {
        MainApp.events.add(event);
        JOptionPane.showMessageDialog(null, "Event created: " + event.name, "Event Creation", JOptionPane.INFORMATION_MESSAGE);
    }

    void viewParticipants(String eventID) {
        for (Event e : MainApp.events) {
            if (e.eventID.equals(eventID)) {
                if (e.participants.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "No participants for " + e.name, "Participants", JOptionPane.INFORMATION_MESSAGE);
                } else {
                    StringBuilder participantsList = new StringBuilder("Participants of " + e.name + ":\n");
                    for (Student s : e.participants) {
                        participantsList.append("- ").append(s.name).append(" (").append(s.matricNo).append(")\n");
                    }
                    JOptionPane.showMessageDialog(null, participantsList.toString(), "Participants", JOptionPane.INFORMATION_MESSAGE);
                }
                return;
            }
        }
        JOptionPane.showMessageDialog(null, "Event not found.", "Error", JOptionPane.ERROR_MESSAGE);
    }

    void viewAllEvents() {
        if (MainApp.events.isEmpty()) {
            JOptionPane.showMessageDialog(null, "No events have been created.", "All Events", JOptionPane.INFORMATION_MESSAGE);
            return;
        }

        StringBuilder eventList = new StringBuilder("List of All Events:\n\n");
        for (Event e : MainApp.events) {
            eventList.append("ID: ").append(e.eventID).append("\n");
            eventList.append("Name: ").append(e.name).append("\n");
            eventList.append("Date: ").append(e.date).append("\n");
            eventList.append("Quota: ").append(e.participants.size()).append(" / ").append(e.quota).append("\n");
            eventList.append("--------------------\n");
        }
        
        JOptionPane.showMessageDialog(null, eventList.toString(), "All Events", JOptionPane.INFORMATION_MESSAGE);
    }
} 