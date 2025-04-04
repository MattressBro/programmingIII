
import java.util.*;
import java.io.*;   
public class discussion {
    // This is a simple Java program that prints "Hello, World!" to the console.
    public static void main(String[] args) {
        int data;
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter a number: ");
            data = scanner.nextInt();
            System.out.println("Number: " + data);
        } catch (InputMismatchException e) {
            System.out.println("Invalid input. Please enter a valid number.");
        } 
        scanner.close();
    }
}
