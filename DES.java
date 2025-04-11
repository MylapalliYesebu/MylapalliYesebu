// Write a Java program to implement the DES algorithm logic. 

import java.util.Base64;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESedeKeySpec;

public class DES {
    private static final String UNICODE_FORMAT = "UTF8";
    public static final String DESEDE_ENCRYPTION_SCHEME = "DESede";
    private Cipher cipher;
    private SecretKey key;
    private String myEncryptionKey;
    private String myEncryptionScheme;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public DES() throws Exception {
        myEncryptionKey = "ThisIsSecretEncryptionKey12"; // Must be 24 bytes for DESede
        myEncryptionScheme = DESEDE_ENCRYPTION_SCHEME;
        byte[] keyAsBytes = myEncryptionKey.getBytes(UNICODE_FORMAT);
        DESedeKeySpec myKeySpec = new DESedeKeySpec(keyAsBytes);
        SecretKeyFactory mySecretKeyFactory = SecretKeyFactory.getInstance(myEncryptionScheme);
        cipher = Cipher.getInstance(myEncryptionScheme);
        key = mySecretKeyFactory.generateSecret(myKeySpec);
    }

    public String encrypt(String unencryptedString) {
        String encryptedString = null;
        try {
            cipher.init(Cipher.ENCRYPT_MODE, key);
            byte[] plainText = unencryptedString.getBytes(UNICODE_FORMAT);
            byte[] encryptedText = cipher.doFinal(plainText);
            encryptedString = Base64.getEncoder().encodeToString(encryptedText);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return encryptedString;
    }

    public String decrypt(String encryptedString) {
        String decryptedText = null;
        try {
            cipher.init(Cipher.DECRYPT_MODE, key);
            byte[] encryptedText = Base64.getDecoder().decode(encryptedString);
            byte[] plainText = cipher.doFinal(encryptedText);
            decryptedText = bytes2String(plainText);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return decryptedText;
    }

    private static String bytes2String(byte[] bytes) {
        StringBuilder stringBuffer = new StringBuilder();
        for (byte aByte : bytes) {
            stringBuffer.append((char) aByte);
        }
        return stringBuffer.toString();
    }

    public static void main(String[] args) throws Exception {
        System.out.print("Enter the string: ");
        DES myEncryptor = new DES();
        String stringToEncrypt = br.readLine();

        String encrypted = myEncryptor.encrypt(stringToEncrypt);
        String decrypted = myEncryptor.decrypt(encrypted);

        System.out.println("\nString To Encrypt: " + stringToEncrypt);
        System.out.println("Encrypted Value   : " + encrypted);
        System.out.println("Decrypted Value   : " + decrypted);
    }
}


// // OUTPUT: 
// Enter the string: Welcome

// String To Encrypt: Welcome
// Encrypted Value   : BPQMwc0wKvg+cxdQe7gcXA==
// Decrypted Value   : Welcome
