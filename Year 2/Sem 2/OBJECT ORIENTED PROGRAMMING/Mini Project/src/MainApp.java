// Main App Class
// Mini Project: Event Registration System (GUI with JOptionPane)
// Language: Java

import java.util.*;
import javax.swing.*;

public class MainApp {
    static ArrayList<Student> students = new ArrayList<>();
    static ArrayList<Admin> admins = new ArrayList<>();
    static ArrayList<Event> events = new ArrayList<>();

    public static void main(String[] args) {
        // Sample data
        students.add(new Student("S001", "Muhammad Ali", "ali@ktdi.utm.my", "student1", "A23CS001", "Faculty of Computing"));
        students.add(new Student("S002", "Lau Yee Wen", "yeewen@ktdi.utm.my", "student2", "A23CS0099", "School of Mechanical Engineering"));
        students.add(new Student("S003", "David Tan", "david.t@ktdi.utm.my", "student3", "A23HM003", "Faculty of Computing"));
        
        admins.add(new Admin("A001", "Puan Zuraini", "aminah.staff@ktdi.utm.my", "admin123"));

        events.add(new Event("EVT01", "Kelab Badminton KTDI", "Every Wednesday", 30, "Sesi latihan mingguan Kelab Badminton KTDI."));
        events.add(new Event("EVT02", "Persatuan Debat (Bahasa Melayu)", "Every Friday", 20, "Latihan dan perbincangan untuk pertandingan debat."));
        events.add(new Event("EVT03", "Workshop: Public Speaking 101", "2024-10-15", 50, "Improve your confidence and public speaking skills."));
        events.add(new Event("EVT04", "Kelas Asas Fotografi", "2024-10-20", 1, "Belajar teknik asas fotografi menggunakan DSLR."));
        events.add(new Event("EVT05", "Program Sukarelawan Komuniti", "2024-11-05", 100, "Khidmat masyarakat di rumah anak-anak yatim."));

        while (true) {
            String[] menuOptions = {"Login", "Exit"};
            int menuChoice = JOptionPane.showOptionDialog(null, "Welcome to the Event Registration System!",
                    "Main Menu", JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, 
                    null, menuOptions, menuOptions[0]);

            if (menuChoice == 1 || menuChoice == JOptionPane.CLOSED_OPTION) break;

            String id = JOptionPane.showInputDialog("Enter user ID:");
            if (id == null) continue;
            
            String pass = JOptionPane.showInputDialog("Enter password:");
            if (pass == null) continue;

            User user = login(id, pass);
            if (user == null) {
                JOptionPane.showMessageDialog(null, "Invalid credentials.", "Login Failed", JOptionPane.ERROR_MESSAGE);
                continue;
            }

            JOptionPane.showMessageDialog(null, "Welcome " + user.name, "Login Success", JOptionPane.INFORMATION_MESSAGE);
            
            if (user instanceof Student) {
                studentMenu((Student) user);
            } else {
                adminMenu((Admin) user);
            }
        }
    }

    private static User login(String id, String pass) {
        for (Student stu : students) {
            if (stu.login(id, pass)) return stu;
        }
        for (Admin admin : admins) {
            if (admin.login(id, pass)) return admin;
        }
        return null;
    }

    private static void studentMenu(Student student) {
        while (true) {
            String[] options = {"Register Event", "View Registered Events", "Cancel Event", "View Profile", "Logout"};
            int choice = JOptionPane.showOptionDialog(null, "Choose an option:", "Student Menu", 
                    JOptionPane.DEFAULT_OPTION, JOptionPane.QUESTION_MESSAGE, null, options, options[0]);

            switch (choice) {
                case 0: registerEvent(student); break;
                case 1: student.viewRegisteredEvents(); break;
                case 2: cancelEvent(student); break;
                case 3: student.viewProfile(); break;
                case 4: student.logout(); return;
                default: return;
            }
        }
    }

    private static void registerEvent(Student student) {
        if (events.isEmpty()) {
            JOptionPane.showMessageDialog(null, "No events available.", "No Events", JOptionPane.INFORMATION_MESSAGE);
            return;
        }

        StringBuilder eventList = new StringBuilder("Available Events:\n");
        for (int i = 0; i < events.size(); i++) {
            Event event = events.get(i);
            eventList.append(i + 1).append(". ").append(event.name)
                    .append(" (ID: ").append(event.eventID).append(")")
                    .append(" - ").append(event.date)
                    .append(" - ").append(event.participants.size()).append("/").append(event.quota)
                    .append(" participants\n");
        }

        String eventChoice = JOptionPane.showInputDialog(eventList.toString() + "\nEnter event number:");
        if (eventChoice == null) return;

        try {
            int eIdx = Integer.parseInt(eventChoice) - 1;
            if (eIdx >= 0 && eIdx < events.size()) {
                try {
                    student.registerEvent(events.get(eIdx));
                } catch (EventFullException e) {
                    JOptionPane.showMessageDialog(null, e.getMessage(), "Registration Failed", JOptionPane.WARNING_MESSAGE);
                }
            } else {
                JOptionPane.showMessageDialog(null, "Invalid event number.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Please enter a valid number.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private static void cancelEvent(Student student) {
        String cancelID = JOptionPane.showInputDialog("Enter Event ID to cancel:");
        if (cancelID != null) {
            student.cancelRegistration(cancelID);
        }
    }

    private static void adminMenu(Admin admin) {
        while (true) {
            String[] options = {"Create Event", "View Participants", "View All Events", "View Profile", "Logout"};
            int choice = JOptionPane.showOptionDialog(null, "Choose an option:", "Admin Menu", 
                    JOptionPane.DEFAULT_OPTION, JOptionPane.QUESTION_MESSAGE, null, options, options[0]);

            switch (choice) {
                case 0: createEvent(admin); break;
                case 1: viewParticipants(admin); break;
                case 2: admin.viewAllEvents(); break;
                case 3: admin.viewProfile(); break;
                case 4: admin.logout(); return;
                default: return;
            }
        }
    }

    private static void createEvent(Admin admin) {
        String eid = JOptionPane.showInputDialog("Enter Event ID:");
        if (eid == null) return;

        String ename = JOptionPane.showInputDialog("Enter Event Name:");
        if (ename == null) return;

        String edate = JOptionPane.showInputDialog("Enter Event Date (YYYY-MM-DD):");
        if (edate == null) return;

        String quotaStr = JOptionPane.showInputDialog("Enter Quota:");
        if (quotaStr == null) return;

        try {
            int quota = Integer.parseInt(quotaStr);
            String desc = JOptionPane.showInputDialog("Enter Description:");
            if (desc == null) return;

            admin.createEvent(new Event(eid, ename, edate, quota, desc));
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Please enter a valid number for quota.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private static void viewParticipants(Admin admin) {
        String vid = JOptionPane.showInputDialog("Enter Event ID:");
        if (vid != null) {
            admin.viewParticipants(vid);
        }
    }
}
