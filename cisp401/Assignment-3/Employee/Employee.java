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
     public String name;
     public double rate;
     public double hours;
     public double gross;
     public double tax;
     public double net;
     
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
 }