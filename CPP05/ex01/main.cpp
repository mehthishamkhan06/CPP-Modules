#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Testing Bureaucrat and Form Classes ===" << std::endl;

    // Test 1: Create a valid Form
    std::cout << "\n--- Test 1: Valid Form Creation ---" << std::endl;
    try {
        Form taxForm("TaxForm", 50, 100);
        std::cout << taxForm << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test 2: Form creation with too high sign grade
    std::cout << "\n--- Test 2: Form Grade Too High ---" << std::endl;
    try {
        Form invalidHigh("InvalidHigh", 0, 100);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test 3: Form creation with too low exec grade
    std::cout << "\n--- Test 3: Form Grade Too Low ---" << std::endl;
    try {
        Form invalidLow("InvalidLow", 50, 151);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test 4: Bureaucrat signs a form successfully
    std::cout << "\n--- Test 4: Successful Form Signing ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);
        Form report("Report", 50, 100);
        std::cout << report << std::endl;
        alice.signForm(report); // should succeed
        std::cout << report << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test 5: Bureaucrat fails to sign a form (grade too low)
    std::cout << "\n--- Test 5: Failed Form Signing ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 60);
        Form confidential("Confidential", 50, 100);
        std::cout << confidential << std::endl;
        bob.signForm(confidential); // should fail
        std::cout << confidential << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test 6: Form already signed
    std::cout << "\n--- Test 6: Form Already Signed ---" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 30);
        Form memo("Memo", 40, 100);
        charlie.signForm(memo); // first signing
        charlie.signForm(memo); // second signing attempt
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test 7: Boundary grades for signing
    std::cout << "\n--- Test 7: Signing at Boundary Grades ---" << std::endl;
    try {
        Bureaucrat top("Top", 1);
        Bureaucrat bottom("Bottom", 150);
        Form form1("Form1", 1, 150);
        Form form2("Form2", 150, 1);

        top.signForm(form1);    // should succeed
        bottom.signForm(form2); // should succeed
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== All Tests Completed ===" << std::endl;
    return 0;
}
