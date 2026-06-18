import java.util.ArrayList; 

public class GradeCalculator {

    public static void main(String[] args) {
        ArrayList <Student> studentList = new ArrayList<Student>(); 

        // Creating students with hardcoded data
        Student s1 =  new Student ("Ali", 85, 78, 90); 
        Student s2 =  new Student ("Beh", 60, 55, 65);
        Student s3 =  new Student ("Sara", 40, 50, 45); 

        // Calculate grades
        s1.calculateGrade(); 
        s2.calculateGrade();
        s3.calculateGrade(); 

        // Add to list
        studentList.add(s1);
        studentList.add(s2);
        studentList.add(s3);

        // Display output
        System.out.println("--- Student Grades ---");
        for (Student s : studentList) { 
            s.Display();
        } 

    }
}

class Student {
    String name;
    int testMark; 
    int quizMark;
    int finalExam;
    char grade;

    // Constructor
    public Student(String name, int testMark, int quizMark, int finalExam) {
        this.name = name;
        this.testMark = testMark;
        this.quizMark = quizMark;
        this.finalExam = finalExam;
    }

    // Grade calculation method
    public void calculateGrade() {
        int total = testMark + quizMark + finalExam; 
        double average = total / 3; 

        if (average >= 80) 
            grade = 'A'; 
        else if (average >= 60)
            grade = 'B';
        else if (average >= 50)
            grade = 'C';
        else
            grade = 'F'; 
    }

    public void Display() { 
        System.out.println("Student Name: " + name);
        System.out.println("Test: " + testMark + ", Quiz: " + quizMark + ", Final: " + finalExam);
        System.out.println("Grade: " + grade + "\n");
    }

    public int getQuizMark() { 
        return quizMark;
    }
}
