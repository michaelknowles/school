import Employee.Employee;

/**
 * Michael Knowles
 * CISP401
 * Program Assignment 2b
 */

public class Assignment2b {
   
    private static void printHeader() {
        /*
         * Print the header for the report
         */
        String headerFormat = "%-17s%8s%8s%9s%8s%9s\n";
        System.out.printf(headerFormat,
            "Employee", "Pay", "Hours", "Gross", "Tax", "Net");
        System.out.printf(headerFormat,
            "Name", "Rate", "Worked", "Pay", "Amount", "Pay");
        System.out.printf(headerFormat,
            "========", "====", "======", "======", "====", "======", "====");
    }
    
    private static void printInfo(Employee employee) {
        /*
         * Print the info for an employee formatted for the report
         */
        System.out.printf("%-17s%8.2f%8.2f%9.2f%8.2f%9.2f\n",
                          employee.name,
                          employee.rate,
                          employee.hours,
                          employee.gross,
                          employee.tax,
                          employee.net);
    }

    public static void main(String[] args) {     
        /*
         * Declare and initialize all employees into an array
         */      
        Employee[] employees = new Employee[] {
            new Employee("Davidson, Carl", 8.75, 38.00),
            new Employee("Doe, John", 17.00, 46.50),
            new Employee("Marion, Louise", 13.00, 40.00),
            new Employee("Prentiss, Paula", 15.75, 50.50),
            new Employee("Whittle, Ed", 11.50, 25.50)
        };
        int employeeCount = employees.length;
        
        /*
         * Sum values from all employees
         */
        Employee totals = new Employee("Totals", 0, 0);
        for(int i = 0; i < employeeCount; i++) {
            totals.rate += employees[i].rate;
            totals.hours += employees[i].hours;
            totals.gross += employees[i].gross;
            totals.tax += employees[i].tax;
            totals.net += employees[i].net;
        }
        
        /*
         * Average values from all employees
         */
        Employee averages = new Employee("Averages", 
            totals.rate / employeeCount, 
            totals.hours / employeeCount,
            totals.gross / employeeCount,
            totals.tax / employeeCount,
            totals.net / employeeCount);
        
        /*
         * Begin output
         */
        printHeader();
        for(int i = 0; i < employeeCount; i++) {
            printInfo(employees[i]);
        }
        System.out.println();
        printInfo(totals);
        printInfo(averages);
    }
}