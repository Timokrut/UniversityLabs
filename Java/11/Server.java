import java.net.*;
import java.io.*;

public class Server {
    public static void main(String[] args) throws Exception {
        if (args.length != 1) {
            System.out.println("Usage: java Server <port>");
            return;
        }

        int port = Integer.parseInt(args[0]);
        DatagramSocket socket = new DatagramSocket(port);
        System.out.println("Sever started on port: " + port);

        final String[] serverName = {"Server"}; 
        final InetAddress[] clientAddr = {null};
        final int[] clientPort = {-1};
        final boolean[] restartGame = {false};

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int secret[] = {askSecret(reader)};
        // final int[] secret = {(int)(Math.random() * 100) + 1};

        Thread receiver = new Thread(() -> {
            byte[] buffer = new byte[1024];
            try {
                while (true) {
                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                    socket.receive(packet);

                    clientAddr[0] = packet.getAddress();
                    clientPort[0] = packet.getPort();

                    String msg = new String(packet.getData(), 0, packet.getLength());

                    if (msg.equals("@quit")) {
                        System.out.println(serverName[0] + " ended session.");
                        clientAddr[0] = null;
                        clientPort[0] = -1;
                        restartGame[0] = true;                        
                        // secret[0] = (int)(Math.random() * 100) + 1;

                    } else {
                        System.out.println(msg);
                        
                        try {
                            int guess = Integer.parseInt(msg);
                            String response;

                            if (guess == secret[0]) {
                                response = "You guessed: " + secret[0];
                            } else if (guess < secret[0]) {
                                response = "Bigger";
                            } else { 
                                response = "Lower";
                            }
                            byte[] buf = response.getBytes();
                            DatagramPacket answer = new DatagramPacket(buf, buf.length, clientAddr[0], clientPort[0]);
                            socket.send(answer);

                        } catch (NumberFormatException e) {
                            // not a number, just message
                        }

                    }
                }
            } catch (IOException e) {
                System.out.println("Reciever stopped");
            }
        });
        receiver.start();


        while (!socket.isClosed()) {
            if (restartGame[0]) {
                secret[0] = askSecret(reader);
                restartGame[0] = false;
            }

            String line = reader.readLine();
            if (line == null) continue;

            if (line.equals("@quit")) {
                System.out.println("Closing server ...");
                socket.close();
                break;
            }
        }

        

        }
    public static int askSecret(BufferedReader reader) throws IOException {
        int secret;
        while (true) {
            System.out.println("Set secret number (1 - 100): ");
            try {
                secret = Integer.parseInt(reader.readLine());
                if (secret >= 1 && secret <= 100) break;
                System.out.println("Number should be in range from 1 to 100. Try again ...");
            } catch (NumberFormatException e) {
                System.out.println("Error with parsing integer. Try again ...");
            }
        }
        System.out.println("Secret number: " + secret);
        return secret;
    }
}

