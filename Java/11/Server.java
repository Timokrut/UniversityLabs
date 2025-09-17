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

        final int[] secret = {(int)(Math.random() * 100) + 1};
        System.out.println("Secret number: " + secret[0]);

        Thread receiver = new Thread(() -> {
            byte[] buffer = new byte[1024];
            try {
                while (true) {
                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                    socket.receive(packet);

                    clientAddr[0] = packet.getAddress();
                    clientPort[0] = packet.getPort();

                    String msg = new String(packet.getData(), 0, packet.getLength());

                    if (msg.startsWith("@name")) {
                        String[] parts = msg.split(" ", 2);
                        if (parts.length == 2) {
                            System.out.println("Client changed name to: " + parts[1]);
                        }
                    } else if (msg.equals("@quit")) {
                        System.out.println(serverName[0] + " ended session.");
                        clientAddr[0] = null;
                        clientPort[0] = -1;
                        secret[0] = (int)(Math.random() * 100) + 1;

                        // socket.close();
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

        // BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        // while (true) {
        //     String line = reader.readLine();
        //     if (line == null) continue;
        //
        //     if (line.startsWith("@name")) {
        //         String[] parts = line.split(" ", 2);
        //         if (parts.length == 2) {
        //             serverName[0] = parts[1];
        //             System.out.println("Your name is now: " + serverName[0]);
        //         }
        //         continue;
        //     }
        //
        //     if (clientAddr[0] == null || clientPort[0] == -1) {
        //         System.out.println("No connected clients, waiting...");
        //         continue;
        //     }
        //
        //     String messageToSend;
        //     if (line.equals("@quit")) {
        //         messageToSend = "@quit";
        //         System.out.println(serverName[0] + "left chat.");
        //         socket.close();
        //     } else {
        //         messageToSend = serverName[0] + ": " + line;
        //     }
        //
        //     byte[] buf = messageToSend.getBytes();
        //     DatagramPacket packet = new DatagramPacket(buf, buf.length, clientAddr[0], clientPort[0]);
        //     socket.send(packet);
        // }

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (!socket.isClosed()) {
            String line = reader.readLine();
            if (line == null) continue;

            if (line.equals("@quit")) {
                System.out.println("Closing server ...");
                socket.close();
                break;
            }
        }

    }
}

