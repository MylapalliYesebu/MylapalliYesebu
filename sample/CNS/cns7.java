// BlowFish algorithm 
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;
import java.util.Scanner;

// public class BlowFishCipher {
public class cns7 {
    public static void main(String[] args) throws Exception {
        // Generate key
        KeyGenerator keyGenerator = KeyGenerator.getInstance("Blowfish");
        keyGenerator.init(128);
        SecretKey secretKey = keyGenerator.generateKey();

        // Cipher instance
        Cipher cipher = Cipher.getInstance("Blowfish");

        // Take input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a message to encrypt: ");
        String inputText = scanner.nextLine();

        // Encrypt
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(inputText.getBytes());
        String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);

        // Decrypt
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);

        // Show output
        System.out.println("Encrypted text (Base64): " + encryptedText);
        System.out.println("Decrypted text: " + decryptedText);
        scanner.close();
    }
}

/*
Output
Input your message: Hello world
Encrypted text (Base64): RjE3+smVAkIqzFZpLg==
Decrypted text: Hello world
 */