# Event Registration System - OOP Demo Presentation Guide

## 1. Program Demo (3-4 minutes)

### Live Demo Steps:
1. **Compile and Run**: `javac -cp . src/*.java` then `java -cp . src.MainApp`
2. **Login as Student**: Use credentials `S001` / `student1` (Muhammad Ali)
3. **Register for Event**: Choose "Kelab Badminton KTDI" (EVT01)
4. **Try Duplicate Registration**: Attempt to register for the same event again
5. **View Registered Events**: Show the list of registered events
6. **Cancel Registration**: Cancel the event registration
7. **Login as Admin**: Use credentials `A001` / `admin123` (Puan Zuraini)
8. **Create New Event**: Demonstrate event creation
9. **View Participants**: Show participant list for an event

---

## 2. OOP Elements Analysis (5-6 minutes)

### A. ABSTRACT CLASSES

**Example**: `User` class
```java
public abstract class User {
    String userID, name, email, password;
    
    abstract boolean login(String userID, String password);
    
    void logout() { /* implementation */ }
    void viewProfile() { /* implementation */ }
}
```

**Why Used**: 
- Provides a common template for all user types (Student, Admin)
- Defines shared attributes and behaviors
- Forces subclasses to implement specific methods (login)
- Prevents instantiation of generic User objects

**Benefits**:
- Code reuse through inheritance
- Polymorphic behavior
- Enforces structure across user types

### B. INTERFACES

**Example**: `Registerable` interface
```java
public interface Registerable {
    boolean registerEvent(Event event) throws EventFullException;
    void viewRegisteredEvents();
}
```

**Why Used**:
- Defines a contract for event registration capabilities
- Allows different classes to implement registration differently
- Enables loose coupling between components
- Supports multiple inheritance (Student extends User AND implements Registerable)

**Benefits**:
- Standardization of registration behavior
- Flexibility to add registration to any class
- Clear contract definition

### C. INHERITANCE

**Examples**:
1. **Student extends User**:
```java
public class Student extends User implements Registerable {
    String matricNo, faculty;
    ArrayList<Registration> registrations = new ArrayList<>();
}
```

2. **Admin extends User**:
```java
public class Admin extends User {
    // Admin-specific methods
}
```

**Why Used**:
- Code reuse: Students and Admins inherit common User properties
- Hierarchical organization: User → Student/Admin
- Polymorphic behavior: Can treat Student/Admin as User objects

**Benefits**:
- Reduces code duplication
- Maintains consistency across user types
- Enables polymorphic collections

### D. ENCAPSULATION

**Examples**:
1. **Private Data with Public Methods**:
```java
// In Event class
private ArrayList<Student> participants = new ArrayList<>();

public void addParticipant(Student student) throws EventFullException {
    if (isFull()) {
        throw new EventFullException("Event is full");
    }
    participants.add(student);
}
```

2. **Controlled Access**:
```java
// In Student class
private ArrayList<Registration> registrations = new ArrayList<>();

public boolean registerEvent(Event event) {
    // Validation logic before adding
    for (Registration reg : registrations) {
        if (reg.event.eventID.equals(event.eventID)) {
            return false; // Already registered
        }
    }
    // Safe to add
}
```

**Why Used**:
- Hides internal implementation details
- Provides controlled access to data
- Ensures data integrity through validation
- Prevents direct manipulation of internal state

**Benefits**:
- Data protection
- Implementation flexibility
- Easier maintenance

### E. POLYMORPHISM

**Examples**:
1. **Method Overriding**:
```java
// In User (abstract)
abstract boolean login(String userID, String password);

// In Student
@Override
boolean login(String userID, String password) {
    return this.userID.equals(userID) && this.password.equals(password);
}

// In Admin
@Override
boolean login(String userID, String password) {
    return this.userID.equals(userID) && this.password.equals(password);
}
```

2. **Interface Implementation**:
```java
// Student implements Registerable
@Override
public boolean registerEvent(Event event) throws EventFullException {
    // Student-specific registration logic
}

@Override
public void viewRegisteredEvents() {
    // Student-specific viewing logic
}
```

3. **Polymorphic Collections**:
```java
// In MainApp
static ArrayList<Student> students = new ArrayList<>();
static ArrayList<Admin> admins = new ArrayList<>();

// Can treat both as User objects
User user = login(id, pass);
if (user instanceof Student) {
    studentMenu((Student) user);
} else {
    adminMenu((Admin) user);
}
```

**Why Used**:
- Same interface, different implementations
- Flexible method calls based on object type
- Extensible design for future user types

**Benefits**:
- Code flexibility
- Extensibility
- Reduced coupling

---

## 3. Additional OOP Concepts Demonstrated

### F. EXCEPTION HANDLING
```java
public class EventFullException extends Exception {
    public EventFullException(String message) {
        super(message);
    }
}
```

### G. ASSOCIATION RELATIONSHIPS
- **Student has Registration**: One-to-many relationship
- **Event has Participants**: One-to-many relationship
- **Registration connects Student and Event**: Many-to-many relationship

### H. COMPOSITION
```java
// Student contains Registration objects
ArrayList<Registration> registrations = new ArrayList<>();

// Event contains Student objects
ArrayList<Student> participants = new ArrayList<>();
```

---

## 4. Key Features to Highlight

1. **Duplicate Registration Prevention**: Demonstrates encapsulation and validation
2. **Exception Handling**: Shows proper error management
3. **GUI Integration**: JOptionPane for user interaction
4. **Data Persistence**: In-memory data structures
5. **Role-Based Access**: Different menus for different user types

---

## 5. QA Session Preparation

### Common Questions & Answers:

**Q: Why use abstract class instead of interface for User?**
A: User provides shared implementation (logout, viewProfile) and common state (userID, name, etc.). Abstract class allows both abstract methods and concrete implementations.

**Q: How does the system prevent duplicate registrations?**
A: Through encapsulation - the Student class validates existing registrations before adding new ones, hiding this logic from external classes.

**Q: What happens if you try to register for a full event?**
A: The Event class throws a custom EventFullException, demonstrating proper exception handling and encapsulation.

**Q: How is polymorphism used in the login system?**
A: The login method is overridden in both Student and Admin classes, allowing the same method call to work differently for different user types.

---

## 6. Demo Script

### Opening (30 seconds):
"Welcome to our Event Registration System. This project demonstrates comprehensive OOP principles including abstract classes, interfaces, inheritance, encapsulation, and polymorphism."

### Live Demo (3-4 minutes):
"Let me show you the system in action..."

### OOP Analysis (5-6 minutes):
"Now let's examine the OOP elements used in this project..."

### Closing (30 seconds):
"This system demonstrates how OOP principles create maintainable, extensible, and well-structured code. Thank you for your attention." 
