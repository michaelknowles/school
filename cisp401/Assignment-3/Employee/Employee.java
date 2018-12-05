package Employee;

/**
 * Michael Knowles
 * CISP401
 * Program Assignment 1
 */

public class Employee {
     /* 
      * Variables
      */
     protected String name;
     protected String type;
     protected double rate;
     protected double hours;
     protected double gross;
     protected double tax;
     protected double net;
     
     /* 
      * Constructor given only name, rate, and hours
      */
     public Employee(String name, double rate, double hours) {
         this.name = name;
         this.rate = rate;
         this.hours = hours;
         this.gross = calcGross();
         this.tax = calcTax();
         this.net = calcNet();
     }
     
     /* 
      * Constructor given all values
      */
     public Employee(String name, double rate, double hours, double gross,
                     double tax, double net) {
         this.name = name;
         this.rate = rate;
         this.hours = hours;
         this.gross = gross;
         this.tax = tax;
         this.net = net;
     }

     /* 
      * Calculate gross from rate and hours
      */
     private double calcGross() {
         // gross = rate * hours
         // up to 40 hours
         // overtime pay (past 40 hours)
         // rate = 1.5 * rate
         if(hours <= 40) {
             return rate * hours;
         } else {
             double overtimehours = hours - 40;
             return (rate * 40) + (rate * 1.5 * overtimehours);
         }
     }
 
     /* 
      * Calculate tax from gross
      */
     private double calcTax() {
         // tax = 15% of gross
         double taxrate = 0.15;
         return gross * taxrate;
     }
 
     /* 
      * Calculate net from gross and tax
      */
     private double calcNet() {
         // net = gross - tax
         return gross - tax;
     }

     /*
      * Getters
      */
    public String getName() {
        return name;
    }
    public double getRate() {
        return rate;
    }
    public double getHours() {
        return hours;
    }
    public double getGross() {
        return gross;
    }
    public double getTax() {
        return tax;
    }
    public double getNet() {
        return net;
    }

    /*
     * Setters
     */
    public void setName(String name) {
        this.name = name;
    }
    public void setRate(double rate) {
        this.rate = rate;
    }
    public void setHours(double hours) {
        this.hours = hours;
    }
    public void setGross(double gross) {
        this.gross = gross;
    }
    public void setTax(double tax) {
        this.tax = tax;
    }
    public void setNet(double net) {
        this.net = net;
    }
}

class EmployeeSalaried extends Employee {
    type = "Salaried";
    
    private double calcGross() {
        return hours * rate;
    }
}