import java.net.*;
import java.io.*;

public class Client {
    public static void main(String[] args) throws Exception {
        if (args.length != 2) {
            System.out.println("Usage: java Client <server-ip> <server-port>");
            return;
        }

        InetAddress serverAddr = InetAddress.getByName(args[0]);
        int serverPort = Integer.parseInt(args[1]);

        DatagramSocket socket = new DatagramSocket();
        System.out.println("Client connected to " + serverAddr + ":" + serverPort);

        final String[] clientName = {"Client"};

        Thread receiver = new Thread(() -> {
            byte[] buffer = new byte[1024];
            try {
                while (true) {
                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                    socket.receive(packet);
                    String msg = new String(packet.getData(), 0, packet.getLength());

                    if (msg.equals("@quit")) {
                        System.out.println("Server ended chat.");
                        break;
                    }
                    System.out.println(msg);
                }
            } catch (IOException e) {
                System.out.println("Receiver stopped.");
            }
        });
        receiver.start();

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String line = reader.readLine();
            if (line == null) continue;

            if (line.startsWith("@name")) {
                String[] parts = line.split(" ", 2);
                if (parts.length == 2) {
                    clientName[0] = parts[1];
                    System.out.println("Your name is now: " + clientName[0]);
                }
                byte[] buf = line.getBytes();
                DatagramPacket packet = new DatagramPacket(buf, buf.length, serverAddr, serverPort);
                socket.send(packet);
                continue;
            }

            String messageToSend;
            if (line.equals("@quit")) {
                messageToSend = "@quit";
                System.out.println("You left chat.");
                byte[] buf = messageToSend.getBytes();
                DatagramPacket packet = new DatagramPacket(buf, buf.length, serverAddr, serverPort);
                socket.send(packet);
                break;
            } else {
                messageToSend = clientName[0] + ": " + line;
            }

            byte[] buf = messageToSend.getBytes();
            DatagramPacket packet = new DatagramPacket(buf, buf.length, serverAddr, serverPort);
            socket.send(packet);
        }

        socket.close();
    }
}

