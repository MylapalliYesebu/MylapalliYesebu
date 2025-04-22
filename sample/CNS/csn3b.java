// Substitution Cipher in Java

import java.io.*;
import java.util.*;

// public class SubstitutionCipher {
public class csn3b {
    static Scanner sc = new Scanner(System.in);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String a = "abcdefghijklmnopqrstuvwxyz";
        String b = "zyxwvutsrqponmlkjihgfedcba"; // Reversed alphabet
        System.out.print("Enter any string (lowercase only): ");
        String str = br.readLine();
        StringBuilder decrypt = new StringBuilder();
        char c;

        for (int i = 0; i < str.length(); i++) {
            c = str.charAt(i);
            int j = a.indexOf(c);

            // Check if character is a lowercase letter
            if (j != -1) {
                decrypt.append(b.charAt(j));
            } else {
                // Optional: just add the character as-is if not in alphabet
                decrypt.append(c);
            }
        }

        System.out.println("The encrypted data is: " + decrypt);
    }
}

/*
Output
Enter any string (lowercase only): aceho
The encrypted data is: zxvsl
*/