import javax.swing.JOptionPane;

public class JOptionPaneExample {
    public static void main(String[] args) {
        // Get input as String
        String  weightStr= JOptionPane.showInputDialog("Enter your weight (kg):");
        String heightStr = JOptionPane.showInputDialog("Enter your height (m):");

        // Convert input to double
        double weight = Double.parseDouble(weightStr);
        double height = Double.parseDouble(heightStr);

        // Calculate BMI
        double bmi = weight / (height * height);

        // Determine BMI category
        String category;
        if (bmi < 18.5) {
            category = "Underweight";
        } else if (bmi < 25) {
            category = "Normal";
        } else if (bmi < 30) {
            category = "Overweight";
        } else {
            category = "Obese";
        }

        // Display result
        JOptionPane.showMessageDialog(null, "Your BMI is: " + String.format("%.2f", bmi) + "( " + category + ")");
    }
}