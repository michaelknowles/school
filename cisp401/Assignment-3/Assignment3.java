import Employee.Employee;

/**
 * Michael Knowles
 * CISP401
 * Program Assignment 3
 */

public class Assignment3 {
   
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
                          employee.getName(),
                          employee.getRate(),
                          employee.getHours(),
                          employee.getGross(),
                          employee.getTax(),
                          employee.getNet());
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
            totals.rate += employees[i].getRate();
            totals.hours += employees[i].getHours();
            totals.gross += employees[i].getGross();
            totals.tax += employees[i].getTax();
            totals.net += employees[i].getNet();
        }
        
        /*
         * Average values from all employees
         */
        Employee averages = new Employee("Averages", 
            totals.getRate() / employeeCount, 
            totals.getHours() / employeeCount,
            totals.getGross() / employeeCount,
            totals.getTax() / employeeCount,
            totals.getNet() / employeeCount);
        
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