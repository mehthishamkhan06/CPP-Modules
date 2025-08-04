#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Testing Bureaucrat Class ===" << std::endl;
    
    // Test 1: Default constructor
    std::cout << "\n--- Test 1: Default Constructor ---" << std::endl;
    try {
        Bureaucrat defaultBureaucrat;
        std::cout << defaultBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 2: Valid grade constructor
    std::cout << "\n--- Test 2: Valid Grade Constructor ---" << std::endl;
    try {
        Bureaucrat john("John", 75);
        std::cout << john << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 3: Grade too high (< 1)
    std::cout << "\n--- Test 3: Grade Too High Exception ---" << std::endl;
    try {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 4: Grade too low (> 150)
    std::cout << "\n--- Test 4: Grade Too Low Exception ---" << std::endl;
    try {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 5: Boundary values (1 and 150)
    std::cout << "\n--- Test 5: Boundary Values ---" << std::endl;
    try {
        Bureaucrat highest("Highest", 1);
        Bureaucrat lowest("Lowest", 150);
        std::cout << highest << std::endl;
        std::cout << lowest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 6: Copy constructor
    std::cout << "\n--- Test 6: Copy Constructor ---" << std::endl;
    try {
        Bureaucrat original("Original", 50);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 7: Assignment operator
    std::cout << "\n--- Test 7: Assignment Operator ---" << std::endl;
    try {
        Bureaucrat source("Source", 25);
        Bureaucrat target("Target", 100);
        std::cout << "Before assignment:" << std::endl;
        std::cout << "Source: " << source << std::endl;
        std::cout << "Target: " << target << std::endl;
        
        target = source;
        std::cout << "After assignment:" << std::endl;
        std::cout << "Source: " << source << std::endl;
        std::cout << "Target: " << target << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 8: Grade increment (promotion - grade decreases)
    std::cout << "\n--- Test 8: Grade Increment (Promotion) ---" << std::endl;
    try {
        Bureaucrat worker("Worker", 50);
        std::cout << "Before increment: " << worker << std::endl;
        worker.gradeIncrement();
        std::cout << "After increment: " << worker << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 9: Grade decrement (demotion - grade increases)
    std::cout << "\n--- Test 9: Grade Decrement (Demotion) ---" << std::endl;
    try {
        Bureaucrat manager("Manager", 50);
        std::cout << "Before decrement: " << manager << std::endl;
        manager.gradeDecrement();
        std::cout << "After decrement: " << manager << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 10: Increment at highest grade (should throw exception)
    std::cout << "\n--- Test 10: Increment at Highest Grade ---" << std::endl;
    try {
        Bureaucrat topBureaucrat("TopBureaucrat", 1);
        std::cout << "Before increment: " << topBureaucrat << std::endl;
        topBureaucrat.gradeIncrement(); // Should throw exception
        std::cout << "After increment: " << topBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 11: Decrement at lowest grade (should throw exception)
    std::cout << "\n--- Test 11: Decrement at Lowest Grade ---" << std::endl;
    try {
        Bureaucrat bottomBureaucrat("BottomBureaucrat", 150);
        std::cout << "Before decrement: " << bottomBureaucrat << std::endl;
        bottomBureaucrat.gradeDecrement(); // Should throw exception
        std::cout << "After decrement: " << bottomBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 12: Multiple increments and decrements
    std::cout << "\n--- Test 12: Multiple Grade Changes ---" << std::endl;
    try {
        Bureaucrat versatile("Versatile", 75);
        std::cout << "Initial: " << versatile << std::endl;
        
        for (int i = 0; i < 5; i++) {
            versatile.gradeIncrement();
            std::cout << "After increment " << (i + 1) << ": " << versatile << std::endl;
        }
        
        for (int i = 0; i < 10; i++) {
            versatile.gradeDecrement();
            std::cout << "After decrement " << (i + 1) << ": " << versatile << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== All Tests Completed ===" << std::endl;
    return 0;
}