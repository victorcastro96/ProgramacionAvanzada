/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejemplo;

/**
 *
 * @author Sala1
 */
public class Ejemplo {
    final static double TaxRate=0.28;
    //static double GrossPay=100.0;
    //static double ExtraPay=50.55;
    double GrossPay=100.0;
    double ExtraPay=50.55;
    
    public static void main(String[] args) {
    
        //double NetTotalPay=GrossPay+ExtraPay;
        Ejemplo H=new Ejemplo();
        double NetTotalPay=H.GrossPay+H.ExtraPay;
        double NetPay=NetTotalPay-(NetTotalPay*TaxRate);
        System.out.println("pago final $"+NetPay);
    }
    
}
