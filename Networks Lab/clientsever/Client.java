import java.net.*;
import java.io.*;

public class Client {

    public static void main(String[] args) {
        if (args.length < 2) return;

        String hostname = args[0];
        int port = Integer.parseInt(args[1]);

        try (Socket socket = new Socket(hostname, port)) {

            InputStream input = socket.getInputStream();
            OutputStream os=socket.getOutputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
          System.out.println( reader.readLine());
          
         PrintWriter write=new PrintWriter(os,true);
         write.println("i am a client");

        } catch (UnknownHostException ex) {

            System.out.println("Server not found: " + ex.getMessage());

        } catch (IOException ex) {

            System.out.println("I/O error: " + ex.getMessage());
        }
    }
}

