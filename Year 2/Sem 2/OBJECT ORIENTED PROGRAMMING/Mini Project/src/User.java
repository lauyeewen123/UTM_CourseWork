// Abstract User Class
// Mini Project: Event Registration System

import javax.swing.*;

public abstract class User {
    String userID, name, email, password;

    public User(String userID, String name, String email, String password) {
        this.userID = userID;
        this.name = name;
        this.email = email;
        this.password = password;
    }

    abstract boolean login(String userID, String password);
    
    void logout() {
        JOptionPane.showMessageDialog(null, name + " has logged out.", "Logout", JOptionPane.INFORMATION_MESSAGE);
    }
    
    void viewProfile() {
        JOptionPane.showMessageDialog(null, "Name: " + name + "\nEmail: " + email, "Profile", JOptionPane.INFORMATION_MESSAGE);
    }
} 